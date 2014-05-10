/** zlprojet.cpp ******************/
/**
** Auteur : Marouane El Gharniti
** 
** CRML UQTR Stage 2013
**
** Library Qt5.1
**
***********************************/

#include "tImage.h"
#include "zlprojet.h"


tImage timage;
//Returns the absolute path of the system's temporary directory
//and put it in a QString variable
QString temp_path = QDir::tempPath();
QStringList fileNames, baseNameList, lsImgTraitees;
int radius;
zLProjet::zLProjet(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//this->setWindowTitle("Detection et mesure de la zone de lyse");
	
	radius = 3;
	// Créer un répertoire, ce répertoire est utilisé pour stocker les images
	// finales. Toutes les images sont supprimées à la sortie du logiciel.
    QDir temp = QDir::temp();//Retourne le chemin du répertoire temporaire du système
    temp.mkdir("zlprojet");//créer un répertoire zlprojet dans le répertoire temporaire du système
	
	//add columns to table
	model = new QStandardItemModel(0,2,this);
	model->setHorizontalHeaderItem(0, new QStandardItem(QString("Nom")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Surface de la zone de lyse en mm2")));
	//hide vertical header
	ui.tableView->verticalHeader()->hide();
    ui.tableView->setModel(model);

}

zLProjet::~zLProjet()
{
	deleteFiles();

}


//open files
void zLProjet::open(QStringList namesList)
{
    if (!namesList.isEmpty())
	{
        QImage image(namesList.at(0));
		//Afficher la première image imgLabel et le redimensionner à la taille de imgLabel.
		ui.imgLabel->setPixmap(QPixmap::fromImage(image).scaled(labelSize(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
		QFileInfo fileName;
		QString fn;
		for(int i = 0; i < namesList.count(); ++i)
		{
			fileName = namesList.at(i);
			//garder le nom du fichier sans chemin et extension.
			fn = fileName.baseName();
			baseNameList << fn;
		}
		//Ajouter la liste des images à comboBox
		ui.comboBoxlsImg->addItems(baseNameList);
	}
}

//Mat2QImage() : Convertir le type cv::Mat de l’image traitée par traitementImage au type QImage
QImage zLProjet::Mat2QImage(const cv::Mat3b &src)
{
	QImage dest(src.cols, src.rows, QImage::Format_ARGB32);
	for (int y = 0; y < src.rows; ++y)
	{
		const cv::Vec3b *srcrow = src[y];
		QRgb *destrow = (QRgb*)dest.scanLine(y);
		for (int x = 0; x < src.cols; ++x)
		{
			destrow[x] = qRgba(srcrow[x][2], srcrow[x][1], srcrow[x][0], 255);
		}
	}
	return dest;
}

//addFileNameToTable() : Ajouter le nom de fichier au tableau de résultat 
void zLProjet::addFileNameToTable()
{
	int c = ui.comboBoxlsImg->count();
	for (int i = 0; i < c; ++i)
    {
        model->setItem(i,new QStandardItem(baseNameList.at(i)));
    }
    ui.tableView->setModel(model);
}


//Méthode calculSurface appelle la méthode traitementImage de TImage
void zLProjet::calculSurface()
{
	std::pair<cv::Mat, float> timage_output;
	std::string srcPath;
	cv::Mat src, img_src;
	QImage dst;
	QString path_update;

	int index = fileNames.count();
	// Afficher un message d'avertissement si la liste de fileNames est vide
	if (index == 0)
	{
		QMessageBox msgBox;
		msgBox.setWindowTitle("Avertissement");
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.setText("La liste des images est vide, veuillez ouvrir une ou plusieurs images avant de cliquer sur \"Calcul la surface\"");
		msgBox.exec();
	}
	else
	{
		for( int i = 0; i < index; i++ )
		{
			srcPath = fileNames.at(i).toStdString();//toStdWString()
			//srcPath = ui.comboBoxlsImg->itemText(i).toStdString();
			//image_name_.toAscii().constData()
			src = cv::imread(srcPath);

			timage_output = timage.traitementImage(src, radius);
			model->setItem(i , 1, new QStandardItem(QString::number(timage_output.second)));
			img_src = timage_output.first;
			dst = Mat2QImage( img_src );
			storeImgInDir(dst, i);

			//path of processed images in temp directory
			path_update = QString( temp_path + "/zlprojet/" + baseNameList.at(i) + ".jpg" );
			//add elements to list of string lsImgTraitees
			lsImgTraitees << path_update;
		}
		//clear combobox
		ui.comboBoxlsImg->clear();
		baseNameList.clear();
		fileNames.clear();
		fileNames = lsImgTraitees;
		lsImgTraitees.clear();
		open(fileNames);
		ui.tableView->setModel(model);
		ui.btnOuvrir->setDisabled(true);
		ui.action_Ouvrir->setDisabled(true);
	}
}


//Sauvegarder des images dans un répertoire
//les images sont stockées en format jpg en utilisant 100% de qualité
//ces images sont utilisées pour afficher dans imgLabel
//puisque l'utilisateur ne souhaite pas conserver les images
//toutes les images seront détruites à la sortie du logiciel utilisant deletefiles
void zLProjet::storeImgInDir(QImage img, int index)
{
	QImageWriter imgWriter;
	imgWriter.setFormat("jpg");
	imgWriter.setQuality(100);
	imgWriter.setFileName( temp_path + "/zlprojet/" + baseNameList.at(index) + "." + "jpg" );
	imgWriter.write(img);
}

//Effacer toutes les images dans le répertoire zlprojet
void zLProjet::deleteFiles()
{
	QString pathd = QString( temp_path + "/zlprojet/" );
    QDir dir(pathd);
    dir.setNameFilters(QStringList() << "*.jpg");
    dir.setFilter(QDir::Files);
    for(int i = 0; i<dir.entryList().size();i++){
        dir.remove(dir.entryList().at(i));
    }
}
//get label size
QSize zLProjet::labelSize()
{
    int labelWidth = ui.imgLabel->width();
    int labelHeight = ui.imgLabel->height();
    return QSize(labelWidth, labelHeight);
}

//exporter le resultat vers un fichier csv ou txt
void zLProjet::exporterResultat(QString resfilename)
{
	QFile resfile(resfilename);
    if(!resfile.open(QIODevice::WriteOnly | QIODevice::Text))return;

    QTextStream out(&resfile);
    int r = model->rowCount();
    int c = model->columnCount();
	
	out<<model->horizontalHeaderItem(0)->text()<<","<<model->horizontalHeaderItem(1)->text()<<"\n";
	
    for(int i = 0; i < r; i++)
    {
        for(int j=0; j < c; j++)
        {
            out<<model->item(i,j)->text();
            if(j != c-1) out<<",";
        }
        out<<"\n";
    }
    resfile.close();
}


///menuItem
// Menu Item Fichier->"Ouvrir"
void zLProjet::on_action_Ouvrir_triggered()
{
	
	fileNames = QFileDialog::getOpenFileNames(this, tr("Selectionnez un ou plusieurs fichiers"),
														 "",
														 "Images (*.jpg *.jpeg *.png)");
	open(fileNames);
	addFileNameToTable();
}

//Item Fichier->"Exporter le resultat"
void zLProjet::on_actionExporter_r_sultat_triggered()
{
	QString resfileName = QFileDialog::getSaveFileName(this, tr("Enregistrer sous"),
                               "",
                               tr("Images (*.csv *.txt)"));
    exporterResultat(resfileName);
}
// Menu Item Fichier->"Quitter"
void zLProjet::on_action_Quitter_triggered()
{
	close();
}

// Menu Item Outils->"Calculer la surface"
void zLProjet::on_action_Calcul_surface_triggered()
{
	calculSurface();
}

//// Menu Item Outils->"Metter à l'échelle"
void zLProjet::on_actionMettreAEchelle_triggered()
{
	radius = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
                                       tr("Choisir le rayon du disque de papier bioactif:"), 3, 1, 1000);
}

// Menu Item Outils->"Effacer la liste des images"
void zLProjet::on_action_Effacer_la_liste_des_images_triggered()
{
	ui.comboBoxlsImg->clear();
	fileNames.clear();
	baseNameList.clear();
	lsImgTraitees.clear();
	int rowcount = model->rowCount();
	for(int i = 0; i < rowcount; i++)
		model->removeRow(i);
	
	ui.tableView->setModel(model);
	ui.imgLabel->clear();
	deleteFiles();
	ui.btnOuvrir->setEnabled(true);
	ui.action_Ouvrir->setEnabled(true);
}
// Menu Item Aide->"Aide"
void zLProjet::on_actionAid_e_triggered()
{
	QUrl url = QUrl::fromLocalFile("aide.pdf");
	QDesktopServices::openUrl(url);
}

// Menu Item Aide->"A propos"
void zLProjet::on_action_propos_triggered()
{
	APropos apropos;
	apropos.setModal(true);
	apropos.exec();
}

/// Buttons
// button "Ouvrir"
void zLProjet::on_btnOuvrir_clicked()
{
	fileNames = QFileDialog::getOpenFileNames(this, tr("Selectionnez un ou plusieurs fichiers"),
														 "",
														 "Images (*.jpg *.jpeg *.png)");
	open(fileNames);
	addFileNameToTable();
}

// Button "Calculer la surface"
void zLProjet::on_btnCalcul_clicked()
{
	calculSurface();
}

// Button "Exporter le resultat"
void zLProjet::on_btnExporter_clicked()
{
	QString resfileName = QFileDialog::getSaveFileName(this, tr("Enregistrer sous"),
                               "",
                               tr("Images (*.csv *.txt)"));
    exporterResultat(resfileName);
}

// comboBox
void zLProjet::on_comboBoxlsImg_activated(int index)
{
	QImage image(fileNames.at(index));
	//show image in imgLabel and scale it to the size of the label
    ui.imgLabel->setPixmap(QPixmap::fromImage(image).scaled(labelSize(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}


