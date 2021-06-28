import sys
import os
import json
from datetime import date
import pytest
import tests.vcu_test as vcu_test
import tests.bms_test as bms_test
import serial.tools.list_ports

from PySide2.QtWidgets import (QApplication, QPushButton, QLineEdit,
                               QTabWidget, QTreeWidget, QComboBox,
                               QStackedWidget, QCommandLinkButton,
                               QStatusBar, QTreeWidgetItem, QAbstractItemView, QFileDialog)
from PySide2.QtCore import (QFile, QObject, Signal, Slot, Qt)
from PySide2.QtUiTools import (QUiLoader)
from PySide2.QtGui import (QBrush, QColor)


# Set-up/Connect mainwindow
class MainWindow(QObject):
    # Create a signal for sending selected tests to back-end
    tests_signal = Signal(list)

    def __init__(self, parent=None):
        super(MainWindow, self).__init__(parent)

        # Pre-define instances
        self.mainwindow = self._load_ui("mainwindow.ui")
        self.device = None
        # Initialize Check-In information dictionary to be filled
        self.checkin_info = {'device': '', 'board_name': '',
                             'board_version': '', 'testID': '',
                             'team_member': '', 'date': str(date.today())}


        # Instantiate required objects
        # ResultsWriter displays results on the gui
        self.resultsWriter = ResultsWriter()

        # Connect Python to ui features

        # QTreeWidget
        self.VCUTree = self.mainwindow.findChild(QTreeWidget, 'VCUTreeWidget')
        self.BMSTree = self.mainwindow.findChild(QTreeWidget, 'BMSTreeWidget')
        self.resultsTree = self.mainwindow.findChild(
            QTreeWidget, 'resultsTreeWidget')
        # Pass resultsTree to resultsWriter
        self.resultsWriter.get_results_tree(self.resultsTree)

        # ComboBox
        self.deviceComboBox = self.mainwindow.findChild(
            QComboBox, 'deviceSelection')
        self.deviceComboBox.currentTextChanged.connect(
            lambda: self._device_selected(self.deviceComboBox.currentIndex()))
        # self.deviceCombobox.currentTextChanged.connect(
        #     lambda: self._device_selected(self.deviceCombobox.currentIndex()))
        self.portNumComboBox = self.mainwindow.findChild(
            QComboBox, 'portNumber')

        self.portNumComboBox.setPlaceholderText('Select')
        self.portNumComboBox.addItems(self._port_num())

        self.portNumComboBox.currentTextChanged.connect( #creates a signal
            lambda: self.get_port_num(self.portNumComboBox.currentText()))

        # LineEdits
        self.boardName = self.mainwindow.findChild(
            QLineEdit, 'boardNameLineEdit')
        self.boardVersion = self.mainwindow.findChild(
            QLineEdit, 'boardVersionLineEdit')
        self.testID = self.mainwindow.findChild(QLineEdit, 'testIDLineEdit')
        self.teamMember = self.mainwindow.findChild(
            QLineEdit, 'teamMemberLineEdit')

        # TabWidget
        self.tabWidget = self.mainwindow.findChild(
            QTabWidget, 'deviceTabWidget')
        # Disable VCU tab
        self.tabWidget.setTabEnabled(0, False)
        # Disable BMS tab
        self.tabWidget.setTabEnabled(1, False)
        # Empty tab just to fix appearance
        self.tabWidget.setTabVisible(2, False)

        # Status Bar
        self.status = self.mainwindow.findChild(QStatusBar, 'statusbar')

        # StackedWidget
        self.stackedWidget = self.mainwindow.findChild(
            QStackedWidget, 'stackedWidget')
        self.stackedWidget.setCurrentIndex(0)

        # CommandLinkButtons
        self.VCUTreeResultsButton = self.mainwindow.findChild(
            QCommandLinkButton, 'viewResults')
        self.VCUTreeResultsButton.clicked.connect(self.view_results)
        self.backButton = self.mainwindow.findChild(
            QCommandLinkButton, 'back')
        self.backButton.clicked.connect(self.view_test_cases)

        # PushButtons
        self.calibrationTestButton = self.mainwindow.findChild(
            QPushButton, 'calibrationTestButton')
        self.calibrationTestButton.clicked.connect(self.calibration)
        self.runPushButton = self.mainwindow.findChild(
            QPushButton, 'runPushButton')
        self.runPushButton.clicked.connect(self.run)
        self.cancelPushButton = self.mainwindow.findChild(
            QPushButton, 'cancelPushButton')
        self.cancelPushButton.clicked.connect(self.cancel)
        self.savePushButton = self.mainwindow.findChild(
            QPushButton, 'savePushButton')
        self.savePushButton.clicked.connect(self.save)

        # Show ui when application runs
        self.mainwindow.show()

    def get_port_num(self, num):
        self.portnum = num

    # Load ui file
    def _load_ui(self, file):
        loader = QUiLoader()
        path = os.path.join(os.path.dirname(__file__), file)
        ui_file = QFile(path)
        ui_file.open(QFile.ReadOnly)
        mainwindow = loader.load(ui_file)
        ui_file.close()
        return mainwindow

    # Actions to take when a device is selected
    def _device_selected(self, index: int):
        # Disable both tabs
        self.tabWidget.setTabEnabled(0, False)
        self.tabWidget.setTabEnabled(1, False)

        # Switch to selected device tab
        self.tabWidget.setCurrentIndex(index)
        self.tabWidget.setTabEnabled(index, True)

        # Get selected device
        self.device = self.deviceComboBox.currentText()

        # Renew signal and slot connection
        try:
            self.tests_signal.disconnect()
        except RuntimeError:
            pass

        # Define selected tree based on selected device
        if self.device == 'VCU':
            # Previously selected tests
            self.BMSTree.clearSelection()
            # Define tree
            self.selectedTree = self.VCUTree
            # Connect tests_signal to vcu_test for sending selected tests later
            self.tests_signal.connect(vcu_test.get_tests)
        elif self.device == 'BMS':
            self.VCUTree.clearSelection()
            self.selectedTree = self.BMSTree
            self.tests_signal.connect(bms_test.get_tests)

        # Set tree behaviors
        self.selectedTree.setSelectionMode(QAbstractItemView.MultiSelection)
        # WIP: SelectedClicked doesn't work for some reason. IDK
        self.selectedTree.setEditTriggers(QAbstractItemView.SelectedClicked
                                          | QAbstractItemView.DoubleClicked)

        # Get test attributes from testcases.JSON
        self.test_attributes = self._get_json_attributes(self.device)

        # Populate test selection
        self._fill_test_cases(self.test_attributes)

    # Populate test cases in test selection tree
    def _fill_test_cases(self, test_attributes):
        for group in test_attributes:
            for test_name, test_cases in group.items():
                # Populate parents (test names)
                parent = QTreeWidgetItem([test_name])
                self.selectedTree.addTopLevelItems([parent])
                # Disable selection of parents
                parent.setFlags(parent.flags() & ~Qt.ItemIsSelectable)
                # Populate children (test cases)
                for case in test_cases:
                    # column_0 = case['Case']
                    # column_1 = case['Repeat']
                    # column_2 = case['Description']
                    # column_3 = case['enum']
                    # child = QTreeWidgetItem([column_0, column_1, column_2, column_3])
                    row = case.values()
                    child = QTreeWidgetItem(list(row))
                    parent.addChild(child)
                    # Make children editable
                    child.setFlags(child.flags() | Qt.ItemIsEditable
                                   | Qt.ItemIsEnabled | Qt.ItemIsSelectable)
                self.selectedTree.expandItem(parent)

    # Get test attributes from testcases.JSON for selected device
    def _get_json_attributes(self, device: str):
        # Load testcases.json
        path = os.path.join(os.path.dirname(__file__), 'testcases.json')
        with open(path) as f:
            test_cases = json.load(f)
        return test_cases[device]

    # Retrieve selected test cases
    def _get_selected_tests(self):
        rawSelections = self.selectedTree.selectedItems()
        selectedTests = list()
        for selection in rawSelections:
            selectedTests.append(self._parse_tests(selection))
        return selectedTests

    # Parse user test selection
    def _parse_tests(self, item):
        test_item = dict()
        test_item['Test Name'] = item.parent().text(0)
        test_item['Test Case'] = item.text(0)
        test_item['Repeat'] = item.text(1)
        # Edit the following lines to match enum attributes
        test_item['enum'] = item.text(3)
        return test_item

    # Retrieve check-in information
    def _get_checkin_info(self):
        self.checkin_info['device'] = self.deviceComboBox.currentText()
        self.checkin_info['board_name'] = self.boardName.text()
        self.checkin_info['board_version'] = self.boardVersion.text()
        self.checkin_info['testID'] = self.testID.text()
        self.checkin_info['team_member'] = self.teamMember.text()

        print(self.checkin_info)

    # Disable/Enable some features
    def _switch_mode(self, mode):
        # Diable run button
        self.runPushButton.setEnabled(mode)
        # Disable combobox
        self.deviceComboBox.setEnabled(mode)
        # Disable calibration test button
        self.calibrationTestButton.setEnabled(mode)
        # Disable all line edits\
        self.boardName.setEnabled(mode)
        self.testID.setEnabled(mode)
        self.boardVersion.setEnabled(mode)
        self.teamMember.setEnabled(mode)

    # Retrieve list of COM ports
    def _port_num (self):
        comlist = serial.tools.list_ports.comports()
        port_num = []
        for element in comlist:
            port_num.append(element.device)
        return port_num

    def open_directory(self):
        self.dirName = QFileDialog.getExistingDirectory()

    # Run tests
    @Slot()
    def run(self):
        # Clean results tree before showing showing results
        self.resultsTree.clear()
        self.status.showMessage('Tests in progress...')
        # Get selected tests
        self.selectedTests = self._get_selected_tests()
        print(self.selectedTests)
        # Disable some features while running tests
        self._switch_mode(False)
        # Send selected tests to bms_test or vcu_test
        self.tests_signal.emit(self.selectedTests)

        # Execute run code here
        # ##########################################

        #pytest.main()
        pytest.main(["-k " + self.device])

        # ##########################################

        # Temporary assigning selected test cases as results
        # To be replaced with actual results from back end
        # Sort results by their Test Name for heirachical structure
        results = sorted(self.selectedTests,key = lambda i: i['Test Name'])
        self.resultsWriter.writeResults(results)
        # Switch to result page
        self.stackedWidget.setCurrentIndex(1)

    # Cancel tests
    @Slot()
    def cancel(self):
        print('cancel button is clicked')
        '''
        Write something here to disrupt tests if needed

        '''

    # Run calibration test
    @Slot()
    def calibration(self):
        print('calibration test button is clicked')
        '''
        Excecute calibration test code here

        '''

    # Save test reults
    @Slot()
    def save(self):
        self._get_checkin_info()
        self.open_directory()
        print('save button is clicked')

    @Slot()
    def view_results(self):
        self.stackedWidget.setCurrentIndex(1)
        self.status.showMessage('Viewing test results')
        print('view results')

    @Slot()
    def view_test_cases(self):
        self.stackedWidget.setCurrentIndex(0)
        self.status.showMessage('Selecting test cases.')
        print('view test cases')
        self._switch_mode(True)


