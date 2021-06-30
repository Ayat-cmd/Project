/********************************************************************************
** Form generated from reading UI file 'supplier.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPLIER_H
#define UI_SUPPLIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Supplier
{
public:
    QGridLayout *gridLayout_6;
    QGroupBox *setSupplier;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer;
    QPushButton *Close_WriteSup_Btn;
    QPushButton *writeSup_Btn;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *surname_label;
    QLineEdit *Surname;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *name_label;
    QLineEdit *Name;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *patronymic_label;
    QLineEdit *Patronymic;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *phone_label;
    QLineEdit *numberPhone;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *ElCoffeeM;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *El_Blender;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *ElMyasoR;
    QGroupBox *ChangeDataSup;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *textBrowser_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *SuppChange_label;
    QLineEdit *dataSuppChange;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *back_Option_Btn;
    QPushButton *Supp_PhSNP_btn;
    QGroupBox *InstallCostKit_Box;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_22;
    QHBoxLayout *horizontalLayout_24;
    QLabel *kofCost_label;
    QLineEdit *kof_line;
    QHBoxLayout *horizontalLayout_25;
    QLabel *BlCost_label;
    QLineEdit *Bl_line;
    QHBoxLayout *horizontalLayout_26;
    QLabel *myasRCost_label;
    QLineEdit *MyasR_line;
    QHBoxLayout *horizontalLayout_27;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *back_costKit_Btn;
    QPushButton *costKit_Btn;
    QGroupBox *NewDataSup;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_12;
    QLabel *newDataSup_label;
    QLineEdit *newDataSup;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *back_ChangeDataSup_Btn;
    QPushButton *new_DataSup_btn;

    void setupUi(QDialog *Supplier)
    {
        if (Supplier->objectName().isEmpty())
            Supplier->setObjectName(QString::fromUtf8("Supplier"));
        Supplier->resize(988, 536);
        gridLayout_6 = new QGridLayout(Supplier);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        setSupplier = new QGroupBox(Supplier);
        setSupplier->setObjectName(QString::fromUtf8("setSupplier"));
        gridLayout_3 = new QGridLayout(setSupplier);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        Close_WriteSup_Btn = new QPushButton(setSupplier);
        Close_WriteSup_Btn->setObjectName(QString::fromUtf8("Close_WriteSup_Btn"));

        horizontalLayout_9->addWidget(Close_WriteSup_Btn);

        writeSup_Btn = new QPushButton(setSupplier);
        writeSup_Btn->setObjectName(QString::fromUtf8("writeSup_Btn"));

        horizontalLayout_9->addWidget(writeSup_Btn);


        gridLayout->addLayout(horizontalLayout_9, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(setSupplier);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        surname_label = new QLabel(setSupplier);
        surname_label->setObjectName(QString::fromUtf8("surname_label"));

        horizontalLayout->addWidget(surname_label);

        Surname = new QLineEdit(setSupplier);
        Surname->setObjectName(QString::fromUtf8("Surname"));

        horizontalLayout->addWidget(Surname);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(setSupplier);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        name_label = new QLabel(setSupplier);
        name_label->setObjectName(QString::fromUtf8("name_label"));

        horizontalLayout_2->addWidget(name_label);

        Name = new QLineEdit(setSupplier);
        Name->setObjectName(QString::fromUtf8("Name"));

        horizontalLayout_2->addWidget(Name);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(setSupplier);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        patronymic_label = new QLabel(setSupplier);
        patronymic_label->setObjectName(QString::fromUtf8("patronymic_label"));

        horizontalLayout_3->addWidget(patronymic_label);

        Patronymic = new QLineEdit(setSupplier);
        Patronymic->setObjectName(QString::fromUtf8("Patronymic"));

        horizontalLayout_3->addWidget(Patronymic);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(setSupplier);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        phone_label = new QLabel(setSupplier);
        phone_label->setObjectName(QString::fromUtf8("phone_label"));

        horizontalLayout_4->addWidget(phone_label);

        numberPhone = new QLineEdit(setSupplier);
        numberPhone->setObjectName(QString::fromUtf8("numberPhone"));

        horizontalLayout_4->addWidget(numberPhone);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(setSupplier);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(setSupplier);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        ElCoffeeM = new QLineEdit(setSupplier);
        ElCoffeeM->setObjectName(QString::fromUtf8("ElCoffeeM"));

        horizontalLayout_6->addWidget(ElCoffeeM);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(setSupplier);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        El_Blender = new QLineEdit(setSupplier);
        El_Blender->setObjectName(QString::fromUtf8("El_Blender"));

        horizontalLayout_7->addWidget(El_Blender);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(setSupplier);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        ElMyasoR = new QLineEdit(setSupplier);
        ElMyasoR->setObjectName(QString::fromUtf8("ElMyasoR"));

        horizontalLayout_8->addWidget(ElMyasoR);


        verticalLayout->addLayout(horizontalLayout_8);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_6->addWidget(setSupplier, 0, 0, 1, 1);

        ChangeDataSup = new QGroupBox(Supplier);
        ChangeDataSup->setObjectName(QString::fromUtf8("ChangeDataSup"));
        gridLayout_2 = new QGridLayout(ChangeDataSup);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textBrowser_2 = new QTextBrowser(ChangeDataSup);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));

        verticalLayout_2->addWidget(textBrowser_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        SuppChange_label = new QLabel(ChangeDataSup);
        SuppChange_label->setObjectName(QString::fromUtf8("SuppChange_label"));

        horizontalLayout_10->addWidget(SuppChange_label);

        dataSuppChange = new QLineEdit(ChangeDataSup);
        dataSuppChange->setObjectName(QString::fromUtf8("dataSuppChange"));

        horizontalLayout_10->addWidget(dataSuppChange);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);

        back_Option_Btn = new QPushButton(ChangeDataSup);
        back_Option_Btn->setObjectName(QString::fromUtf8("back_Option_Btn"));

        horizontalLayout_11->addWidget(back_Option_Btn);

        Supp_PhSNP_btn = new QPushButton(ChangeDataSup);
        Supp_PhSNP_btn->setObjectName(QString::fromUtf8("Supp_PhSNP_btn"));

        horizontalLayout_11->addWidget(Supp_PhSNP_btn);


        verticalLayout_2->addLayout(horizontalLayout_11);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_6->addWidget(ChangeDataSup, 0, 1, 1, 1);

        InstallCostKit_Box = new QGroupBox(Supplier);
        InstallCostKit_Box->setObjectName(QString::fromUtf8("InstallCostKit_Box"));
        gridLayout_5 = new QGridLayout(InstallCostKit_Box);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_22 = new QLabel(InstallCostKit_Box);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        verticalLayout_4->addWidget(label_22);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        kofCost_label = new QLabel(InstallCostKit_Box);
        kofCost_label->setObjectName(QString::fromUtf8("kofCost_label"));

        horizontalLayout_24->addWidget(kofCost_label);

        kof_line = new QLineEdit(InstallCostKit_Box);
        kof_line->setObjectName(QString::fromUtf8("kof_line"));

        horizontalLayout_24->addWidget(kof_line);


        verticalLayout_4->addLayout(horizontalLayout_24);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        BlCost_label = new QLabel(InstallCostKit_Box);
        BlCost_label->setObjectName(QString::fromUtf8("BlCost_label"));

        horizontalLayout_25->addWidget(BlCost_label);

        Bl_line = new QLineEdit(InstallCostKit_Box);
        Bl_line->setObjectName(QString::fromUtf8("Bl_line"));

        horizontalLayout_25->addWidget(Bl_line);


        verticalLayout_4->addLayout(horizontalLayout_25);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        myasRCost_label = new QLabel(InstallCostKit_Box);
        myasRCost_label->setObjectName(QString::fromUtf8("myasRCost_label"));

        horizontalLayout_26->addWidget(myasRCost_label);

        MyasR_line = new QLineEdit(InstallCostKit_Box);
        MyasR_line->setObjectName(QString::fromUtf8("MyasR_line"));

        horizontalLayout_26->addWidget(MyasR_line);


        verticalLayout_4->addLayout(horizontalLayout_26);


        gridLayout_5->addLayout(verticalLayout_4, 0, 0, 1, 1);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_27->addItem(horizontalSpacer_4);

        back_costKit_Btn = new QPushButton(InstallCostKit_Box);
        back_costKit_Btn->setObjectName(QString::fromUtf8("back_costKit_Btn"));

        horizontalLayout_27->addWidget(back_costKit_Btn);

        costKit_Btn = new QPushButton(InstallCostKit_Box);
        costKit_Btn->setObjectName(QString::fromUtf8("costKit_Btn"));

        horizontalLayout_27->addWidget(costKit_Btn);


        gridLayout_5->addLayout(horizontalLayout_27, 1, 0, 1, 1);


        gridLayout_6->addWidget(InstallCostKit_Box, 1, 0, 1, 1);

        NewDataSup = new QGroupBox(Supplier);
        NewDataSup->setObjectName(QString::fromUtf8("NewDataSup"));
        gridLayout_4 = new QGridLayout(NewDataSup);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        newDataSup_label = new QLabel(NewDataSup);
        newDataSup_label->setObjectName(QString::fromUtf8("newDataSup_label"));

        horizontalLayout_12->addWidget(newDataSup_label);

        newDataSup = new QLineEdit(NewDataSup);
        newDataSup->setObjectName(QString::fromUtf8("newDataSup"));

        horizontalLayout_12->addWidget(newDataSup);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_3);

        back_ChangeDataSup_Btn = new QPushButton(NewDataSup);
        back_ChangeDataSup_Btn->setObjectName(QString::fromUtf8("back_ChangeDataSup_Btn"));

        horizontalLayout_13->addWidget(back_ChangeDataSup_Btn);

        new_DataSup_btn = new QPushButton(NewDataSup);
        new_DataSup_btn->setObjectName(QString::fromUtf8("new_DataSup_btn"));

        horizontalLayout_13->addWidget(new_DataSup_btn);


        verticalLayout_3->addLayout(horizontalLayout_13);


        gridLayout_4->addLayout(verticalLayout_3, 1, 0, 1, 1);


        gridLayout_6->addWidget(NewDataSup, 1, 1, 1, 1);


        retranslateUi(Supplier);

        QMetaObject::connectSlotsByName(Supplier);
    } // setupUi

    void retranslateUi(QDialog *Supplier)
    {
        Supplier->setWindowTitle(QCoreApplication::translate("Supplier", "Dialog", nullptr));
        setSupplier->setTitle(QCoreApplication::translate("Supplier", "\320\222\320\262\320\276\320\264\320\270\320\274 \320\264\320\260\320\275\320\275\321\213\320\265 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\260", nullptr));
        Close_WriteSup_Btn->setText(QCoreApplication::translate("Supplier", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        writeSup_Btn->setText(QCoreApplication::translate("Supplier", "OK", nullptr));
        label->setText(QCoreApplication::translate("Supplier", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\204\320\260\320\274\320\270\320\273\320\270\321\216 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\260:", nullptr));
        surname_label->setText(QString());
        label_2->setText(QCoreApplication::translate("Supplier", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\274\321\217 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\260:         ", nullptr));
        name_label->setText(QString());
        label_3->setText(QCoreApplication::translate("Supplier", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\260: ", nullptr));
        patronymic_label->setText(QString());
        label_4->setText(QCoreApplication::translate("Supplier", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\260: ", nullptr));
        phone_label->setText(QString());
        label_5->setText(QCoreApplication::translate("Supplier", "                                   \320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\206\320\265\320\275\320\275\321\203 \320\272\320\276\320\274\320\277\320\273\320\265\320\272\321\202\320\260 \320\264\320\265\321\202\320\260\320\273\320\265\320\271, \320\267\320\260 \320\272\320\276\321\202\321\200\321\203\321\216 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272 \320\261\321\203\320\264\320\265\321\202 \320\277\320\276\321\201\321\202\320\260\320\262\320\273\321\217\321\202\321\214 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273!", nullptr));
        label_6->setText(QCoreApplication::translate("Supplier", "  \320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\206\320\265\320\275\320\275\321\203 N>0 \320\267\320\260 \320\276\320\264\320\270\320\275 \320\272\320\276\320\274\320\277\320\273\320\265\320\272\321\202 \320\264\320\265\321\202\320\260\320\273\320\265\320\271 \320\264\320\273\321\217 \321\215\320\273. \320\272\320\276\321\204\320\265\320\274\320\276\320\273\320\272\320\270:", nullptr));
        label_7->setText(QCoreApplication::translate("Supplier", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\206\320\265\320\275\320\275\321\203 N>0 \320\267\320\260 \320\276\320\264\320\270\320\275 \320\272\320\276\320\274\320\277\320\273\320\265\320\272\321\202 \320\264\320\265\321\202\320\260\320\273\320\265\320\271 \320\264\320\273\321\217 \321\215\320\273. \320\261\320\273\320\265\320\275\320\264\320\265\321\200\320\260:  ", nullptr));
        label_8->setText(QCoreApplication::translate("Supplier", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\206\320\265\320\275\320\275\321\203 N>0 \320\267\320\260 \320\276\320\264\320\270\320\275 \320\272\320\276\320\274\320\277\320\273\320\265\320\272\321\202 \320\264\320\265\321\202\320\260\320\273\320\265\320\271 \320\264\320\273\321\217 \321\215\320\273. \320\274\321\217\321\201\320\276\321\200\321\203\320\261\320\272\320\270: ", nullptr));
        ChangeDataSup->setTitle(QCoreApplication::translate("Supplier", "\320\222\321\213\320\261\320\270\321\200\320\260\320\265\320\274 \321\207\321\202\320\276 \320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("Supplier", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\222\320\262\320\265\320\264\320\270\321\202\320\265 1 \321\207\321\202\320\276\320\261\321\213 \320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\244\320\260\320\274\320\270\320\273\320\270\321\216.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt"
                        "-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\222\320\262\320\265\320\264\320\270\321\202\320\265 2 \321\207\321\202\320\276\320\261\321\213 \320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\230\320\274\321\217.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\222\320\262\320\265\320\264\320\270\321\202\320\265 3 \321\207\321\202\320\276\320\261\321\213 \320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text"
                        "-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\222\320\262\320\265\320\264\320\270\321\202\320\265 4 \321\207\321\202\320\276\320\261\321\213 \320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\275\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260.</span></p></body></html>", nullptr));
        SuppChange_label->setText(QCoreApplication::translate("Supplier", "\320\222\320\260\321\210 \320\262\321\213\320\261\320\276\321\200:", nullptr));
        back_Option_Btn->setText(QCoreApplication::translate("Supplier", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        Supp_PhSNP_btn->setText(QCoreApplication::translate("Supplier", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
        InstallCostKit_Box->setTitle(QCoreApplication::translate("Supplier", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \321\206\320\265\320\275 \320\275\320\260 \320\272\320\276\320\274\320\273\320\265\320\272\321\202\321\213 \320\264\320\265\321\202\320\260\320\273\320\265\320\271", nullptr));
        label_22->setText(QCoreApplication::translate("Supplier", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\206\320\265\320\275\320\275\321\203 \320\272\320\276\320\274\320\277\320\273\320\265\320\272\321\202\320\260 \320\264\320\265\321\202\320\260\320\273\320\265\320\271, \320\267\320\260 \320\272\320\276\321\202\321\200\321\203\321\216 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272 \320\261\321\203\320\264\320\265\321\202 \320\277\320\276\321\201\321\202\320\260\320\262\320\273\321\217\321\202\321\214 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273!", nullptr));
        kofCost_label->setText(QCoreApplication::translate("Supplier", "  \320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\206\320\265\320\275\320\275\321\203 N>0 \320\267\320\260 \320\276\320\264\320\270\320\275 \320\272\320\276\320\274\320\277\320\273\320\265\320\272\321\202 \320\264\320\265\321\202\320\260\320\273\320\265\320\271 \320\264\320\273\321\217 \321\215\320\273. \320\272\320\276\321\204\320\265\320\274\320\276\320\273\320\272\320\270:", nullptr));
        BlCost_label->setText(QCoreApplication::translate("Supplier", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\206\320\265\320\275\320\275\321\203 N>0 \320\267\320\260 \320\276\320\264\320\270\320\275 \320\272\320\276\320\274\320\277\320\273\320\265\320\272\321\202 \320\264\320\265\321\202\320\260\320\273\320\265\320\271 \320\264\320\273\321\217 \321\215\320\273. \320\261\320\273\320\265\320\275\320\264\320\265\321\200\320\260:  ", nullptr));
        myasRCost_label->setText(QCoreApplication::translate("Supplier", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\206\320\265\320\275\320\275\321\203 N>0 \320\267\320\260 \320\276\320\264\320\270\320\275 \320\272\320\276\320\274\320\277\320\273\320\265\320\272\321\202 \320\264\320\265\321\202\320\260\320\273\320\265\320\271 \320\264\320\273\321\217 \321\215\320\273. \320\274\321\217\321\201\320\276\321\200\321\203\320\261\320\272\320\270: ", nullptr));
        back_costKit_Btn->setText(QCoreApplication::translate("Supplier", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        costKit_Btn->setText(QCoreApplication::translate("Supplier", "OK", nullptr));
        NewDataSup->setTitle(QCoreApplication::translate("Supplier", "\320\230\320\267\320\274\320\265\320\275\321\217\320\265\320\274 \320\264\320\260\320\275\320\275\321\213\320\265 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\260", nullptr));
        newDataSup_label->setText(QCoreApplication::translate("Supplier", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\262\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\260", nullptr));
        back_ChangeDataSup_Btn->setText(QCoreApplication::translate("Supplier", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        new_DataSup_btn->setText(QCoreApplication::translate("Supplier", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Supplier: public Ui_Supplier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPLIER_H
