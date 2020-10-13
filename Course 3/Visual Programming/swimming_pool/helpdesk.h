#ifndef HELPDESK_H
#define HELPDESK_H

#include <QWidget>
#include <QFile>
namespace Ui {
class HelpDesk;
}

class HelpDesk : public QWidget
{
    Q_OBJECT

public:
    explicit HelpDesk(QWidget *parent = nullptr);
    ~HelpDesk();

private:
    Ui::HelpDesk *ui;
};

#endif // HELPDESK_H