# This class display results on the gui.
class ResultsWriter(QObject):
    def __init__(self):
        super(ResultsWriter, self).__init__()

    # Retreive results tree from MainWindow in order to edit.
    def get_results_tree(self, tree):
        self.resultsTree = tree

    # Display status as PASS/FAIL in green/red
    def _fill_status(self, stat: bool, child):
        status = "PASS" if stat else "FAIL"
        colour = "#196F3D" if stat else "#FF0000"
        child.setText(1, status)
        child.setForeground(1, QBrush(QColor(colour)))
    
    def writeResults(self, data: list):
        # This list keeps track of the parents to avoid
        # having multiple parents with the same name
        parents = ['']
        for item in data:
            root = item['Test Name']
            print(parents[-1])
            # check if a top level has already been added
            if root != parents[-1]:
                parents.pop()
                parents.append(root)
                # Create new parent QTreewidgetItem
                parent = QTreeWidgetItem([root])
                self.resultsTree.addTopLevelItems([parent])
            parent.setFlags(parent.flags() & ~Qt.ItemIsSelectable)
            self.resultsTree.expandItem(parent)
            column_0 = item['Test Case']

            # Edit the following part to propoerly display status
            # ##########################################

            child = QTreeWidgetItem([column_0, '',''])
            # column_2 = item['Message']
            # child = QTreeWidgetItem([column_0, '', column_2])
            parent.addChild(child)
            # self._fill_status(item['Status'], child)

            # ##########################################
            
            child.setFlags(child.flags() & ~Qt.ItemIsSelectable)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainwindow = MainWindow()
    sys.exit(app.exec_())