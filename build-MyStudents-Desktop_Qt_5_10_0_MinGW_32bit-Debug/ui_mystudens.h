/********************************************************************************
** Form generated from reading UI file 'mystudens.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSTUDENS_H
#define UI_MYSTUDENS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyStudens
{
public:
    QListWidget *listWidget;
    QLabel *studentName;
    QLabel *studentDOB;
    QLabel *studentClass;

    void setupUi(QWidget *MyStudens)
    {
        if (MyStudens->objectName().isEmpty())
            MyStudens->setObjectName(QStringLiteral("MyStudens"));
        MyStudens->resize(754, 360);
        listWidget = new QListWidget(MyStudens);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(40, 160, 701, 192));
        studentName = new QLabel(MyStudens);
        studentName->setObjectName(QStringLiteral("studentName"));
        studentName->setGeometry(QRect(30, 40, 171, 31));
        studentDOB = new QLabel(MyStudens);
        studentDOB->setObjectName(QStringLiteral("studentDOB"));
        studentDOB->setGeometry(QRect(250, 40, 141, 31));
        studentClass = new QLabel(MyStudens);
        studentClass->setObjectName(QStringLiteral("studentClass"));
        studentClass->setGeometry(QRect(540, 30, 141, 31));

        retranslateUi(MyStudens);

        QMetaObject::connectSlotsByName(MyStudens);
    } // setupUi

    void retranslateUi(QWidget *MyStudens)
    {
        MyStudens->setWindowTitle(QApplication::translate("MyStudens", "MyStudens", nullptr));
        studentName->setText(QApplication::translate("MyStudens", "Name", nullptr));
        studentDOB->setText(QApplication::translate("MyStudens", "DOB", nullptr));
        studentClass->setText(QApplication::translate("MyStudens", "Class", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyStudens: public Ui_MyStudens {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSTUDENS_H
