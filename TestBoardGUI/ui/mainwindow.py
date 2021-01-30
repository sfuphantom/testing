import sys
import os
import json
from datetime import date

from PySide2.QtWidgets import (QApplication, QPushButton, QLineEdit, QTabWidget,
                               QTreeWidget, QComboBox, QTreeWidget, QTableWidget,
                               QWidget, QTreeWidgetItem, QHeaderView)
from PySide2.QtCore import (QFile, QObject, QDir, Signal, Slot)
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
        self.boardName = self.mainwindow.findChild(QLineEdit, 'boardNameLineEdit')
        self.boardVersion = self.mainwindow.findChild(QLineEdit, 'boardVersionLineEdit')
        self.testID = self.mainwindow.findChild(QLineEdit, 'testIDLineEdit')
        self.teamMember = self.mainwindow.findChild(QLineEdit, 'teamMemberLineEdit')
        
        # TabWidget
        self.tabwidget = self.mainwindow.findChild(QTabWidget, 'deviceTabWidget')
        # Disable VCU tab
        self.tabwidget.setTabEnabled(0, False)
        # Disable BMS tab
        self.tabwidget.setTabEnabled(1, False)
        # Empty tab just to fix appearance
        self.tabwidget.setTabVisible(2, False)

        # TreeWidget
        self.VCUTree = self.mainwindow.findChild(QTreeWidget, 'VCUTreeWidget')
        self.BMSTree = self.mainwindow.findChild(QTreeWidget, 'BMSTreeWidget')

        # TableWidget
        self.resultsTable = self.mainwindow.findChild(QTableWidget, 'resultsTable')
        
        # PushButtons
        self.calibrationTestButton = self.mainwindow.findChild(
                                        QPushButton, 'calibrationTestButton')
        self.calibrationTestButton.clicked.connect(self.calibration)
        self.runPushButton = self.mainwindow.findChild(QPushButton, 'runPushButton')
        self.runPushButton.clicked.connect(self.run)
        self.cancelPushButton = self.mainwindow.findChild(QPushButton, 'cancelPushButton')
        self.cancelPushButton.clicked.connect(self.cancel)
        self.savePushButton = self.mainwindow.findChild(QPushButton, 'savePushButton')
        self.savePushButton.clicked.connect(self.save)

        # Show ui when application runs
        self.mainwindow.show()

    # Populate test cases in test selection tree
    def _fill_test_cases(self, device: str):
        # Select tree to populate base on selected device
        if device == 'VCU':
            tree = self.VCUTree
        elif device == 'BMS':
            tree = self.BMSTree

        # Load testcases JSON
        path = os.path.join(os.path.dirname(__file__), 'testcases.json')
        with open(path) as f:
            test_cases = json.load(f)

        # Populate QTreeWidget
        for thing in test_cases[device]:
            for key, value in thing.items():
                root = QTreeWidgetItem(tree, [key])
                for val in value:
                    item = QTreeWidgetItem(root, list(val.values()))
        
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
        print('run button is clicked')

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


if __name__=='__main__':
    app = QApplication(sys.argv)
    mainwindow = MainWindow()
    sys.exit(app.exec_())
