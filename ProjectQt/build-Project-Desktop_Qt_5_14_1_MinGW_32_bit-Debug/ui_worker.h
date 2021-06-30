/********************************************************************************
** Form generated from reading UI file 'worker.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKER_H
#define UI_WORKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Worker
{
public:
    QGridLayout *gridLayout_6;
    QGroupBox *countWorker_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *worker;
    QPushButton *countWorker;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *close_Btn;
    QPushButton *saveWorker;
    QGroupBox *Choice;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *OneWorker;
    QCheckBox *Workers;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *cancel;
    QPushButton *OK;
    QGroupBox *Choice_DeleteWorker;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *All_deleteWorker_check;
    QCheckBox *delete_WorkerChoice_check;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *back_find_worker_phone_delete;
    QPushButton *delete_phone_Btn;
    QGroupBox *new_Worker;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *surname_label;
    QLineEdit *surname;
    QHBoxLayout *horizontalLayout_4;
    QLabel *name_label;
    QLineEdit *name;
    QHBoxLayout *horizontalLayout_5;
    QLabel *patronymic_label;
    QLineEdit *patronymic;
    QHBoxLayout *horizontalLayout_6;
    QLabel *phone_label;
    QLabel *countPhone_label;
    QLineEdit *phone;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Back_ChoiceAddWorker_Btn;
    QPushButton *newWork_btn;
    QGroupBox *deleteChoice_Box;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_6;
    QTextBrowser *Worker_textBrowser;
    QLabel *deleteWorkerChoice_label;
    QLineEdit *deleteWorker_line;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *back_Choice_DeleteWorker_Btn;
    QPushButton *ChoiceDelete_Btn;

    void setupUi(QDialog *Worker)
    {
        if (Worker->objectName().isEmpty())
            Worker->setObjectName(QString::fromUtf8("Worker"));
        Worker->resize(761, 492);
        Worker->setMinimumSize(QSize(282, 212));
        Worker->setMaximumSize(QSize(10000, 14342432));
        gridLayout_6 = new QGridLayout(Worker);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        countWorker_2 = new QGroupBox(Worker);
        countWorker_2->setObjectName(QString::fromUtf8("countWorker_2"));
        countWorker_2->setMaximumSize(QSize(465546, 16777215));
        gridLayout = new QGridLayout(countWorker_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(countWorker_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        worker = new QLineEdit(countWorker_2);
        worker->setObjectName(QString::fromUtf8("worker"));

        horizontalLayout->addWidget(worker);

        countWorker = new QPushButton(countWorker_2);
        countWorker->setObjectName(QString::fromUtf8("countWorker"));

        horizontalLayout->addWidget(countWorker);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(countWorker_2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        close_Btn = new QPushButton(countWorker_2);
        close_Btn->setObjectName(QString::fromUtf8("close_Btn"));

        horizontalLayout_2->addWidget(close_Btn);

        saveWorker = new QPushButton(countWorker_2);
        saveWorker->setObjectName(QString::fromUtf8("saveWorker"));

        horizontalLayout_2->addWidget(saveWorker);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_6->addWidget(countWorker_2, 0, 0, 2, 1);

        Choice = new QGroupBox(Worker);
        Choice->setObjectName(QString::fromUtf8("Choice"));
        Choice->setMaximumSize(QSize(178957, 16777215));
        gridLayout_3 = new QGridLayout(Choice);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_6 = new QLabel(Choice);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_4->addWidget(label_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        OneWorker = new QCheckBox(Choice);
        OneWorker->setObjectName(QString::fromUtf8("OneWorker"));

        verticalLayout_3->addWidget(OneWorker);

        Workers = new QCheckBox(Choice);
        Workers->setObjectName(QString::fromUtf8("Workers"));

        verticalLayout_3->addWidget(Workers);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        cancel = new QPushButton(Choice);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        horizontalLayout_8->addWidget(cancel);

        OK = new QPushButton(Choice);
        OK->setObjectName(QString::fromUtf8("OK"));

        horizontalLayout_8->addWidget(OK);


        verticalLayout_4->addLayout(horizontalLayout_8);


        gridLayout_3->addLayout(verticalLayout_4, 0, 0, 1, 1);


        gridLayout_6->addWidget(Choice, 0, 1, 1, 1);

        Choice_DeleteWorker = new QGroupBox(Worker);
        Choice_DeleteWorker->setObjectName(QString::fromUtf8("Choice_DeleteWorker"));
        gridLayout_4 = new QGridLayout(Choice_DeleteWorker);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        All_deleteWorker_check = new QCheckBox(Choice_DeleteWorker);
        All_deleteWorker_check->setObjectName(QString::fromUtf8("All_deleteWorker_check"));

        verticalLayout_5->addWidget(All_deleteWorker_check);

        delete_WorkerChoice_check = new QCheckBox(Choice_DeleteWorker);
        delete_WorkerChoice_check->setObjectName(QString::fromUtf8("delete_WorkerChoice_check"));

        verticalLayout_5->addWidget(delete_WorkerChoice_check);


        gridLayout_4->addLayout(verticalLayout_5, 0, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);

        back_find_worker_phone_delete = new QPushButton(Choice_DeleteWorker);
        back_find_worker_phone_delete->setObjectName(QString::fromUtf8("back_find_worker_phone_delete"));

        horizontalLayout_9->addWidget(back_find_worker_phone_delete);

        delete_phone_Btn = new QPushButton(Choice_DeleteWorker);
        delete_phone_Btn->setObjectName(QString::fromUtf8("delete_phone_Btn"));

        horizontalLayout_9->addWidget(delete_phone_Btn);


        gridLayout_4->addLayout(horizontalLayout_9, 1, 0, 1, 1);


        gridLayout_6->addWidget(Choice_DeleteWorker, 1, 1, 1, 1);

        new_Worker = new QGroupBox(Worker);
        new_Worker->setObjectName(QString::fromUtf8("new_Worker"));
        new_Worker->setMaximumSize(QSize(6436543, 16777215));
        gridLayout_2 = new QGridLayout(new_Worker);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        surname_label = new QLabel(new_Worker);
        surname_label->setObjectName(QString::fromUtf8("surname_label"));

        horizontalLayout_3->addWidget(surname_label);

        surname = new QLineEdit(new_Worker);
        surname->setObjectName(QString::fromUtf8("surname"));

        horizontalLayout_3->addWidget(surname);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        name_label = new QLabel(new_Worker);
        name_label->setObjectName(QString::fromUtf8("name_label"));

        horizontalLayout_4->addWidget(name_label);

        name = new QLineEdit(new_Worker);
        name->setObjectName(QString::fromUtf8("name"));

        horizontalLayout_4->addWidget(name);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        patronymic_label = new QLabel(new_Worker);
        patronymic_label->setObjectName(QString::fromUtf8("patronymic_label"));

        horizontalLayout_5->addWidget(patronymic_label);

        patronymic = new QLineEdit(new_Worker);
        patronymic->setObjectName(QString::fromUtf8("patronymic"));

        horizontalLayout_5->addWidget(patronymic);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        phone_label = new QLabel(new_Worker);
        phone_label->setObjectName(QString::fromUtf8("phone_label"));

        horizontalLayout_6->addWidget(phone_label);

        countPhone_label = new QLabel(new_Worker);
        countPhone_label->setObjectName(QString::fromUtf8("countPhone_label"));

        horizontalLayout_6->addWidget(countPhone_label);

        phone = new QLineEdit(new_Worker);
        phone->setObjectName(QString::fromUtf8("phone"));

        horizontalLayout_6->addWidget(phone);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        Back_ChoiceAddWorker_Btn = new QPushButton(new_Worker);
        Back_ChoiceAddWorker_Btn->setObjectName(QString::fromUtf8("Back_ChoiceAddWorker_Btn"));

        horizontalLayout_7->addWidget(Back_ChoiceAddWorker_Btn);

        newWork_btn = new QPushButton(new_Worker);
        newWork_btn->setObjectName(QString::fromUtf8("newWork_btn"));

        horizontalLayout_7->addWidget(newWork_btn);


        verticalLayout_2->addLayout(horizontalLayout_7);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_6->addWidget(new_Worker, 2, 0, 1, 1);

        deleteChoice_Box = new QGroupBox(Worker);
        deleteChoice_Box->setObjectName(QString::fromUtf8("deleteChoice_Box"));
        gridLayout_5 = new QGridLayout(deleteChoice_Box);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        Worker_textBrowser = new QTextBrowser(deleteChoice_Box);
        Worker_textBrowser->setObjectName(QString::fromUtf8("Worker_textBrowser"));

        verticalLayout_6->addWidget(Worker_textBrowser);

        deleteWorkerChoice_label = new QLabel(deleteChoice_Box);
        deleteWorkerChoice_label->setObjectName(QString::fromUtf8("deleteWorkerChoice_label"));

        verticalLayout_6->addWidget(deleteWorkerChoice_label);

        deleteWorker_line = new QLineEdit(deleteChoice_Box);
        deleteWorker_line->setObjectName(QString::fromUtf8("deleteWorker_line"));

        verticalLayout_6->addWidget(deleteWorker_line);


        gridLayout_5->addLayout(verticalLayout_6, 0, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_5);

        back_Choice_DeleteWorker_Btn = new QPushButton(deleteChoice_Box);
        back_Choice_DeleteWorker_Btn->setObjectName(QString::fromUtf8("back_Choice_DeleteWorker_Btn"));

        horizontalLayout_10->addWidget(back_Choice_DeleteWorker_Btn);

        ChoiceDelete_Btn = new QPushButton(deleteChoice_Box);
        ChoiceDelete_Btn->setObjectName(QString::fromUtf8("ChoiceDelete_Btn"));

        horizontalLayout_10->addWidget(ChoiceDelete_Btn);


        gridLayout_5->addLayout(horizontalLayout_10, 1, 0, 1, 1);


        gridLayout_6->addWidget(deleteChoice_Box, 2, 1, 1, 1);


        retranslateUi(Worker);

        QMetaObject::connectSlotsByName(Worker);
    } // setupUi

    void retranslateUi(QDialog *Worker)
    {
        Worker->setWindowTitle(QCoreApplication::translate("Worker", "Dialog", nullptr));
        countWorker_2->setTitle(QCoreApplication::translate("Worker", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\276\320\262", nullptr));
        label->setText(QCoreApplication::translate("Worker", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\273-\320\262\320\276: ", nullptr));
        countWorker->setText(QCoreApplication::translate("Worker", "\320\227\320\260\320\264\320\260\321\202\321\214", nullptr));
        close_Btn->setText(QCoreApplication::translate("Worker", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        saveWorker->setText(QCoreApplication::translate("Worker", "\320\236\320\232", nullptr));
        Choice->setTitle(QCoreApplication::translate("Worker", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        label_6->setText(QCoreApplication::translate("Worker", "                        \320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 1-\320\263\320\276 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260 \320\270\320\273\320\270 \320\275\320\265\321\201\320\272\320\276\320\273\321\214\320\272\320\276?", nullptr));
        OneWorker->setText(QCoreApplication::translate("Worker", "\320\236\320\264\320\275\320\276\320\263\320\276", nullptr));
        Workers->setText(QCoreApplication::translate("Worker", "\320\235\320\265\321\201\320\272\320\276\320\273\321\214\320\272\320\276", nullptr));
        cancel->setText(QCoreApplication::translate("Worker", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        OK->setText(QCoreApplication::translate("Worker", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
        Choice_DeleteWorker->setTitle(QCoreApplication::translate("Worker", "\320\243\320\262\320\276\320\273\321\214\320\275\320\265\320\275\320\270\320\265 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260", nullptr));
        All_deleteWorker_check->setText(QCoreApplication::translate("Worker", " \321\203\320\262\320\276\320\273\320\270\321\202\321\214 \320\262\321\201\320\265\321\205 \320\275\320\260\320\271\320\264\320\265\320\275\320\275\321\213\321\205 \321\201 \321\202\320\260\320\272\320\270\320\274 \320\275\320\276\320\274\320\265\321\200\320\276\320\274 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\276\320\262", nullptr));
        delete_WorkerChoice_check->setText(QCoreApplication::translate("Worker", "\321\203\320\262\320\276\320\273\320\270\321\202\321\214 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260 \320\277\320\276 \320\262\321\213\320\261\320\276\321\200\321\203", nullptr));
        back_find_worker_phone_delete->setText(QCoreApplication::translate("Worker", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        delete_phone_Btn->setText(QCoreApplication::translate("Worker", "OK", nullptr));
        new_Worker->setTitle(QCoreApplication::translate("Worker", "\320\235\320\276\320\262\321\213\320\271 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272", nullptr));
        surname_label->setText(QCoreApplication::translate("Worker", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217:", nullptr));
        name_label->setText(QCoreApplication::translate("Worker", "    \320\230\320\274\321\217:    ", nullptr));
        patronymic_label->setText(QCoreApplication::translate("Worker", " \320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276:", nullptr));
        patronymic->setText(QString());
        phone_label->setText(QCoreApplication::translate("Worker", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260:", nullptr));
        countPhone_label->setText(QString());
        Back_ChoiceAddWorker_Btn->setText(QCoreApplication::translate("Worker", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        newWork_btn->setText(QCoreApplication::translate("Worker", "\320\236\320\232", nullptr));
        deleteChoice_Box->setTitle(QCoreApplication::translate("Worker", "\320\243\320\262\320\260\320\276\320\273\320\270\321\202\321\214 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260", nullptr));
        deleteWorkerChoice_label->setText(QCoreApplication::translate("Worker", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260 \320\272\320\276\321\202\320\276\321\200\320\276\320\263\320\276 \321\205\320\276\321\202\320\270\321\202\320\265 \321\203\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        back_Choice_DeleteWorker_Btn->setText(QCoreApplication::translate("Worker", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        ChoiceDelete_Btn->setText(QCoreApplication::translate("Worker", "\320\243\320\262\320\276\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Worker: public Ui_Worker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKER_H
