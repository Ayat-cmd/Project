/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actiondark;
    QAction *actionQuit;
    QWidget *centralwidget;
    QGridLayout *gridLayout_15;
    QGroupBox *Menu;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout;
    QLabel *state_menu_label;
    QLineEdit *state_menu;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *option;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(585, 420);
        MainWindow->setMinimumSize(QSize(585, 420));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        actiondark = new QAction(MainWindow);
        actiondark->setObjectName(QString::fromUtf8("actiondark"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_15 = new QGridLayout(centralwidget);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        Menu = new QGroupBox(centralwidget);
        Menu->setObjectName(QString::fromUtf8("Menu"));
        gridLayout_2 = new QGridLayout(Menu);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(Menu);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(Menu);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(Menu);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(Menu);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(Menu);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_6 = new QLabel(Menu);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(Menu);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        label_8 = new QLabel(Menu);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_2->addWidget(label_8);

        label_9 = new QLabel(Menu);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_2->addWidget(label_9);

        label_10 = new QLabel(Menu);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_2->addWidget(label_10);

        label_11 = new QLabel(Menu);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_2->addWidget(label_11);

        label_13 = new QLabel(Menu);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_2->addWidget(label_13);


        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        state_menu_label = new QLabel(Menu);
        state_menu_label->setObjectName(QString::fromUtf8("state_menu_label"));

        horizontalLayout->addWidget(state_menu_label);

        state_menu = new QLineEdit(Menu);
        state_menu->setObjectName(QString::fromUtf8("state_menu"));

        horizontalLayout->addWidget(state_menu);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        option = new QPushButton(Menu);
        option->setObjectName(QString::fromUtf8("option"));

        horizontalLayout_2->addWidget(option);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_15->addWidget(Menu, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 585, 25));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
#if QT_CONFIG(shortcut)
        state_menu_label->setBuddy(state_menu);
#endif // QT_CONFIG(shortcut)

        menubar->addAction(menu->menuAction());
        menu->addSeparator();
        menu->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actiondark->setText(QCoreApplication::translate("MainWindow", "dark", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        Menu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264 \320\270\320\267 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213 - 0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264 \320\275\320\260\321\207\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\260 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\276\320\262 \320\270 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\260 - 1", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\263\320\276 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260 - 2", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272 (\320\227\320\260\320\272\320\260\320\267\320\260\321\202\321\214 \320\272\320\276\320\274\320\273\320\265\320\272\321\202 \320\264\320\265\321\202\320\260\320\273\320\265\320\271, \320\262\321\201\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\260) - 3", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264 \321\201\320\277\320\270\321\201\320\272\320\260 \320\262\321\201\320\265\321\205 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\276\320\262(\320\244\320\230\320\236, \320\275\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260, \320\267\320\277) - 4", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260 - 5", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \321\201\320\272\320\273\320\260\320\264\320\260 - 6", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\321\203\320\272\321\202 \320\261\321\213\321\202\320\276\320\262\320\276\320\271 \321\202\320\265\321\205\320\275\320\270\320\272\320\270(C\320\276\320\261\321\200\320\260\321\202\321\214 \320\277\321\200\320\276\320\264\321\203\320\272\321\202) - 7", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", " \320\243\320\262\320\276\320\273\320\270\321\202\321\214 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260 - 8", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\270\320\265 \320\267\320\260\321\200\320\277\320\273\320\260\321\202\321\213 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260\320\274 \320\270\320\273\320\270 \321\206\320\265\320\275\321\213 \320\275\320\260 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\321\213. \320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \321\206\320\265\320\275 \320\275\320\260 \321\202\320\276\320\262\320\260\321\200\321\213 - 9", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\320\260\321\202\321\214 \321\201\320\276\320\261\321\200\320\260\320\275\320\275\321\213\320\265 \321\202\320\276\320\262\320\260\321\200\321\213 - 10", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265 - 11", nullptr));
        state_menu_label->setText(QCoreApplication::translate("MainWindow", "&\320\222\320\260\321\210 \320\262\321\213\320\261\320\276\321\200:", nullptr));
        option->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
