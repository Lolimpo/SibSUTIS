import sys

from PyQt6.QtWidgets import QApplication, QWidget, QMainWindow, QLabel, QVBoxLayout
from PyQt6.QtGui import QPixmap


class Menu(QMainWindow):

    def __init__(self):
        super().__init__()
        self.setWindowTitle("Lab4")

        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)
        lay = QVBoxLayout(self.central_widget)

        label = QLabel(self)
        pixmap = QPixmap('true_color.bmp')
        label.setPixmap(pixmap)
        self.resize(pixmap.width(), pixmap.height())

        lay.addWidget(label)
        self.show()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = Menu()
    sys.exit(app.exec())
