#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    help = new HelpDesk();
    connect(ui->action, SIGNAL(triggered()), SLOT(Action()));
    connect(ui->action_2, SIGNAL(triggered()), help, SLOT(show()));

/*    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(putstr()));
    timer->start(250);*/

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/lolimpo/Projects/Visual Programming/swimming_pool/sp.db");
    if(db.open())
    {
        qDebug() << "Success";
    }
    query = new QSqlQuery;
    /*query.exec("CREATE TABLE pool ("
                                 "ab	TEXT,"
                                 "name	TEXT,"
                                 "phNum	    INTEGER,"
                                 "abType	INTEGER,"
                                 "visRem	INTEGER"
               ");");*/ //создание БД (уже создана)
    tableWidget = new QTableWidget;
    tableView = new QTableView;
    model = new QSqlTableModel;
    model->setTable("pool");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("Номер абонемента"));
    model->setHeaderData(1, Qt::Horizontal, tr("ФИО"));
    model->setHeaderData(2, Qt::Horizontal, tr("Телефон"));
    model->setHeaderData(3, Qt::Horizontal, tr("Тип абонемента"));
    model->setHeaderData(4, Qt::Horizontal, tr("Осталось посещений"));
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,150);
    ui->tableView->setColumnWidth(1,220);
    ui->tableView->setColumnWidth(2,150);
    ui->tableView->setColumnWidth(3,150);
    ui->tableView->setColumnWidth(4,170);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    abType = new QComboBox;
    QStringList list;
    list << "Дневной" << "Вечерний" << "Полнодневный";
    ui->abType->addItems(list);
    ui->tableView->sortByColumn(0, Qt::AscendingOrder);
    ui->tableView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString tempABNUM = ui->abNum->text();
    QString tempNAME = ui->name->text();
    QString tempPHNUMBER = ui->phNumber->text();
    QString tempABTYPE = ui->abType->currentText();
    int tempREMVIS = ui->remVis->value();
    qDebug() << tempABNUM;
    qDebug() << tempNAME;
    qDebug() << tempPHNUMBER ;
    qDebug() << tempABTYPE;
    qDebug() << tempREMVIS;
    int rip = 0;
    for(int i = 0; i < tempABNUM.count(); i++)
    {
        if(' ' == tempABNUM.at(i))
            rip = 1;
    }
    if(!query->exec("SELECT * FROM pool WHERE ab = '" + tempABNUM + "';") || rip == 1)
    {
        qDebug() << "Can't execute SQLite query or name with spaces";
    }
    else if(query->first())
    {
        qDebug() << "Duplicate was found";
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Ошибка!");
        msgBox.setMinimumSize(250, 0);
        msgBox.setText("Найден дубликат.\n");
        msgBox.exec();

    }
    else if(!(tempABNUM.isEmpty() or tempNAME.isEmpty() or tempPHNUMBER.isEmpty() or
            tempABTYPE.isEmpty() or tempREMVIS == 0))
    {
        ui->abNum->clear();ui->name->clear();ui->phNumber->clear();ui->remVis->setValue(0);
        //qDebug() << "Done!";
        query->prepare("INSERT INTO pool (ab, name, phNum, abType, visRem) "
                      "VALUES (:ab, :name, :phNum, :abType, :visRem)");
        query->bindValue(":ab", tempABNUM);
        query->bindValue(":name", tempNAME);
        query->bindValue(":phNum", tempPHNUMBER);
        query->bindValue(":abType", tempABTYPE);
        query->bindValue(":visRem", tempREMVIS);
        query->exec();
        query->prepare("SELECT * FROM pool ORDER BY ab");
        query->exec();
        model->select();
        ui->tableView->sortByColumn(0, Qt::AscendingOrder);
    }
    else
    {
        QMessageBox msg;
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowTitle("Ошибка!");
        msg.setText("Проверьте правильность заполнения полей.\n");
        msg.exec();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(!ui->lineEdit->text().isEmpty())
    {
        QString string = ui->lineEdit->text(); ui->lineEdit->clear();
        query->prepare("DELETE FROM pool WHERE ab = " + string + ";");
        query->exec();
    }
    else if(!(ui->tableView->model()->data(ui->tableView->currentIndex()).isNull()))
    {
        QString string = ui->tableView->model()->data(ui->tableView->currentIndex()).toString();
        query->prepare("DELETE FROM pool WHERE ab = " + string + ";");
        query->exec();
        ui->tableView->sortByColumn(0, Qt::AscendingOrder);
    }
    model->select();
}

void MainWindow::on_lineEdit_2_textChanged()
{
    QString temp = ui->lineEdit_2->text();
    //qDebug() << temp;
    if(temp != "")
    {
        //query->exec("SELECT * FROM pool WHERE ab LIKE "+temp+"% OR name LIKE "+temp+"% OR phNum = "+temp+" OR abType = "+temp+" OR visRem = "+temp+";");
        //model->setFilter("ab = "+temp+" OR name = "+temp+" OR phNum = "+temp+" OR abType = "+temp+" OR visRem = "+temp+";");
        model->setFilter("ab LIKE "+temp);
        model->select();
    }
    else
    {
        model->setFilter("");
        model->select();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(model->rowCount() == 1)
    {
        QString temp = ui->tableView->model()->index(0,0).data().toString();
        int tempR = ui->tableView->model()->index(0,4).data().toInt()-1;
        qDebug() << tempR;
        QString tempR_ = QString::number(tempR);
        qDebug() << tempR_;
        if(query->exec("UPDATE pool SET visRem = "+tempR_+" WHERE ab = "+temp+";"))
           qDebug() << "Ddone";
    }
    model->select();
}

/*void MainWindow::putstr()
{
    if(!ui->lineEdit->isModified())
    {
        QString string = ui->tableView->model()->data(ui->tableView->currentIndex()).toString();
        ui->lineEdit->setText(string);
    }
}*/
