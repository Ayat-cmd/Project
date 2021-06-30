/********************************************************************************
** Form generated from reading UI file 'save_data.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVE_DATA_H
#define UI_SAVE_DATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Save_Data
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_3;
    QLabel *kitProductCost_toFile_label;
    QLineEdit *kitProductCost_toFile_line;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser_3;
    QHBoxLayout *horizontalLayout;
    QLabel *worker_toFile_label;
    QLineEdit *worker_toFile_line;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *textBrowser_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *supCost_toFile_label;
    QLineEdit *supCost_toFile_line;
    QPushButton *to_File_btn;
    QPushButton *to_Menu;

    void setupUi(QDialog *Save_Data)
    {
        if (Save_Data->objectName().isEmpty())
            Save_Data->setObjectName(QString::fromUtf8("Save_Data"));
        Save_Data->resize(290, 535);
        gridLayout = new QGridLayout(Save_Data);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(Save_Data);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 280, 258, 191));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout_3->addWidget(textBrowser);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        kitProductCost_toFile_label = new QLabel(layoutWidget);
        kitProductCost_toFile_label->setObjectName(QString::fromUtf8("kitProductCost_toFile_label"));

        horizontalLayout_3->addWidget(kitProductCost_toFile_label);

        kitProductCost_toFile_line = new QLineEdit(layoutWidget);
        kitProductCost_toFile_line->setObjectName(QString::fromUtf8("kitProductCost_toFile_line"));

        horizontalLayout_3->addWidget(kitProductCost_toFile_line);


        verticalLayout_3->addLayout(horizontalLayout_3);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 20, 258, 119));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser_3 = new QTextBrowser(layoutWidget1);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));

        verticalLayout->addWidget(textBrowser_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        worker_toFile_label = new QLabel(layoutWidget1);
        worker_toFile_label->setObjectName(QString::fromUtf8("worker_toFile_label"));

        horizontalLayout->addWidget(worker_toFile_label);

        worker_toFile_line = new QLineEdit(layoutWidget1);
        worker_toFile_line->setObjectName(QString::fromUtf8("worker_toFile_line"));

        horizontalLayout->addWidget(worker_toFile_line);


        verticalLayout->addLayout(horizontalLayout);

        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 150, 258, 119));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        textBrowser_2 = new QTextBrowser(layoutWidget2);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));

        verticalLayout_2->addWidget(textBrowser_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        supCost_toFile_label = new QLabel(layoutWidget2);
        supCost_toFile_label->setObjectName(QString::fromUtf8("supCost_toFile_label"));

        horizontalLayout_2->addWidget(supCost_toFile_label);

        supCost_toFile_line = new QLineEdit(layoutWidget2);
        supCost_toFile_line->setObjectName(QString::fromUtf8("supCost_toFile_line"));

        horizontalLayout_2->addWidget(supCost_toFile_line);


        verticalLayout_2->addLayout(horizontalLayout_2);

        to_File_btn = new QPushButton(groupBox);
        to_File_btn->setObjectName(QString::fromUtf8("to_File_btn"));
        to_File_btn->setGeometry(QRect(170, 480, 80, 25));
        to_Menu = new QPushButton(groupBox);
        to_Menu->setObjectName(QString::fromUtf8("to_Menu"));
        to_Menu->setGeometry(QRect(80, 480, 80, 25));

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(Save_Data);

        QMetaObject::connectSlotsByName(Save_Data);
    } // setupUi

    void retranslateUi(QDialog *Save_Data)
    {
        Save_Data->setWindowTitle(QCoreApplication::translate("Save_Data", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Save_Data", "\320\241\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Save_Data", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260 (\320\277\321\203\321\202\321\214 \320\272 \321\204\320\260\320\271\320\273\321\203) \320\264\320\273\321\217 \320\267\320\260\320\277\320\270\321\201\320\270:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">1)\320\232"
                        "\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\260 \320\272\320\276\320\274\320\273\320\265\320\272\321\202\320\276\320\262 \320\264\320\265\321\202\320\260\320\273\320\265\320\271 \320\264\320\273\321\217 \321\201\320\261\320\276\321\200\320\272\320\270 \320\261\321\213\321\202\320\276\320\262\320\276\320\271 \321\202\320\265\321\205\320\275\320\270\320\272\320\270 \321\205\321\200\320\276\320\275\321\217\321\211\320\270\321\205\321\201\321\217 \320\275\320\260 \321\201\320\272\320\273\320\260\320\264\320\265.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">2)\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\260 \320\263\320\276\321\202\320\276\320\262\320\276\320\263\320\276 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\320\260 \320\261\321\213\321\202\320\276\320\262\320\276\320\271 \321\202\320\265\321\205\320\275\320"
                        "\270\320\272\320\270 \321\205\321\200\320\276\320\275\321\217\321\211\320\270\321\205\321\201\321\217 \320\275\320\260 \321\201\320\272\320\273\320\260\320\264\320\265.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">3)\320\246\320\265\320\275\321\213 \320\275\320\260 \320\263\320\276\321\202\320\276\320\262\321\213\320\271 \320\277\321\200\320\276\320\264\321\203\320\272\321\202 \320\261\321\213\321\202\320\276\320\262\320\276\320\271 \321\202\320\265\321\205\320\275\320\270\320\272\320\270. </span></p></body></html>", nullptr));
        kitProductCost_toFile_label->setText(QCoreApplication::translate("Save_Data", "\320\237\321\203\321\202\321\214 \320\272 \321\204\320\260\320\271\320\273\321\203:", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("Save_Data", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\235\320\220\320\227\320\222\320\220\320\235\320\230\320\225 \320\244\320\220\320\231\320\233\320\220 \320\224\320\233\320\257 \320\227\320\220\320\237\320\230\320\241\320\230 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\276\320\262</span></p></body></html>", nullptr));
        worker_toFile_label->setText(QCoreApplication::translate("Save_Data", "<html><head/><body><p>\320\237\320\243\320\242\320\254 \320\232 \320\244\320\220\320\231\320\233\320\243:</p></body></html>", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("Save_Data", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\235\320\220\320\227\320\222\320\220\320\235\320\230\320\225 \320\244\320\220\320\231\320\233\320\220 \320\224\320\233\320\257 \320\227\320\220\320\237\320\230\320\241\320\230 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\260 \320\270 \321\206\320\265\320\275\321\213 \320\275\320\260 \320\272\320\276\320\274\320\273\320\265\320\272\321\202 \320\264\320\265\321\202\320\260\320\273\320\265\320\271</span></p></body></html"
                        ">", nullptr));
        supCost_toFile_label->setText(QCoreApplication::translate("Save_Data", "\320\237\320\243\320\242\320\254 \320\232 \320\244\320\220\320\231\320\233\320\243:", nullptr));
        to_File_btn->setText(QCoreApplication::translate("Save_Data", "OK", nullptr));
        to_Menu->setText(QCoreApplication::translate("Save_Data", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Save_Data: public Ui_Save_Data {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVE_DATA_H
