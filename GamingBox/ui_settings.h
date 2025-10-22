/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QDialogButtonBox *buttonBox;
    QDialogButtonBox *buttonBox_2;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QFrame *line;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName("Settings");
        Settings->resize(400, 300);
        buttonBox = new QDialogButtonBox(Settings);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(50, 260, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Ok);
        buttonBox->setCenterButtons(false);
        buttonBox_2 = new QDialogButtonBox(Settings);
        buttonBox_2->setObjectName("buttonBox_2");
        buttonBox_2->setGeometry(QRect(10, 260, 341, 32));
        buttonBox_2->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        buttonBox_2->setOrientation(Qt::Orientation::Horizontal);
        buttonBox_2->setStandardButtons(QDialogButtonBox::StandardButton::Save);
        buttonBox_2->setCenterButtons(false);
        groupBox = new QGroupBox(Settings);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 120, 381, 121));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(290, 90, 80, 23));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(200, 90, 80, 23));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 30, 361, 51));
        line = new QFrame(Settings);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 240, 401, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        groupBox_2 = new QGroupBox(Settings);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 0, 151, 121));
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(10, 20, 81, 20));
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(10, 40, 81, 20));
        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setGeometry(QRect(10, 60, 81, 20));
        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName("checkBox_4");
        checkBox_4->setGeometry(QRect(10, 80, 81, 20));
        groupBox_3 = new QGroupBox(Settings);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(170, 0, 221, 121));
        groupBox_4 = new QGroupBox(groupBox_3);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(10, 60, 201, 51));
        checkBox_5 = new QCheckBox(groupBox_3);
        checkBox_5->setObjectName("checkBox_5");
        checkBox_5->setGeometry(QRect(10, 20, 81, 20));
        checkBox_6 = new QCheckBox(groupBox_3);
        checkBox_6->setObjectName("checkBox_6");
        checkBox_6->setGeometry(QRect(10, 40, 81, 20));

        retranslateUi(Settings);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Settings, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Settings, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Settings", "License", nullptr));
        pushButton->setText(QCoreApplication::translate("Settings", "Buy", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Settings", "Register", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Settings", "GroupBox", nullptr));
        checkBox->setText(QCoreApplication::translate("Settings", "CheckBox", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Settings", "CheckBox", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Settings", "CheckBox", nullptr));
        checkBox_4->setText(QCoreApplication::translate("Settings", "CheckBox", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Settings", "GroupBox", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Settings", "GroupBox", nullptr));
        checkBox_5->setText(QCoreApplication::translate("Settings", "CheckBox", nullptr));
        checkBox_6->setText(QCoreApplication::translate("Settings", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
