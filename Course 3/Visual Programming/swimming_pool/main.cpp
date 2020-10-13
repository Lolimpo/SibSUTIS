#include "mainwindow.h"

#include <QApplication>
#include <QtGui>

void loadModules(QSplashScreen* psplash)
{
    QTime time;
    time.start();
    for(int i = 0; i < 100;)
    {
        if(time.elapsed() > 20)
        {
            time.start();
            i += 2;
        }
        psplash->showMessage("Загрузка программы..." + QString::number(i)+"%", Qt::AlignCenter | Qt::AlignCenter, Qt::black);
        qApp->processEvents();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen splash(QPixmap("/home/lolimpo/Projects/Visual Programming/swimming_pool/load.png"));
    splash.show();
    MainWindow w;
    loadModules(&splash);
    splash.finish(&w);
    w.show();
    return a.exec();
}
