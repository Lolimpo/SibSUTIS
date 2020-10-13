#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPixmap>
#include <QWidget>
#include <QPixmapCache>
#include <QTimer>

#include "triangle.h"
#include "log.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Triangle *triangle;
    Triangle *triangle2;
    Triangle *triangle3;
    log *log1;
    QGraphicsPixmapItem *movable;
    QTimer *timer;
    int xx, yy, mov;
private slots:
    void slotAlarmTimer();
};
#endif // MAINWINDOW_H
