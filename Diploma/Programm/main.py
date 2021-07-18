import os
import sys

import cv2
from PyQt5 import QtWidgets
from PyQt5.QtGui import QPixmap
import design
import processing


# Основной класс главного окна
class MainApp(QtWidgets.QMainWindow, design.Ui_MainWindow):

    # Инициализирующая функция
    def __init__(self):
        # Ключевая точка для старта
        super().__init__()
        # Установка дизайна
        self.setupUi(self)
        # Установка начальной вкладки после запуска приложения
        self.tabWidget.setCurrentIndex(0)
        # Установка фукнции обработки изображения на сигнал нажатия кнопки
        self.pushButton.clicked.connect(self.process_image)
        # Установка фукнции обработки видео на сигнал нажатия кнопки
        self.pushButton_2.clicked.connect(self.process_video)
        # Установка функции обработки видео с камеры на сигнал переключения соотвествующей вкладки
        self.tabWidget.currentChanged.connect(self.selector)
        # Установка начальных значений информационных полей в программе
        self.label.setText('')
        self.label_2.setText('')

    def selector(self):
        if self.tab_3 is self.tabWidget.currentWidget():
            self.tabWidget.setCurrentIndex(2)
            self.process_camera()

    def process_image(self):
        self.label.setText('Выполняю...')
        image_path = QtWidgets.QFileDialog.getOpenFileName(self, 'Выберите изображение', '.', '*.png *.jpg *.bmp')

        if image_path[0] != '':
            image_path = image_path[0]
        else:
            self.label.setText('Вы не выбрали изображение. \nПопробуйте еще раз.')
            return

        flag, t = processing.process_image(image_path)

        if flag:
            pixmap_image = QPixmap('result.png')
            self.label.setPixmap(pixmap_image)
            self.label.resize(pixmap_image.width(), pixmap_image.height())
            self.window().resize(pixmap_image.width(), pixmap_image.height())
            msg = QtWidgets.QMessageBox()
            msg.setIcon(QtWidgets.QMessageBox.Information)
            msg.setText(f'Обработка изображения заняла {t:.5f} с')
            msg.setWindowTitle('Дополнительная информация')
            msg.exec_()

    def process_video(self):
        self.window().resize(window.baseSize())
        self.label_2.setText('Выполняю...')
        video_path = QtWidgets.QFileDialog.getOpenFileName(self, 'Выберите видео', '.', '*.mp4')

        if video_path != '':
            video_path = video_path[0]
        else:
            self.label_2.setText('Вы не выбрали видео.\nПопробуйте еще раз.')
            return

        flag, f, t = processing.process_video(video_path)

        if flag:
            msg = QtWidgets.QMessageBox()
            msg.setIcon(QtWidgets.QMessageBox.Information)
            msg.setText(f'Всего обработано кадров: {f}\nЗаняло {t:.5f} секунд\nFPS: {round((f / t), 1)}')
            msg.setWindowTitle('Дополнительная информация')
            msg.exec_()

            self.label_2.setText('Видео обработано! \nМожете выбрать еще одно.')
            os.startfile('result.mp4')

    def process_camera(self):
        self.window().resize(window.baseSize())
        self.label_3.setText('Посмотрите в окошко с камерой.')
        f, t = processing.process_camera()
        self.window().resize(window.baseSize())
        msg = QtWidgets.QMessageBox()
        msg.setIcon(QtWidgets.QMessageBox.Information)
        msg.setText(f'Всего обработано кадров: {f}\nЗаняло {t:.5f} секунд\nFPS: {round((f / t), 1)}')
        msg.setWindowTitle('Дополнительная информация')
        msg.exec_()
        self.label_3.setText('')


if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)
    window = MainApp()
    window.show()
    sys.exit(app.exec())
