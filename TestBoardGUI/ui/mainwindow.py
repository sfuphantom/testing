import sys
import os
import json
from datetime import date

from PySide2.QtWidgets import (QApplication, QPushButton, QLineEdit,
                               QTabWidget, QTreeWidget, QComboBox, QTreeWidget,
                               QWidget, QTreeWidgetItem, QHeaderView)
from PySide2.QtCore import (QFile, QObject, QDir, Signal, Slot, Qt,
                            QAbstractProxyModel)
from PySide2.QtUiTools import (QUiLoader)
from PySide2.QtGui import (QBrush, QColor)


# Set-up/Connect mainwindow
class MainWindow(QObject):
    # When run button is clicked, it sends a signal with
    # the selected tests to be used by tests handler
    runsignal = Signal(list)

    def __init__(self, parent=None):
        super(MainWindow, self).__init__(parent)

        # Instantiate required objects
        # ResultWriter displays results on the gui
        self.resultsWriter = ResultsWriter()
        # Dummy test results generator. To be replaced by real tests handler.
        self.testdummy = TestDummy()
        # Connect signal emitted by run button to test handler.
        self.runsignal.connect(self.testdummy.poppulate_results)
        # Connect results signal from "dummy" test handler to ResultWriter
        self.testdummy.results.connect(self.resultsWriter.test_function)

        # Initialize Check-In Information dictionary to be filled
        self.checkin_info = {'device': '', 'board_name': '',
                             'board_version': '', 'testID': '',
                             'team_member': '', 'date': str(date.today())}

        # Load ui file
        loader = QUiLoader()
        path = os.path.join(os.path.dirname(__file__), 'mainwindow.ui')
        ui_file = QFile(path)
        ui_file.open(QFile.ReadOnly)
        self.mainwindow = loader.load(ui_file)
        ui_file.close()

        # Connect Python to ui features

        # ComboBox
        self.device = self.mainwindow.findChild(QComboBox, 'deviceSelection')
        self.device.currentTextChanged.connect(lambda: self._device_selected(
                                               self.device.currentIndex()))

        # LineEdits
        self.boardName = self.mainwindow.findChild(
            QLineEdit, 'boardNameLineEdit')
        self.boardVersion = self.mainwindow.findChild(
            QLineEdit, 'boardVersionLineEdit')
        self.testID = self.mainwindow.findChild(QLineEdit, 'testIDLineEdit')
        self.teamMember = self.mainwindow.findChild(
            QLineEdit, 'teamMemberLineEdit')

        # TabWidget
        self.tabwidget = self.mainwindow.findChild(
            QTabWidget, 'deviceTabWidget')
        # Disable VCU tab
        self.tabwidget.setTabEnabled(0, False)
        # Disable BMS tab
        self.tabwidget.setTabEnabled(1, False)
        # Empty tab just to fix appearance
        self.tabwidget.setTabVisible(2, False)

        # TreeWidget
        self.VCUTree = self.mainwindow.findChild(QTreeWidget, 'VCUTreeWidget')
        self.BMSTree = self.mainwindow.findChild(QTreeWidget, 'BMSTreeWidget')
        self.resultsTree = self.mainwindow.findChild(
            QTreeWidget, 'resultsTreeWidget')
        self.VCUTree.itemClicked.connect(self._duplicate_selections)
        self.BMSTree.itemClicked.connect(self._duplicate_selections)
        # Pass resultsTree to resultsWriter
        self.resultsWriter.results_tree(self.resultsTree)

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

    # Populate test cases in test selection tree
    def _fill_test_cases(self, device: str):
        # Select tree to populate base on selected device
        if device == 'VCU':
            self.selectedTree = self.VCUTree
        elif device == 'BMS':
            self.selectedTree = self.BMSTree

        # Load testcases JSON
        path = os.path.join(os.path.dirname(__file__), 'testcases.json')
        with open(path) as f:
            test_cases = json.load(f)

        # Populate QTreeWidget
        for thing in test_cases[device]:
            for key, value in thing.items():
                # Populate parents (test names)
                parent = QTreeWidgetItem([key])
                self.selectedTree.addTopLevelItems([parent])
                # Add check box to parent
                # parent.setCheckState(0, Qt.Unchecked)
                # Disable selection of parents
                parent.setFlags(parent.flags() & ~Qt.ItemIsSelectable)
                # Populate children (test cases)
                for val in value:
                    children = QTreeWidgetItem(list(val.values()))
                    parent.addChildren([children])
                    # Add check box to each test case
                    # children.setCheckState(0, Qt.Unchecked)

    # WIP: This function is buggy. 
    @Slot()
    def _duplicate_selections(self):
        items = self.selectedTree.selectedItems()
        self.resultsTree.clear()
        for item in items:
            # why did i create this index smh not even using it
            # index = items.index(item)
            parent = QTreeWidgetItem([item.parent().text(0)])
            self.resultsTree.addTopLevelItem(parent)
            child = QTreeWidgetItem([item.text(0)])
            parent.addChild(child)

    # Retrieve selected test cases
    def _get_selected_tests(self):
        # Retrieve all selected tests in -> list(QTreeWidgetItems)
        self._rawSelection = self.selectedTree.selectedItems()

        test_item = {'Test Name': '', 'Test Case': '', 'Repeat': None}

        self.selectedTests = list()

        for item in self._rawSelection:
            test_item = self._parse_tests(item)
            self.selectedTests.append(test_item)

    # Parse user test selection
    def _parse_tests(self, item):
        test_item = {}
        test_item['Test Name'] = item.parent().text(0)
        test_item['Test Case'] = item.text(0)
        # WIP: repeat column doesn't exist in test selection yet
        # test_item['Repeat'] = item.text(1)
        test_item['Repeat'] = None

        # QModelIndex of selected test to be used for adding results to the table
        # index = self.selectedTree.indexFromItem(item)
        # This index is from test selection tree. Cannot be used with results tree.
        # test_item['Test Index'] = index
        return test_item

    # Retrieve checkin information
    def _get_checkin_info(self):
        self.checkin_info['device'] = self.device.currentText()
        self.checkin_info['board_name'] = self.boardName.text()
        self.checkin_info['board_version'] = self.boardVersion.text()
        self.checkin_info['testID'] = self.testID.text()
        self.checkin_info['team_member'] = self.teamMember.text()

        print(self.checkin_info)

    # Enable test selection tab according to selected device
    def _device_selected(self, index: int):
        # Disable both tabs
        self.tabwidget.setTabEnabled(0, False)
        self.tabwidget.setTabEnabled(1, False)

        # Switch to selected device tab
        self.tabwidget.setCurrentIndex(index)
        self.tabwidget.setTabEnabled(index, True)

        # Populate test selection
        self._fill_test_cases(self.device.currentText())

    # Run tests
    @Slot()
    def run(self):
        self._get_selected_tests()
        print(self.selectedTests)
        print('run button is clicked')
        # for i in self.selectedTests:
        #     print(i)
        # Emit selectedTests to runsignal
        self.runsignal.emit(self.selectedTests)

    # Cancel tests
    @Slot()
    def cancel(self):
        print('cancel button is clicked')

    # Run calibration test
    @Slot()
    def calibration(self):
        print('calibration test button is clicked')

    # Save test reults
    @Slot()
    def save(self):
        self._get_checkin_info()
        print('save button is clicked')

    # Dont mind me. Just being tested.
    def test_function(self):
        print('Hi there! I am test_function. I belong in MainWindow. :)')


