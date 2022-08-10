/********************************************************************************
** Form generated from reading UI file 'setuapi.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUAPI_H
#define UI_SETUAPI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setuapiClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *setuapiClass)
    {
        if (setuapiClass->objectName().isEmpty())
            setuapiClass->setObjectName(QString::fromUtf8("setuapiClass"));
        setuapiClass->setWindowModality(Qt::NonModal);
        setuapiClass->resize(742, 572);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/setuapi/tubiao"), QSize(), QIcon::Normal, QIcon::Off);
        setuapiClass->setWindowIcon(icon);
        centralWidget = new QWidget(setuapiClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        spinBox = new QSpinBox(groupBox_3);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(200);

        verticalLayout_3->addWidget(spinBox);


        horizontalLayout->addWidget(groupBox_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);


        horizontalLayout->addWidget(groupBox_2);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setAutoFillBackground(false);
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(true);

        horizontalLayout_4->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        horizontalLayout_4->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        horizontalLayout_4->addWidget(radioButton_3);


        horizontalLayout->addWidget(groupBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);


        verticalLayout->addWidget(widget_2);

        setuapiClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(setuapiClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 742, 23));
        setuapiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(setuapiClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        setuapiClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(setuapiClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        setuapiClass->setStatusBar(statusBar);

        retranslateUi(setuapiClass);

        QMetaObject::connectSlotsByName(setuapiClass);
    } // setupUi

    void retranslateUi(QMainWindow *setuapiClass)
    {
        setuapiClass->setWindowTitle(QCoreApplication::translate("setuapiClass", "\350\211\262\345\233\276\350\216\267\345\217\226\345\231\250", nullptr));
        pushButton->setText(QCoreApplication::translate("setuapiClass", "\351\232\217\346\234\272\350\211\262\345\233\276", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("setuapiClass", "\350\246\201\345\220\257\347\224\250\347\232\204\347\272\277\347\250\213\346\225\260\357\274\232", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("setuapiClass", "\350\246\201\350\216\267\345\217\226\347\232\204\347\261\273\345\236\213\357\274\232", nullptr));
        label_2->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("setuapiClass", "R18\351\200\211\351\241\271", nullptr));
        radioButton->setText(QCoreApplication::translate("setuapiClass", "R18\345\205\263\351\227\255", nullptr));
        radioButton_2->setText(QCoreApplication::translate("setuapiClass", "R18\345\274\200\345\220\257", nullptr));
        radioButton_3->setText(QCoreApplication::translate("setuapiClass", "\346\267\267\345\220\210\346\250\241\345\274\217", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class setuapiClass: public Ui_setuapiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUAPI_H
