/********************************************************************************
** Form generated from reading UI file 'apropos.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APROPOS_H
#define UI_APROPOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_APropos
{
public:
    QPushButton *btnFermer;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label;

    void setupUi(QDialog *APropos)
    {
        if (APropos->objectName().isEmpty())
            APropos->setObjectName(QStringLiteral("APropos"));
        APropos->resize(483, 331);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../../zlicon48.ico"), QSize(), QIcon::Normal, QIcon::Off);
        APropos->setWindowIcon(icon);
        btnFermer = new QPushButton(APropos);
        btnFermer->setObjectName(QStringLiteral("btnFermer"));
        btnFermer->setGeometry(QRect(390, 298, 81, 23));
        plainTextEdit = new QPlainTextEdit(APropos);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 98, 461, 191));
        plainTextEdit->setReadOnly(true);
        plainTextEdit_2 = new QPlainTextEdit(APropos);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(10, 8, 461, 41));
        plainTextEdit_2->setReadOnly(true);
        label = new QLabel(APropos);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 60, 501, 31));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        retranslateUi(APropos);

        QMetaObject::connectSlotsByName(APropos);
    } // setupUi

    void retranslateUi(QDialog *APropos)
    {
        APropos->setWindowTitle(QApplication::translate("APropos", "APropos", 0));
        btnFermer->setText(QApplication::translate("APropos", "Fermer", 0));
        plainTextEdit->setPlainText(QApplication::translate("APropos", "D\303\251velopp\303\251 par:\n"
"	Marouane El Gharniti\n"
"	zlprojet@elgharniti.com\n"
"\n"
"\n"
"D\303\251velopp\303\251 pour le Centre de Recherche sur les Mat\303\251riaux Lignocellulosiques\n"
"Universit\303\251 du Qu\303\251bec \303\240 Trois-Rivi\303\250res (UQTR)\n"
"\n"
"\n"
"Vous utilisez l'interface Qt5.1", 0));
        plainTextEdit_2->setPlainText(QApplication::translate("APropos", "D\303\251tection et mesure de la zone de lyse dans une image.\n"
"", 0));
        label->setText(QApplication::translate("APropos", "Version 1.0 (2013.08)", 0));
    } // retranslateUi

};

namespace Ui {
    class APropos: public Ui_APropos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APROPOS_H
