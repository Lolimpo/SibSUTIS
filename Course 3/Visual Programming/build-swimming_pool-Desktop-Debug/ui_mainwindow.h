/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_4;
    QWidget *centralwidget;
    QTableView *tableView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *abNum;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *name;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *phNumber;
    QComboBox *abType;
    QSpinBox *remVis;
    QLineEdit *lineEdit;
    QLabel *label_6;
    QLabel *label_7;
    QFrame *line_2;
    QLineEdit *lineEdit_2;
    QFrame *line_3;
    QPushButton *pushButton_3;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1129, 525);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        MainWindow->setFont(font);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(260, 60, 851, 401));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 260, 231, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background-color:rgb(101, 151, 0)"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 360, 231, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("background:rgb(140, 0, 0)"));
        abNum = new QLineEdit(centralwidget);
        abNum->setObjectName(QString::fromUtf8("abNum"));
        abNum->setGeometry(QRect(10, 30, 241, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 151, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 67, 17));
        name = new QLineEdit(centralwidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(10, 80, 241, 25));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 110, 131, 17));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 160, 131, 17));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 210, 181, 17));
        phNumber = new QLineEdit(centralwidget);
        phNumber->setObjectName(QString::fromUtf8("phNumber"));
        phNumber->setGeometry(QRect(10, 130, 241, 25));
        abType = new QComboBox(centralwidget);
        abType->setObjectName(QString::fromUtf8("abType"));
        abType->setGeometry(QRect(10, 180, 241, 25));
        abType->setEditable(false);
        remVis = new QSpinBox(centralwidget);
        remVis->setObjectName(QString::fromUtf8("remVis"));
        remVis->setGeometry(QRect(10, 230, 63, 28));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 330, 231, 25));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 310, 141, 17));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(270, 10, 67, 17));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(260, 0, 3, 61));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(270, 30, 651, 25));
        lineEdit_2->setToolTipDuration(-1);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(0, 390, 261, 31));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(930, 30, 181, 25));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("background:rgb(101, 151, 0)"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1129, 28));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu->addSeparator();
        menu->addAction(action_4);

        retranslateUi(MainWindow);
        QObject::connect(action_4, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Visitors Database", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
#if QT_CONFIG(tooltip)
        action->setToolTip(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        action->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
#if QT_CONFIG(shortcut)
        action_2->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        action_4->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
#if QT_CONFIG(shortcut)
        action_4->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_2->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
#if QT_CONFIG(tooltip)
        abNum->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\266\320\265\320\273\320\260\320\265\320\274\321\213\320\271 \320\275\320\276\320\274\320\265\321\200 \320\260\320\261\320\276\320\275\320\265\320\274\320\265\320\275\321\202\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\260\320\261\320\276\320\275\320\265\320\274\320\265\320\275\321\202\320\260:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217:", nullptr));
#if QT_CONFIG(tooltip)
        name->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\244\320\230\320\236 \320\272\320\273\320\270\320\265\320\275\321\202\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\260\320\261\320\276\320\275\320\265\320\274\320\265\320\275\321\202\320\260:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\320\273\320\276\321\201\321\214 \320\277\320\276\321\201\320\265\321\211\320\265\320\275\320\270\320\271:", nullptr));
#if QT_CONFIG(tooltip)
        phNumber->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260 \320\272\320\273\320\270\320\265\320\275\321\202\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        abType->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\265\321\202\320\265 \321\202\320\270\320\277 \320\260\320\261\320\276\320\275\320\265\320\274\320\265\320\275\321\202\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        remVis->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\207\320\270\321\201\320\273\320\276 \320\267\320\260\320\275\321\217\321\202\320\270\320\271, \320\276\320\277\320\273\320\260\321\207\320\265\320\275\320\276\320\265 \320\272\320\273\320\270\320\265\320\275\321\202\320\276\320\274", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        lineEdit->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \320\260\320\261\320\276\320\275\320\265\320\274\320\265\320\275\321\202\320\260 \320\264\320\273\321\217 \321\203\320\264\320\260\320\273\320\265\320\275\320\270\321\217", nullptr));
#endif // QT_CONFIG(tooltip)
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\260\320\261\320\276\320\275\320\265\320\274\320\265\320\275\321\202\320\260:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_2->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \320\260\320\261\320\276\320\275\320\265\320\274\320\265\320\275\321\202\320\260 \320\264\320\273\321\217 \320\277\320\276\320\270\321\201\320\272\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        pushButton_3->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \320\277\320\276\321\201\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
