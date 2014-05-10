/** zlprojet.h ******************/
/**
** Auteur : Marouane El Gharniti
** 
** CRML UQTR Stage 2013
**
** Library Qt5.1
**
***********************************/

#ifndef ZLPROJET_H
#define ZLPROJET_H


#include <QtWidgets/QMainWindow>
#include "ui_zlprojet.h"
#include "qstandarditemmodel.h"
#include <opencv\cv.h>

#include "qimage.h"
#include "apropos.h"
#include "qstandarditemmodel.h"
#include "qfiledialog.h"
#include "qmessagebox.h"
#include "qstringlistmodel.h"
#include "qdir.h"
#include "qimagewriter.h"
#include "qtextstream.h"
#include "qinputdialog.h"
#include "qurl.h"
#include "qdesktopservices.h"
#include <String>
#include <stdio.h>


class zLProjet : public QMainWindow
{
	Q_OBJECT

public:
	zLProjet(QWidget *parent = 0);
	~zLProjet();


private slots:
	//menu items
	void on_action_Ouvrir_triggered();
	void on_actionExporter_r_sultat_triggered();
	void on_action_Quitter_triggered();
	void on_action_Calcul_surface_triggered();
	void on_actionMettreAEchelle_triggered();
	void on_action_Effacer_la_liste_des_images_triggered();
	void on_actionAid_e_triggered();
	void on_action_propos_triggered();
	//button
	void on_btnOuvrir_clicked();
	void on_btnCalcul_clicked();
	void on_btnExporter_clicked();
	//comboBox
	void on_comboBoxlsImg_activated(int);
	
	//open
	void open(QStringList);
	
	//Convertir le type cv::Mat de l’image traitée par traitementImage au type QImage
	QImage Mat2QImage(const cv::Mat3b &);
	
	//get label size
	QSize labelSize();
	
	//Ajouter le nom de fichier au tableau de résultat
	void addFileNameToTable();
	
	//Méthode calculSurface appelle la méthode traitementImage de TImage
	void calculSurface();
	
	//Sauvegarder des images dans un répertoire
	void storeImgInDir(QImage, int);

	//Effacer toutes les images dans le répertoire zlprojet
	void deleteFiles();

	//Exporter le resultat vers un fichier csv ou txt
	void exporterResultat(QString);


private:
	Ui::zLProjetClass ui;
	QStandardItemModel *model;
};

#endif // ZLPROJET_H
