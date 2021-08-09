/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Qdialog
{
public:

    void setupUi(QDialog *Qdialog)
    {
        if (Qdialog->objectName().isEmpty())
            Qdialog->setObjectName(QString::fromUtf8("Qdialog"));
        Qdialog->resize(800, 600);

        retranslateUi(Qdialog);

        QMetaObject::connectSlotsByName(Qdialog);
    } // setupUi

    void retranslateUi(QDialog *Qdialog)
    {
        Qdialog->setWindowTitle(QApplication::translate("Qdialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qdialog: public Ui_Qdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
