/********************************************************************************
** Form generated from reading UI file 'print_workers.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINT_WORKERS_H
#define UI_PRINT_WORKERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Print_Workers
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTextBrowser *printShowWorkers;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *printWorker_btn;

    void setupUi(QDialog *Print_Workers)
    {
        if (Print_Workers->objectName().isEmpty())
            Print_Workers->setObjectName(QString::fromUtf8("Print_Workers"));
        Print_Workers->resize(721, 391);
        gridLayout_2 = new QGridLayout(Print_Workers);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(Print_Workers);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        printShowWorkers = new QTextBrowser(groupBox);
        printShowWorkers->setObjectName(QString::fromUtf8("printShowWorkers"));

        verticalLayout->addWidget(printShowWorkers);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        printWorker_btn = new QPushButton(groupBox);
        printWorker_btn->setObjectName(QString::fromUtf8("printWorker_btn"));

        horizontalLayout->addWidget(printWorker_btn);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(Print_Workers);

        QMetaObject::connectSlotsByName(Print_Workers);
    } // setupUi

    void retranslateUi(QDialog *Print_Workers)
    {
        Print_Workers->setWindowTitle(QCoreApplication::translate("Print_Workers", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Print_Workers", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270", nullptr));
        printWorker_btn->setText(QCoreApplication::translate("Print_Workers", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Print_Workers: public Ui_Print_Workers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINT_WORKERS_H
