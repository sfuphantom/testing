import sys
import os
from datetime import date


from PySide2.QtWidgets import (QApplication, QMainWindow, QWidget, QPushButton,
                               QTabWidget, QTreeWidget, QLineEdit, QComboBox,
                               QTreeWidgetItem, QTextEdit, QHeaderView)
from PySide2.QtCore import QFile, QObject, QDir, Signal, Slot
from PySide2.QtUiTools import QUiLoader


class MainWindow(QObject):
    def __init__(self, parent=None):
        super(MainWindow, self).__init__(parent)

        self.checkin_info = {'date': '', 'board_name': '', 'team_member': '',
                             'device_type': '', 'testID': '',
                             'board_version': ''}

        self.result_temp = {'category': '', 'test_name': '', 'outcome': ''}

        # Load ui file
        loader = QUiLoader()
        path = os.path.join(os.path.dirname(__file__), "mainwindow.ui")
        ui_file = QFile(path)
        ui_file.open(QFile.ReadOnly | QFile.ExistingOnly)
        self.ui_widget = loader.load(ui_file)
        ui_file.close()

        # Connecting python to ui features
        self.mainscreen = self.ui_widget.findChild(QWidget, "centralwidget")

        # LineEdits
        self.date = self.ui_widget.findChild(QLineEdit, "Date")
        self.date.setText(str(date.today()))
        self.date.setReadOnly(True)
        self.board_name = self.ui_widget.findChild(QLineEdit, "BoardName")
        self.team_member = self.ui_widget.findChild(QLineEdit, "TeamMember")
        self.testID = self.ui_widget.findChild(QLineEdit, "TestID")
        self.board_version = self.ui_widget.findChild(QLineEdit, "version")

        # ComboBox
        self.device = self.ui_widget.findChild(QComboBox, "Device")
        self.device.currentTextChanged.connect(self._device_selected)

        # PushButtons
        self.calibrationPushButton = self.ui_widget.findChild(
                                        QPushButton, "CalibrationTest")
        self.calibrationPushButton.clicked.connect(self.calibration_test)

        self.savePushButton = self.ui_widget.findChild(QPushButton, "Save")
        self.savePushButton.clicked.connect(self.save)

        self.cancelPushButton = self.ui_widget.findChild(QPushButton, "Cancel")
        self.cancelPushButton.clicked.connect(self.cancel)

        self.runPushButton = self.ui_widget.findChild(QPushButton, "Run")
        self.runPushButton.clicked.connect(self.run)

        # TabWidgets
        self.tabwidget = self.ui_widget.findChild(QTabWidget, "TestSelection")
        # Disable VCU Tab
        self.tabwidget.setTabEnabled(0, False)
        # Disable BMS Tab
        self.tabwidget.setTabEnabled(1, False)

        # TreeWidget
        self.vcu_tree = self.ui_widget.findChild(QTreeWidget, "VCUTree")
        self.bms_tree = self.ui_widget.findChild(QTreeWidget, "BMSTree")

        # TextEdit
        self.resultsTextEdit = self.ui_widget.findChild(
                                QTextEdit, 'ResultsTextEdit')
        self.resultsTextEdit.setReadOnly(True)

        # Must have this for ui to appear
        self.ui_widget.show()

    # WIP
    def _get_selected_tests(self):
        self.selected_tests = self.selected_tree.selectedItems()  # Returns a list of QTreeWidgetItems:
        print(self.selected_tests)
        # for test_case in self.selected_tests:
        #     print(test_case.text(0))
        #     if test_case.parent():
        #         print(test_case.parent().text(0))

    def _write_textedit(self, text):
        self.resultsTextEdit.append(text)

    def _get_checkin_info(self):
        self.checkin_info['date'] = self.date.text()
        self.checkin_info['board_name'] = self.board_name.text()
        self.checkin_info['team_member'] = self.team_member.text()
        self.checkin_info['testID'] = self.board_name.text()
        self.checkin_info['board_version'] = self.board_name.text()
        self.checkin_info['device_type'] = self.device.currentText()

    @Slot()
    def _device_selected(self):
        # Disable both tabs
        self.tabwidget.setTabEnabled(0, False)
        self.tabwidget.setTabEnabled(1, False)
        # Identify selected device
        device = self.device.currentText()
        # Enable tab corresponding to selected device
        if device == "VCU":
            self.tabwidget.setCurrentIndex(0)
            self.tabwidget.setTabEnabled(0, True)
            self.selected_tree = self.vcu_tree
        elif device == "BMS":
            self.tabwidget.setCurrentIndex(1)
            self.tabwidget.setTabEnabled(1, True)
            self.selected_tree = self.bms_tree

    @Slot()
    def run(self):
        # Run selected tests and print results on screen
        # Retrieve selected tests
        self._get_selected_tests()
        self._write_textedit('Running tests')

    @Slot()
    def cancel(self):
        self._write_textedit('Cancel')
        # Stop running tests

    @Slot()
    def calibration_test(self):
        # Run calibration test
        self._write_textedit('Starting calibration test...')

    @Slot()
    def save(self):
        self._write_textedit('Saving results')
        self._get_checkin_info()
        print(self.checkin_info)
        self._write_textedit('Test Summary:\n')
        for key in self.checkin_info.keys():
            self._write_textedit(key + ':    ' + self.checkin_info[key])
        # Get test results
        # Open folder
        # Write excel file


if __name__ == "__main__":
    app = QApplication(sys.argv)
    mainwindow = MainWindow()
    sys.exit(app.exec_())
