import sys
from PySide2.QtWidgets import QApplication
from ui.mainwindow import MainWindow

if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainwindow = MainWindow()
    sys.exit(app.exec_())