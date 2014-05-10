/********************************************************************************
** Form generated from reading UI file 'zlprojet.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZLPROJET_H
#define UI_ZLPROJET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_zLProjetClass
{
public:
    QAction *action_Ouvrir;
    QAction *action_Quitter;
    QAction *actionAid_e;
    QAction *action_propos;
    QAction *action_Calcul_la_surface;
    QAction *action_Effacer_la_liste_des_images;
    QAction *actionExporter_r_sultat;
    QAction *actionMettreAEchelle;
    QWidget *centralWidget;
    QPushButton *btnOuvrir;
    QLabel *label1;
    QComboBox *comboBoxlsImg;
    QPushButton *btnCalcul;
    QPushButton *btnExporter;
    QTableView *tableView;
    QLabel *imgLabel;
    QMenuBar *menuBar;
    QMenu *menu_Fichier;
    QMenu *menuAid_e;
    QMenu *menuOutils;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *zLProjetClass)
    {
        if (zLProjetClass->objectName().isEmpty())
            zLProjetClass->setObjectName(QStringLiteral("zLProjetClass"));
        zLProjetClass->resize(800, 600);
        zLProjetClass->setMinimumSize(QSize(800, 600));
        zLProjetClass->setMaximumSize(QSize(800, 600));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../../zlicon48.ico"), QSize(), QIcon::Normal, QIcon::Off);
        zLProjetClass->setWindowIcon(icon);
        action_Ouvrir = new QAction(zLProjetClass);
        action_Ouvrir->setObjectName(QStringLiteral("action_Ouvrir"));
        action_Quitter = new QAction(zLProjetClass);
        action_Quitter->setObjectName(QStringLiteral("action_Quitter"));
        actionAid_e = new QAction(zLProjetClass);
        actionAid_e->setObjectName(QStringLiteral("actionAid_e"));
        action_propos = new QAction(zLProjetClass);
        action_propos->setObjectName(QStringLiteral("action_propos"));
        action_Calcul_la_surface = new QAction(zLProjetClass);
        action_Calcul_la_surface->setObjectName(QStringLiteral("action_Calcul_la_surface"));
        action_Effacer_la_liste_des_images = new QAction(zLProjetClass);
        action_Effacer_la_liste_des_images->setObjectName(QStringLiteral("action_Effacer_la_liste_des_images"));
        actionExporter_r_sultat = new QAction(zLProjetClass);
        actionExporter_r_sultat->setObjectName(QStringLiteral("actionExporter_r_sultat"));
        actionMettreAEchelle = new QAction(zLProjetClass);
        actionMettreAEchelle->setObjectName(QStringLiteral("actionMettreAEchelle"));
        centralWidget = new QWidget(zLProjetClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnOuvrir = new QPushButton(centralWidget);
        btnOuvrir->setObjectName(QStringLiteral("btnOuvrir"));
        btnOuvrir->setGeometry(QRect(480, 500, 101, 41));
        label1 = new QLabel(centralWidget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(10, 510, 101, 16));
        QFont font;
        font.setFamily(QStringLiteral("Verdana"));
        label1->setFont(font);
        comboBoxlsImg = new QComboBox(centralWidget);
        comboBoxlsImg->setObjectName(QStringLiteral("comboBoxlsImg"));
        comboBoxlsImg->setGeometry(QRect(120, 510, 231, 22));
        comboBoxlsImg->setFrame(true);
        btnCalcul = new QPushButton(centralWidget);
        btnCalcul->setObjectName(QStringLiteral("btnCalcul"));
        btnCalcul->setGeometry(QRect(630, 460, 161, 41));
        btnExporter = new QPushButton(centralWidget);
        btnExporter->setObjectName(QStringLiteral("btnExporter"));
        btnExporter->setGeometry(QRect(630, 510, 161, 31));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(590, 10, 201, 441));
        imgLabel = new QLabel(centralWidget);
        imgLabel->setObjectName(QStringLiteral("imgLabel"));
        imgLabel->setGeometry(QRect(10, 10, 571, 471));
        imgLabel->setLayoutDirection(Qt::LeftToRight);
        imgLabel->setFrameShape(QFrame::Box);
        imgLabel->setFrameShadow(QFrame::Sunken);
        imgLabel->setTextFormat(Qt::AutoText);
        imgLabel->setAlignment(Qt::AlignCenter);
        zLProjetClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(zLProjetClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menu_Fichier = new QMenu(menuBar);
        menu_Fichier->setObjectName(QStringLiteral("menu_Fichier"));
        menuAid_e = new QMenu(menuBar);
        menuAid_e->setObjectName(QStringLiteral("menuAid_e"));
        menuOutils = new QMenu(menuBar);
        menuOutils->setObjectName(QStringLiteral("menuOutils"));
        zLProjetClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(zLProjetClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        zLProjetClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(zLProjetClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        zLProjetClass->setStatusBar(statusBar);

        menuBar->addAction(menu_Fichier->menuAction());
        menuBar->addAction(menuOutils->menuAction());
        menuBar->addAction(menuAid_e->menuAction());
        menu_Fichier->addAction(action_Ouvrir);
        menu_Fichier->addAction(actionExporter_r_sultat);
        menu_Fichier->addAction(action_Quitter);
        menuAid_e->addAction(actionAid_e);
        menuAid_e->addAction(action_propos);
        menuOutils->addAction(action_Calcul_la_surface);
        menuOutils->addAction(actionMettreAEchelle);
        menuOutils->addAction(action_Effacer_la_liste_des_images);

        retranslateUi(zLProjetClass);

        comboBoxlsImg->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(zLProjetClass);
    } // setupUi

    void retranslateUi(QMainWindow *zLProjetClass)
    {
        zLProjetClass->setWindowTitle(QApplication::translate("zLProjetClass", "D\303\251tection et mesure de la zone de lyse", 0));
        action_Ouvrir->setText(QApplication::translate("zLProjetClass", "&Ouvrir", 0));
        action_Ouvrir->setShortcut(QApplication::translate("zLProjetClass", "Ctrl+O", 0));
        action_Quitter->setText(QApplication::translate("zLProjetClass", "&Quitter", 0));
        action_Quitter->setShortcut(QApplication::translate("zLProjetClass", "Ctrl+Q", 0));
        actionAid_e->setText(QApplication::translate("zLProjetClass", "A&ide", 0));
        actionAid_e->setShortcut(QApplication::translate("zLProjetClass", "F1", 0));
        action_propos->setText(QApplication::translate("zLProjetClass", "\303\200 &propos", 0));
        action_Calcul_la_surface->setText(QApplication::translate("zLProjetClass", "&Calculer la surface", 0));
        action_Calcul_la_surface->setShortcut(QApplication::translate("zLProjetClass", "Ctrl+M", 0));
        action_Effacer_la_liste_des_images->setText(QApplication::translate("zLProjetClass", "&Effacer la liste des images", 0));
        action_Effacer_la_liste_des_images->setShortcut(QApplication::translate("zLProjetClass", "Ctrl+E", 0));
        actionExporter_r_sultat->setText(QApplication::translate("zLProjetClass", "Exporter le &r\303\251sultat", 0));
        actionExporter_r_sultat->setShortcut(QApplication::translate("zLProjetClass", "Ctrl+S", 0));
        actionMettreAEchelle->setText(QApplication::translate("zLProjetClass", "&Mettre \303\240 l'\303\251chelle", 0));
        actionMettreAEchelle->setShortcut(QApplication::translate("zLProjetClass", "Ctrl+R", 0));
        btnOuvrir->setText(QApplication::translate("zLProjetClass", "Ouvrir", 0));
        btnOuvrir->setShortcut(QApplication::translate("zLProjetClass", "Ctrl+O", 0));
        label1->setText(QApplication::translate("zLProjetClass", "Liste des images", 0));
        btnCalcul->setText(QApplication::translate("zLProjetClass", "Calculer la surface", 0));
        btnCalcul->setShortcut(QApplication::translate("zLProjetClass", "Ctrl+M", 0));
        btnExporter->setText(QApplication::translate("zLProjetClass", "Exporter le r\303\251sultat", 0));
        btnExporter->setShortcut(QApplication::translate("zLProjetClass", "Ctrl+S", 0));
        imgLabel->setText(QApplication::translate("zLProjetClass", "Cliquer sur le bouton Ouvrir pour ajouter une ou plusieurs images", 0));
        menu_Fichier->setTitle(QApplication::translate("zLProjetClass", "&Fichier", 0));
        menuAid_e->setTitle(QApplication::translate("zLProjetClass", "Aid&e", 0));
        menuOutils->setTitle(QApplication::translate("zLProjetClass", "&Outils", 0));
    } // retranslateUi

};

namespace Ui {
    class zLProjetClass: public Ui_zLProjetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZLPROJET_H
