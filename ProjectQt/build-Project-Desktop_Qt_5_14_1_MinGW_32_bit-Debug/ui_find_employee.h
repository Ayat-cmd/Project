/********************************************************************************
** Form generated from reading UI file 'find_employee.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIND_EMPLOYEE_H
#define UI_FIND_EMPLOYEE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Find_employee
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *choiceFind;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QCheckBox *findSNP_check;
    QCheckBox *findPhone_check;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *OkFind_Btn;
    QGroupBox *find_to_SNP;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *surname_label;
    QLineEdit *surnameFind_line;
    QHBoxLayout *horizontalLayout_3;
    QLabel *name_label;
    QLineEdit *nameFind_line;
    QHBoxLayout *horizontalLayout_4;
    QLabel *patrinymic_label;
    QLineEdit *patranomicFind_line;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *backFindSNP_Btn;
    QPushButton *OkFindSNP_Btn;
    QGroupBox *find_to_phine;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *phoneFind_label;
    QLineEdit *phoneFind_line;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Back_find_to_phine;
    QPushButton *OkFindPhone_Btn;

    void setupUi(QDialog *Find_employee)
    {
        if (Find_employee->objectName().isEmpty())
            Find_employee->setObjectName(QString::fromUtf8("Find_employee"));
        Find_employee->resize(589, 371);
        gridLayout_4 = new QGridLayout(Find_employee);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        choiceFind = new QGroupBox(Find_employee);
        choiceFind->setObjectName(QString::fromUtf8("choiceFind"));
        gridLayout_3 = new QGridLayout(choiceFind);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        findSNP_check = new QCheckBox(choiceFind);
        findSNP_check->setObjectName(QString::fromUtf8("findSNP_check"));

        verticalLayout->addWidget(findSNP_check);

        findPhone_check = new QCheckBox(choiceFind);
        findPhone_check->setObjectName(QString::fromUtf8("findPhone_check"));

        verticalLayout->addWidget(findPhone_check);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(choiceFind);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        OkFind_Btn = new QPushButton(choiceFind);
        OkFind_Btn->setObjectName(QString::fromUtf8("OkFind_Btn"));

        horizontalLayout->addWidget(OkFind_Btn);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_4->addWidget(choiceFind, 0, 0, 1, 1);

        find_to_SNP = new QGroupBox(Find_employee);
        find_to_SNP->setObjectName(QString::fromUtf8("find_to_SNP"));
        gridLayout = new QGridLayout(find_to_SNP);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        surname_label = new QLabel(find_to_SNP);
        surname_label->setObjectName(QString::fromUtf8("surname_label"));

        horizontalLayout_2->addWidget(surname_label);

        surnameFind_line = new QLineEdit(find_to_SNP);
        surnameFind_line->setObjectName(QString::fromUtf8("surnameFind_line"));

        horizontalLayout_2->addWidget(surnameFind_line);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        name_label = new QLabel(find_to_SNP);
        name_label->setObjectName(QString::fromUtf8("name_label"));

        horizontalLayout_3->addWidget(name_label);

        nameFind_line = new QLineEdit(find_to_SNP);
        nameFind_line->setObjectName(QString::fromUtf8("nameFind_line"));

        horizontalLayout_3->addWidget(nameFind_line);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        patrinymic_label = new QLabel(find_to_SNP);
        patrinymic_label->setObjectName(QString::fromUtf8("patrinymic_label"));

        horizontalLayout_4->addWidget(patrinymic_label);

        patranomicFind_line = new QLineEdit(find_to_SNP);
        patranomicFind_line->setObjectName(QString::fromUtf8("patranomicFind_line"));

        horizontalLayout_4->addWidget(patranomicFind_line);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        backFindSNP_Btn = new QPushButton(find_to_SNP);
        backFindSNP_Btn->setObjectName(QString::fromUtf8("backFindSNP_Btn"));

        horizontalLayout_5->addWidget(backFindSNP_Btn);

        OkFindSNP_Btn = new QPushButton(find_to_SNP);
        OkFindSNP_Btn->setObjectName(QString::fromUtf8("OkFindSNP_Btn"));

        horizontalLayout_5->addWidget(OkFindSNP_Btn);


        verticalLayout_2->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_4->addWidget(find_to_SNP, 0, 1, 1, 1);

        find_to_phine = new QGroupBox(Find_employee);
        find_to_phine->setObjectName(QString::fromUtf8("find_to_phine"));
        gridLayout_2 = new QGridLayout(find_to_phine);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        phoneFind_label = new QLabel(find_to_phine);
        phoneFind_label->setObjectName(QString::fromUtf8("phoneFind_label"));

        horizontalLayout_7->addWidget(phoneFind_label);

        phoneFind_line = new QLineEdit(find_to_phine);
        phoneFind_line->setObjectName(QString::fromUtf8("phoneFind_line"));

        horizontalLayout_7->addWidget(phoneFind_line);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        Back_find_to_phine = new QPushButton(find_to_phine);
        Back_find_to_phine->setObjectName(QString::fromUtf8("Back_find_to_phine"));

        horizontalLayout_6->addWidget(Back_find_to_phine);

        OkFindPhone_Btn = new QPushButton(find_to_phine);
        OkFindPhone_Btn->setObjectName(QString::fromUtf8("OkFindPhone_Btn"));

        horizontalLayout_6->addWidget(OkFindPhone_Btn);


        verticalLayout_3->addLayout(horizontalLayout_6);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);


        gridLayout_4->addWidget(find_to_phine, 1, 0, 1, 1);


        retranslateUi(Find_employee);

        QMetaObject::connectSlotsByName(Find_employee);
    } // setupUi

    void retranslateUi(QDialog *Find_employee)
    {
        Find_employee->setWindowTitle(QCoreApplication::translate("Find_employee", "Dialog", nullptr));
        choiceFind->setTitle(QCoreApplication::translate("Find_employee", "\320\222\321\213\320\261\320\276\321\200 \320\277\320\276\320\270\321\201\320\272\320\260", nullptr));
        findSNP_check->setText(QCoreApplication::translate("Find_employee", "\320\235\320\260\320\271\321\202\320\270 \320\277\320\276 \320\244\320\230\320\236", nullptr));
        findPhone_check->setText(QCoreApplication::translate("Find_employee", "\320\235\320\260\320\271\321\202\320\270 \320\277\320\276 \320\275\320\276\320\274\320\265\321\200\321\203 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", nullptr));
        pushButton->setText(QCoreApplication::translate("Find_employee", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        OkFind_Btn->setText(QCoreApplication::translate("Find_employee", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
        find_to_SNP->setTitle(QCoreApplication::translate("Find_employee", "\320\237\320\276\320\270\321\201\320\272 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260 \320\277\320\276 \320\244\320\230\320\236", nullptr));
        surname_label->setText(QCoreApplication::translate("Find_employee", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217:", nullptr));
        name_label->setText(QCoreApplication::translate("Find_employee", "\320\230\320\274\321\217:", nullptr));
        patrinymic_label->setText(QCoreApplication::translate("Find_employee", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276:", nullptr));
        backFindSNP_Btn->setText(QCoreApplication::translate("Find_employee", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        OkFindSNP_Btn->setText(QCoreApplication::translate("Find_employee", "OK", nullptr));
        find_to_phine->setTitle(QCoreApplication::translate("Find_employee", "\320\237\320\276\320\270\321\201\320\272 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260 \320\277\320\276 \320\275\320\276\320\274\320\265\321\200\321\203", nullptr));
        phoneFind_label->setText(QCoreApplication::translate("Find_employee", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260:", nullptr));
        Back_find_to_phine->setText(QCoreApplication::translate("Find_employee", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        OkFindPhone_Btn->setText(QCoreApplication::translate("Find_employee", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Find_employee: public Ui_Find_employee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIND_EMPLOYEE_H
