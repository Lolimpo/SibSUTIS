#include "helpdesk.h"
#include "ui_helpdesk.h"

HelpDesk::HelpDesk(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpDesk)
{
    QFile file("/home/lolimpo/Projects/Visual Programming/swimming_pool/Help/help.html");
    ui->setupUi(this);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning("Файл справки не найден!");
    }
    ui->textBrowser->setHtml(QString::fromUtf8(file.readAll()));
}

HelpDesk::~HelpDesk()
{
    delete ui;
}
