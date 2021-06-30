/********************************************************************************
** Form generated from reading UI file 'addworker.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWORKER_H
#define UI_ADDWORKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_addWorker
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *addWorker)
    {
        if (addWorker->objectName().isEmpty())
            addWorker->setObjectName(QString::fromUtf8("addWorker"));
        addWorker->resize(400, 300);
        label = new QLabel(addWorker);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 60, 56, 16));
        label_2 = new QLabel(addWorker);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 90, 56, 16));
        label_3 = new QLabel(addWorker);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 120, 56, 16));
        label_4 = new QLabel(addWorker);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 150, 56, 16));

        retranslateUi(addWorker);

        QMetaObject::connectSlotsByName(addWorker);
    } // setupUi

    void retranslateUi(QDialog *addWorker)
    {
        addWorker->setWindowTitle(QCoreApplication::translate("addWorker", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("addWorker", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("addWorker", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("addWorker", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("addWorker", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addWorker: public Ui_addWorker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWORKER_H
