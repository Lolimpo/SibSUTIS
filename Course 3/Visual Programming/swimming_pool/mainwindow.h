#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
#include <QTableWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QTimer>
#include <QSpinBox>
#include <QSplashScreen>
#include <string>
#include <algorithm>

#include "helpdesk.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    QTableView *tableView;
    QSqlTableModel *model;
    QSqlQuery *query;
    QTableWidget *tableWidget;
    QComboBox *abType;
    QTimer* timer;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_2_textChanged();

    void on_pushButton_3_clicked();

    void Action()
    {
        QMessageBox msg;
        msg.setWindowTitle("О программе");
        msg.setText("Учёт посетителей бассейна\nВыполнили студенты группы ИП-713:\nМихеев Никита,\nУстенко Дмитрий.\n2019 год.");
        msg.exec();
    }
    //void putstr();

private:
    HelpDesk *help;
    QDockWidget* helpWindow;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
