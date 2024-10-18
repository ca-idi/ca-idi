/********************************************************************************
** Form generated from reading UI file 'mafenetre.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAFENETRE_H
#define UI_MAFENETRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaFenetre
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MaFenetre)
    {
        if (MaFenetre->objectName().isEmpty())
            MaFenetre->setObjectName(QString::fromUtf8("MaFenetre"));
        MaFenetre->resize(800, 600);
        centralwidget = new QWidget(MaFenetre);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MaFenetre->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MaFenetre);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        MaFenetre->setMenuBar(menubar);
        statusbar = new QStatusBar(MaFenetre);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MaFenetre->setStatusBar(statusbar);

        retranslateUi(MaFenetre);

        QMetaObject::connectSlotsByName(MaFenetre);
    } // setupUi

    void retranslateUi(QMainWindow *MaFenetre)
    {
        MaFenetre->setWindowTitle(QCoreApplication::translate("MaFenetre", "MaFenetre", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MaFenetre: public Ui_MaFenetre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAFENETRE_H
