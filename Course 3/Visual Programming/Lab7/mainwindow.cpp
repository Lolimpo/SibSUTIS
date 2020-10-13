#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1280,720);
    this->setFixedSize(1280,720);

    scene = new QGraphicsScene();
    triangle = new Triangle();
    triangle2 = new Triangle();
    triangle3 = new Triangle();
    log1 = new log();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(-250,-250,500,500);

    scene->addItem(log1);
    log1->setFlag(QGraphicsItem::ItemIsMovable, true);
    log1->setPos(0,150);

    scene->addItem(triangle);
    triangle->setFlag(QGraphicsItem::ItemIsMovable, true);
    triangle->setPos(-150,0);

    scene->addItem(triangle2);
    triangle2->setFlag(QGraphicsItem::ItemIsMovable, true);
    triangle2->setPos(0,0);

    scene->addItem(triangle3);
    triangle3->setFlag(QGraphicsItem::ItemIsMovable, true);
    triangle3->setPos(150,0);

    auto circle1 = new QGraphicsEllipseItem(0, 0, 50, 50);
    circle1->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    circle1->setBrush(Qt::red);
    auto circle2 = new QGraphicsEllipseItem(0, 0, 50, 50);
    circle2->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    circle2->setBrush(Qt::yellow);
    auto circle3 = new QGraphicsEllipseItem(0, 0, 50, 50);
    circle3->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    circle3->setBrush(Qt::blue);


    scene->addItem(circle1);
    circle1->setFlag(QGraphicsItem::ItemIsMovable, true);
    circle1->setPos(-150, -150);
    scene->addItem(circle2);
    circle2->setFlag(QGraphicsItem::ItemIsMovable, true);
    circle2->setPos(50, 150);
    scene->addItem(circle3);
    circle3->setFlag(QGraphicsItem::ItemIsMovable, true);
    circle3->setPos(150, -150);

    movable = scene->addPixmap(QPixmap("/home/lolimpo/Рабочий стол/Projects/Visual Programming/Lab7/snow.png"));
    movable->setPos(100,0);

    timer = new QTimer();
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
    timer->start(50);
    xx = 3;
    yy = 2;
    mov = 10;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotAlarmTimer()
{
    if(movable->x() > 430)
        xx *= -1;
    if(movable->x() < -640)
        xx *= -1;
    if(movable->y() > 100)
        yy *= -1;
    if(movable->y() < -360)
        yy *= -1;
    if(movable->collidesWithItem(triangle) || movable->collidesWithItem(triangle2) || movable->collidesWithItem(triangle3) || movable->collidesWithItem(log1))
    {
        xx *= -1;
        yy *= -1;
    }
    movable->setPos(movable->x() + xx, movable->y() + yy);
    timer->start(10);


    /*srand(time_t(nullptr));
    scene->removeItem(movable);
    scene->addItem(movable);
    if(xx + mov > 430 || xx + mov < -640 || yy + mov > 360 || yy + mov < -360)
    {
        mov = mov * -1;
    }
    if(movable->collidesWithItem(triangle) || movable->collidesWithItem(triangle2) || movable->collidesWithItem(triangle3) || movable->collidesWithItem(log1))
    {
        scene->removeItem(movable);
        scene->addItem(movable);
        if(mov < 0)
        {
            xx = xx + rand()%20;
            yy += rand()%20;
        }
        if(mov > 0)
        {
            xx = xx - rand()%20;
            yy -= rand()%20;
        }
        movable->setPos(xx,yy);
        mov = mov * -1;
    }

    if(mov < 0)
    {
        xx = xx + rand()%20;
        yy += rand()%20;
    }
    if(mov > 0)
    {
        xx = xx - rand()%20;
        yy -= rand()%20;
    }
    movable->setPos(xx,yy);
    mov = mov * -1;*/;
}