# This class display results on the gui.
class ResultsWriter(QObject):
    def __init__(self):
        super(ResultsWriter, self).__init__()

    # Retreive results tree from MainWindow in order to edit.
    def results_tree(self, tree):
        self.results_tree = tree

    # Display status as PASS/FAIL in green/red
    def _fill_status(self, index, status: bool):
        status = "PASS" if status else "FAIL"
        colour = "#49E20E" if status else "#FF0000"
        # Edit status column in results tree
        self.results_tree.itemFromIndex(index).setText(2, status)
        # Change colour of text
        self.results_tree.itemFromIndex(index).setForeground(
            2, QBrush(QColor(colour)))

    # Display message in results tree
    def _fill_message(self, tree, index, message: str):
        self.results_tree.itemFromIndex(index).setText(3, message)

    # Write status and message for each test item
    @Slot(list)
    def writeresults(self, results: list):
        for test in results:
            index = test['Test Index']
            status = test['Test Status']
            message = test['Test Message']
            self._fill_status(index, status)
            self._fill_message(index, message)

    # Dont mind me. Just being tested.
    @Slot(list)
    def test_function(self, results):
        print('hi there. I belong in results writer.')
        for i in results:
            print(i)


# Dont mind me. Just a dummy test handler.
# Used for generating fake results for testing ResultsWriter
class TestDummy(QObject):
    results = Signal(list)

    def __init__(self):
        super(TestDummy, self).__init__()

    # Just fake test results.
    @Slot(list)
    def poppulate_results(self, tests):
        # self.results.emit('testdummy')
        num = 0
        dummy_status = True
        dummy_message = "Message"
        for test in tests:
            test['Status'] = dummy_status
            test['Message'] = dummy_message + str(num)
            test['Repeat'] = num
            num += 1
            dummy_status = not dummy_status
        self.results.emit(tests)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainwindow = MainWindow()
    results = ResultsWriter()
    sys.exit(app.exec_())
