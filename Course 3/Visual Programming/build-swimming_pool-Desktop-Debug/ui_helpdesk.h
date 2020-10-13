/********************************************************************************
** Form generated from reading UI file 'helpdesk.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPDESK_H
#define UI_HELPDESK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpDesk
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QWidget *HelpDesk)
    {
        if (HelpDesk->objectName().isEmpty())
            HelpDesk->setObjectName(QString::fromUtf8("HelpDesk"));
        HelpDesk->resize(800, 600);
        textBrowser = new QTextBrowser(HelpDesk);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 801, 601));

        retranslateUi(HelpDesk);

        QMetaObject::connectSlotsByName(HelpDesk);
    } // setupUi

    void retranslateUi(QWidget *HelpDesk)
    {
        HelpDesk->setWindowTitle(QCoreApplication::translate("HelpDesk", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpDesk: public Ui_HelpDesk {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDESK_H
