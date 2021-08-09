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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QFormLayout *formLayout;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(216, 167);
        formLayout = new QFormLayout(Dialog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setAutoFillBackground(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        spinBox = new QSpinBox(Dialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBox);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        comboBox = new QComboBox(Dialog);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBox);

        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 751));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(5, QFormLayout::FieldRole, buttonBox);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(spinBox);
        label_3->setBuddy(comboBox);
        label->setBuddy(lineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(Dialog);
        QObject::connect(label, SIGNAL(linkHovered(QString)), lineEdit, SLOT(copy()));
        QObject::connect(label_2, SIGNAL(linkActivated(QString)), spinBox, SLOT(stepDown()));
        QObject::connect(label_3, SIGNAL(linkActivated(QString)), comboBox, SLOT(setEditText(QString)));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        label_2->setText(QApplication::translate("Dialog", "\345\271\264\351\276\204(&A)", nullptr));
        label_3->setText(QApplication::translate("Dialog", "\346\260\221\346\227\217(&M)", nullptr));
        comboBox->setItemText(0, QApplication::translate("Dialog", "\346\261\211\346\227\217", nullptr));
        comboBox->setItemText(1, QApplication::translate("Dialog", "\350\222\231\346\227\217", nullptr));

        label->setText(QApplication::translate("Dialog", "\345\247\223\345\220\215(&N)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
