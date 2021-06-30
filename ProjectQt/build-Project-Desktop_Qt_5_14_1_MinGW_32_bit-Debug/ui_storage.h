/********************************************************************************
** Form generated from reading UI file 'storage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STORAGE_H
#define UI_STORAGE_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Storage
{
public:
    QGridLayout *gridLayout_8;
    QGroupBox *infoSupp;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLabel *lastname;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLabel *name;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QLabel *patronymic;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QLabel *phone;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton;
    QGroupBox *CountKitSup;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Spin_label;
    QSpinBox *countKit_Spin;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *total_cost_ordered_kits;
    QLabel *total_cost_ordered_kits_label;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QPushButton *countKit_Btn;
    QGroupBox *condition_sklad;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *kit_detail;
    QCheckBox *kit_product;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *back_Btn;
    QTextBrowser *quantity_Kit_Product;
    QTextBrowser *quantity_Kit_Detail;
    QGroupBox *kitDetail;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QTextBrowser *textBrowser_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *kit_label;
    QLineEdit *kit_line;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *close_2;
    QPushButton *kit_btn;
    QGroupBox *sellProduct_Box;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_14;
    QLabel *Cof_label;
    QLineEdit *countSell_cof_line;
    QHBoxLayout *horizontalLayout_17;
    QLabel *MyasoR_label;
    QLineEdit *countSell_MyasoR_line;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *back_btn;
    QPushButton *sell_product_btn;
    QHBoxLayout *horizontalLayout_16;
    QLabel *Bl_label;
    QLineEdit *countSell_Bl_line;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *total_cost_sell_product;
    QLabel *total_cost_sell_product_label;
    QGroupBox *Option;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser_2;
    QHBoxLayout *horizontalLayout;
    QLabel *supplierOrKit_label;
    QLineEdit *supplierOrKit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *close;
    QPushButton *changeS_btn;
    QGroupBox *sell_Box;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *sell_elCof_check;
    QCheckBox *sell_elBl_check;
    QCheckBox *sell_elMyasoR_check;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *menu_btn;
    QPushButton *sell_Btn;

    void setupUi(QDialog *Storage)
    {
        if (Storage->objectName().isEmpty())
            Storage->setObjectName(QString::fromUtf8("Storage"));
        Storage->resize(972, 807);
        gridLayout_8 = new QGridLayout(Storage);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        infoSupp = new QGroupBox(Storage);
        infoSupp->setObjectName(QString::fromUtf8("infoSupp"));
        gridLayout = new QGridLayout(infoSupp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(infoSupp);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        lastname = new QLabel(infoSupp);
        lastname->setObjectName(QString::fromUtf8("lastname"));

        horizontalLayout_7->addWidget(lastname);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_6 = new QLabel(infoSupp);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_8->addWidget(label_6);

        name = new QLabel(infoSupp);
        name->setObjectName(QString::fromUtf8("name"));

        horizontalLayout_8->addWidget(name);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_7 = new QLabel(infoSupp);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_9->addWidget(label_7);

        patronymic = new QLabel(infoSupp);
        patronymic->setObjectName(QString::fromUtf8("patronymic"));

        horizontalLayout_9->addWidget(patronymic);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_8 = new QLabel(infoSupp);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_10->addWidget(label_8);

        phone = new QLabel(infoSupp);
        phone->setObjectName(QString::fromUtf8("phone"));

        horizontalLayout_10->addWidget(phone);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_4);

        pushButton = new QPushButton(infoSupp);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_11->addWidget(pushButton);


        verticalLayout_4->addLayout(horizontalLayout_11);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);


        gridLayout_8->addWidget(infoSupp, 0, 0, 1, 1);

        CountKitSup = new QGroupBox(Storage);
        CountKitSup->setObjectName(QString::fromUtf8("CountKitSup"));
        gridLayout_4 = new QGridLayout(CountKitSup);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Spin_label = new QLabel(CountKitSup);
        Spin_label->setObjectName(QString::fromUtf8("Spin_label"));

        horizontalLayout_3->addWidget(Spin_label);

        countKit_Spin = new QSpinBox(CountKitSup);
        countKit_Spin->setObjectName(QString::fromUtf8("countKit_Spin"));
        countKit_Spin->setMaximum(999999999);

        horizontalLayout_3->addWidget(countKit_Spin);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        total_cost_ordered_kits = new QPushButton(CountKitSup);
        total_cost_ordered_kits->setObjectName(QString::fromUtf8("total_cost_ordered_kits"));

        horizontalLayout_18->addWidget(total_cost_ordered_kits);

        total_cost_ordered_kits_label = new QLabel(CountKitSup);
        total_cost_ordered_kits_label->setObjectName(QString::fromUtf8("total_cost_ordered_kits_label"));

        horizontalLayout_18->addWidget(total_cost_ordered_kits_label);


        verticalLayout_2->addLayout(horizontalLayout_18);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(CountKitSup);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_5->addWidget(pushButton_2);

        countKit_Btn = new QPushButton(CountKitSup);
        countKit_Btn->setObjectName(QString::fromUtf8("countKit_Btn"));

        horizontalLayout_5->addWidget(countKit_Btn);


        verticalLayout_2->addLayout(horizontalLayout_5);


        gridLayout_4->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_8->addWidget(CountKitSup, 0, 1, 1, 1);

        condition_sklad = new QGroupBox(Storage);
        condition_sklad->setObjectName(QString::fromUtf8("condition_sklad"));
        gridLayout_5 = new QGridLayout(condition_sklad);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        kit_detail = new QCheckBox(condition_sklad);
        kit_detail->setObjectName(QString::fromUtf8("kit_detail"));

        verticalLayout_5->addWidget(kit_detail);

        kit_product = new QCheckBox(condition_sklad);
        kit_product->setObjectName(QString::fromUtf8("kit_product"));

        verticalLayout_5->addWidget(kit_product);


        verticalLayout_6->addLayout(verticalLayout_5);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer_5 = new QSpacerItem(40, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_5);

        back_Btn = new QPushButton(condition_sklad);
        back_Btn->setObjectName(QString::fromUtf8("back_Btn"));

        horizontalLayout_12->addWidget(back_Btn);


        verticalLayout_6->addLayout(horizontalLayout_12);


        gridLayout_5->addLayout(verticalLayout_6, 0, 1, 1, 1);

        quantity_Kit_Product = new QTextBrowser(condition_sklad);
        quantity_Kit_Product->setObjectName(QString::fromUtf8("quantity_Kit_Product"));

        gridLayout_5->addWidget(quantity_Kit_Product, 1, 0, 1, 3);

        quantity_Kit_Detail = new QTextBrowser(condition_sklad);
        quantity_Kit_Detail->setObjectName(QString::fromUtf8("quantity_Kit_Detail"));

        gridLayout_5->addWidget(quantity_Kit_Detail, 2, 0, 1, 3);


        gridLayout_8->addWidget(condition_sklad, 0, 2, 2, 1);

        kitDetail = new QGroupBox(Storage);
        kitDetail->setObjectName(QString::fromUtf8("kitDetail"));
        gridLayout_3 = new QGridLayout(kitDetail);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        textBrowser_3 = new QTextBrowser(kitDetail);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));

        verticalLayout_3->addWidget(textBrowser_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        kit_label = new QLabel(kitDetail);
        kit_label->setObjectName(QString::fromUtf8("kit_label"));

        horizontalLayout_4->addWidget(kit_label);

        kit_line = new QLineEdit(kitDetail);
        kit_line->setObjectName(QString::fromUtf8("kit_line"));

        horizontalLayout_4->addWidget(kit_line);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        close_2 = new QPushButton(kitDetail);
        close_2->setObjectName(QString::fromUtf8("close_2"));

        horizontalLayout_6->addWidget(close_2);

        kit_btn = new QPushButton(kitDetail);
        kit_btn->setObjectName(QString::fromUtf8("kit_btn"));

        horizontalLayout_6->addWidget(kit_btn);


        verticalLayout_3->addLayout(horizontalLayout_6);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);


        gridLayout_8->addWidget(kitDetail, 1, 0, 2, 1);

        sellProduct_Box = new QGroupBox(Storage);
        sellProduct_Box->setObjectName(QString::fromUtf8("sellProduct_Box"));
        gridLayout_7 = new QGridLayout(sellProduct_Box);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        Cof_label = new QLabel(sellProduct_Box);
        Cof_label->setObjectName(QString::fromUtf8("Cof_label"));

        horizontalLayout_14->addWidget(Cof_label);

        countSell_cof_line = new QLineEdit(sellProduct_Box);
        countSell_cof_line->setObjectName(QString::fromUtf8("countSell_cof_line"));

        horizontalLayout_14->addWidget(countSell_cof_line);


        gridLayout_7->addLayout(horizontalLayout_14, 0, 0, 1, 1);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        MyasoR_label = new QLabel(sellProduct_Box);
        MyasoR_label->setObjectName(QString::fromUtf8("MyasoR_label"));

        horizontalLayout_17->addWidget(MyasoR_label);

        countSell_MyasoR_line = new QLineEdit(sellProduct_Box);
        countSell_MyasoR_line->setObjectName(QString::fromUtf8("countSell_MyasoR_line"));

        horizontalLayout_17->addWidget(countSell_MyasoR_line);


        gridLayout_7->addLayout(horizontalLayout_17, 2, 0, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalSpacer_7 = new QSpacerItem(112, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_7);

        back_btn = new QPushButton(sellProduct_Box);
        back_btn->setObjectName(QString::fromUtf8("back_btn"));

        horizontalLayout_15->addWidget(back_btn);

        sell_product_btn = new QPushButton(sellProduct_Box);
        sell_product_btn->setObjectName(QString::fromUtf8("sell_product_btn"));

        horizontalLayout_15->addWidget(sell_product_btn);


        gridLayout_7->addLayout(horizontalLayout_15, 4, 0, 1, 1);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        Bl_label = new QLabel(sellProduct_Box);
        Bl_label->setObjectName(QString::fromUtf8("Bl_label"));

        horizontalLayout_16->addWidget(Bl_label);

        countSell_Bl_line = new QLineEdit(sellProduct_Box);
        countSell_Bl_line->setObjectName(QString::fromUtf8("countSell_Bl_line"));

        horizontalLayout_16->addWidget(countSell_Bl_line);


        gridLayout_7->addLayout(horizontalLayout_16, 1, 0, 1, 1);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        total_cost_sell_product = new QPushButton(sellProduct_Box);
        total_cost_sell_product->setObjectName(QString::fromUtf8("total_cost_sell_product"));

        horizontalLayout_19->addWidget(total_cost_sell_product);

        total_cost_sell_product_label = new QLabel(sellProduct_Box);
        total_cost_sell_product_label->setObjectName(QString::fromUtf8("total_cost_sell_product_label"));

        horizontalLayout_19->addWidget(total_cost_sell_product_label);


        gridLayout_7->addLayout(horizontalLayout_19, 3, 0, 1, 1);


        gridLayout_8->addWidget(sellProduct_Box, 2, 1, 2, 1);

        Option = new QGroupBox(Storage);
        Option->setObjectName(QString::fromUtf8("Option"));
        gridLayout_2 = new QGridLayout(Option);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser_2 = new QTextBrowser(Option);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));

        verticalLayout->addWidget(textBrowser_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        supplierOrKit_label = new QLabel(Option);
        supplierOrKit_label->setObjectName(QString::fromUtf8("supplierOrKit_label"));

        horizontalLayout->addWidget(supplierOrKit_label);

        supplierOrKit = new QLineEdit(Option);
        supplierOrKit->setObjectName(QString::fromUtf8("supplierOrKit"));

        horizontalLayout->addWidget(supplierOrKit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        close = new QPushButton(Option);
        close->setObjectName(QString::fromUtf8("close"));

        horizontalLayout_2->addWidget(close);

        changeS_btn = new QPushButton(Option);
        changeS_btn->setObjectName(QString::fromUtf8("changeS_btn"));

        horizontalLayout_2->addWidget(changeS_btn);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_8->addWidget(Option, 2, 2, 2, 1);

        sell_Box = new QGroupBox(Storage);
        sell_Box->setObjectName(QString::fromUtf8("sell_Box"));
        gridLayout_6 = new QGridLayout(sell_Box);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        sell_elCof_check = new QCheckBox(sell_Box);
        sell_elCof_check->setObjectName(QString::fromUtf8("sell_elCof_check"));

        verticalLayout_7->addWidget(sell_elCof_check);

        sell_elBl_check = new QCheckBox(sell_Box);
        sell_elBl_check->setObjectName(QString::fromUtf8("sell_elBl_check"));

        verticalLayout_7->addWidget(sell_elBl_check);

        sell_elMyasoR_check = new QCheckBox(sell_Box);
        sell_elMyasoR_check->setObjectName(QString::fromUtf8("sell_elMyasoR_check"));

        verticalLayout_7->addWidget(sell_elMyasoR_check);


        verticalLayout_8->addLayout(verticalLayout_7);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_6);

        menu_btn = new QPushButton(sell_Box);
        menu_btn->setObjectName(QString::fromUtf8("menu_btn"));

        horizontalLayout_13->addWidget(menu_btn);

        sell_Btn = new QPushButton(sell_Box);
        sell_Btn->setObjectName(QString::fromUtf8("sell_Btn"));

        horizontalLayout_13->addWidget(sell_Btn);


        verticalLayout_8->addLayout(horizontalLayout_13);


        gridLayout_6->addLayout(verticalLayout_8, 0, 0, 1, 1);


        gridLayout_8->addWidget(sell_Box, 3, 0, 1, 1);


        retranslateUi(Storage);

        QMetaObject::connectSlotsByName(Storage);
    } // setupUi

    void retranslateUi(QDialog *Storage)
    {
        Storage->setWindowTitle(QCoreApplication::translate("Storage", "Dialog", nullptr));
        infoSupp->setTitle(QCoreApplication::translate("Storage", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("Storage", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217:", nullptr));
        lastname->setText(QString());
        label_6->setText(QCoreApplication::translate("Storage", "    \320\230\320\274\321\217:     ", nullptr));
        name->setText(QString());
        label_7->setText(QCoreApplication::translate("Storage", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276:", nullptr));
        patronymic->setText(QString());
        label_8->setText(QCoreApplication::translate("Storage", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260:", nullptr));
        phone->setText(QString());
        pushButton->setText(QCoreApplication::translate("Storage", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        CountKitSup->setTitle(QCoreApplication::translate("Storage", "\320\243\321\201\321\202\320\260\320\275\320\260\320\262\320\273\320\270\320\262\320\260\320\265\320\274 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\272\320\276\320\274\320\277\320\273\320\265\320\272\321\202\320\276\320\262 \320\264\320\265\321\202\320\260\320\273\320\265\320\271", nullptr));
        Spin_label->setText(QCoreApplication::translate("Storage", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\320\262\320\276:", nullptr));
        total_cost_ordered_kits->setText(QCoreApplication::translate("Storage", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \321\201\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        total_cost_ordered_kits_label->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("Storage", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        countKit_Btn->setText(QCoreApplication::translate("Storage", "OK", nullptr));
        condition_sklad->setTitle(QCoreApplication::translate("Storage", "\320\241\320\272\320\273\320\260\320\264", nullptr));
        kit_detail->setText(QCoreApplication::translate("Storage", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\264\320\265\321\202\320\260\320\273\320\265\320\271", nullptr));
        kit_product->setText(QCoreApplication::translate("Storage", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\320\276\320\262", nullptr));
        back_Btn->setText(QCoreApplication::translate("Storage", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        kitDetail->setTitle(QCoreApplication::translate("Storage", "\320\227\320\260\320\272\320\260\320\267\320\260\321\202\321\214", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("Storage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">(1) \320\232\320\276\320\274\320\277\320\273\320\265\320\272\321\202 \320\264\320\265\321\202\320\260\320\273\320\265\320\271 \320\264\320\273\321\217 \321\215\320\273\320\265\320\272\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\276\320\271 \320\272\320\276\321\204\320\265\320\274\320\276\320\273\320\272\320\270.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg"
                        " 2';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">(2) \320\232\320\276\320\274\320\277\320\273\320\265\320\272\321\202 \320\264\320\265\321\202\320\260\320\273\320\265\320\271 \320\264\320\273\321\217 \321\215\320\273\320\265\320\272\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\276\320\263\320\276 \320\261\320\273\320\265\320\275\320\264\320\265\321\200\320\260.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">(3) \320\232\320\276\320\274\320\277\320\273\320\265\320\272\321\202 \320\264\320\265\321\202\320\260\320\273\320\265\320\271 \320\264"
                        "\320\273\321\217 \321\215\320\273\320\265\320\272\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\276\320\271 \320\274\321\217\321\201\320\276\321\200\321\203\320\261\320\272\320\270.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">(4) \320\227\320\260\320\272\320\260\320\267\320\260\321\202\321\214 \321\202\321\200\320\270 \320\272\320\276\320\274\320\277\320\273\320\265\320\272\321\202\320\260 \320\264\320\265\321\202\320\260\320\273\320\265\320\271 (1, 2, 3).</span></p></body></html>", nullptr));
        kit_label->setText(QCoreApplication::translate("Storage", "\320\222\320\260\321\210 \320\262\321\213\320\261\320\276\321\200:", nullptr));
        close_2->setText(QCoreApplication::translate("Storage", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        kit_btn->setText(QCoreApplication::translate("Storage", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
        sellProduct_Box->setTitle(QCoreApplication::translate("Storage", "\320\237\321\200\320\276\320\264\320\260\321\202\321\214 \320\242\320\276\320\262\320\260\321\200", nullptr));
        Cof_label->setText(QCoreApplication::translate("Storage", "\320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\232\320\276\321\204\320\265\320\274\320\276\320\273\320\276\320\272:", nullptr));
        MyasoR_label->setText(QCoreApplication::translate("Storage", "\320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\234\321\217\321\201\320\276\321\200\321\203\320\261\320\276\320\272:", nullptr));
        back_btn->setText(QCoreApplication::translate("Storage", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        sell_product_btn->setText(QCoreApplication::translate("Storage", "\320\236\320\232", nullptr));
        Bl_label->setText(QCoreApplication::translate("Storage", "\320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\221\320\273\320\265\320\275\320\264\320\265\321\200\320\276\320\262:", nullptr));
        total_cost_sell_product->setText(QCoreApplication::translate("Storage", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        total_cost_sell_product_label->setText(QString());
        Option->setTitle(QCoreApplication::translate("Storage", "\320\236\320\277\321\206\320\270\320\270", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("Storage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\222\320\262\320\265\320\264\320\270\321\202\320\265 0 - \320\277\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\244\320\230\320\236 \320\270 \320\275\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\260.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; "
                        "text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\222\320\262\320\265\320\264\320\270\321\202\320\265 1 - \320\277\320\276\320\274\320\265\320\275\321\217\321\202\321\214 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\260, \320\270\320\273\320\270 \320\265\321\201\320\273\320\270 \320\265\320\263\320\276 \320\275\320\265\321\202 \320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\222\320\262\320\265\320\264\320\270"
                        "\321\202\320\265 2 - \321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\260.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\222\320\262\320\265\320\264\320\270\321\202\320\265 3 - \320\267\320\260\320\272\320\260\320\267\320\260\321\202\321\214 \320\272\320\276\320\274\320\277\320\273\320\265\320\272\321\202 \320\264\320\265\321\202\320\260\320\273\320\265\320\271 \321\203 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\260.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; mar"
                        "gin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\222\320\262\320\265\320\264\320\270\321\202\320\265 4 - \320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \321\206\320\265\320\275\321\203 \320\275\320\260 \320\272\320\276\320\274\320\277\320\273\320\265\320\272\321\202 \320\264\320\265\321\202\320\260\320\273\320\265\320\271</span></p></body></html>", nullptr));
        supplierOrKit_label->setText(QCoreApplication::translate("Storage", "\320\222\320\260\321\210 \320\262\321\213\320\261\320\276\321\200:", nullptr));
        close->setText(QCoreApplication::translate("Storage", "\320\234\320\265\320\275\321\216", nullptr));
        changeS_btn->setText(QCoreApplication::translate("Storage", "\320\236\320\232", nullptr));
        sell_Box->setTitle(QCoreApplication::translate("Storage", "\320\222\321\213\320\261\320\276\321\200 \320\277\321\200\320\276\320\264\320\260\320\266\320\270", nullptr));
        sell_elCof_check->setText(QCoreApplication::translate("Storage", "\320\237\321\200\320\276\320\264\320\260\321\202\321\214 \320\255\320\273. \320\232\320\276\321\204\320\265\320\274\320\276\320\273\320\272\321\203", nullptr));
        sell_elBl_check->setText(QCoreApplication::translate("Storage", "\320\237\321\200\320\276\320\264\320\260\321\202\321\214 \320\255\320\273. \320\221\320\273\320\265\320\275\320\264\320\265\321\200", nullptr));
        sell_elMyasoR_check->setText(QCoreApplication::translate("Storage", "\320\237\321\200\320\276\320\264\320\260\321\202\321\214 \320\255\320\273. \320\234\321\217\321\201\320\276\321\200\321\203\320\261\320\272\321\203", nullptr));
        menu_btn->setText(QCoreApplication::translate("Storage", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        sell_Btn->setText(QCoreApplication::translate("Storage", "\320\236\320\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Storage: public Ui_Storage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STORAGE_H
