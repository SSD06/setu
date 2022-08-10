/********************************************************************************
** Form generated from reading UI file 'Widget1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET1_H
#define UI_WIDGET1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget1class
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *Widget1class)
    {
        if (Widget1class->objectName().isEmpty())
            Widget1class->setObjectName(QString::fromUtf8("Widget1class"));
        Widget1class->resize(493, 366);
        pushButton = new QPushButton(Widget1class);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 220, 75, 23));

        retranslateUi(Widget1class);
        QObject::connect(pushButton, SIGNAL(clicked()), Widget1class, SLOT(close()));

        QMetaObject::connectSlotsByName(Widget1class);
    } // setupUi

    void retranslateUi(QWidget *Widget1class)
    {
        Widget1class->setWindowTitle(QCoreApplication::translate("Widget1class", "\345\260\217\350\200\201\345\274\237", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget1class", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget1class: public Ui_Widget1class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET1_H
