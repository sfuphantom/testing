import sys
import os
import json
from datetime import date

from PySide2.QtWidgets import (QApplication, QPushButton, QLineEdit,
                               QTabWidget, QTreeWidget, QComboBox, QTreeWidget,
                               QWidget, QTreeWidgetItem, QHeaderView)
from PySide2.QtCore import (QFile, QObject, QDir, Signal, Slot, Qt)
from PySide2.QtUiTools import (QUiLoader)


# Set-up/Connect mainwindow
class MainWindow(QObject):

    def __init__(self, parent=None):
        super(MainWindow, self).__init__(parent)

        # Check-In Information
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
    
    # This function is buggy. WIP
    @Slot()
    def _duplicate_selections(self):
        items = self.selectedTree.selectedItems()    
        self.resultsTree.clear()
        for item in items:
            index = items.index(item)

            parent = QTreeWidgetItem([item.parent().text(0)])
            self.resultsTree.addTopLevelItem(parent)
            child = QTreeWidgetItem([item.text(0)])
            parent.addChild(child)

    # Retrieve selected test cases
    def _get_selected_tests(self):
        # Retrieve all selected tests in -> list(QTreeWidgetItems)
        self._rawSelection = self.selectedTree.selectedItems()

        test_item = {'Test Name': '', 'Test Case': '', 'Repeat': None, 'Test Index': None}

        self.selectedTests = list()

        for item in self._rawSelection:
            test_item = self._parse_tests(item)
            self.selectedTests.append(test_item)
        
    
    # Parse user test selection
    def _parse_tests(self, item):
        test_item = {}
        # QModelIndex of selected test to be used for adding results to the table
        index = self.selectedTree.indexFromItem(item)
        test_item['Test Name'] = item.parent().text(0)
        test_item['Test Case'] = item.text(0)
        test_item['Test Index'] = index
        return test_item

    # Write results
    def _write_results(self, test_index, status):
        pass

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


if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainwindow = MainWindow()
    sys.exit(app.exec_())
