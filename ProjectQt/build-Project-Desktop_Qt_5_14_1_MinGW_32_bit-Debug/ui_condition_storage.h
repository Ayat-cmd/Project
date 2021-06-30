/********************************************************************************
** Form generated from reading UI file 'condition_storage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONDITION_STORAGE_H
#define UI_CONDITION_STORAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Condition_Storage
{
public:

    void setupUi(QDialog *Condition_Storage)
    {
        if (Condition_Storage->objectName().isEmpty())
            Condition_Storage->setObjectName(QString::fromUtf8("Condition_Storage"));
        Condition_Storage->resize(782, 509);

        retranslateUi(Condition_Storage);

        QMetaObject::connectSlotsByName(Condition_Storage);
    } // setupUi

    void retranslateUi(QDialog *Condition_Storage)
    {
        Condition_Storage->setWindowTitle(QCoreApplication::translate("Condition_Storage", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Condition_Storage: public Ui_Condition_Storage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONDITION_STORAGE_H
