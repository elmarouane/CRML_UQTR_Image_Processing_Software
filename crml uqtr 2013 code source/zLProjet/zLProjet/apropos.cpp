/** apropos.cpp  ******************/
/**
** Auteur : Marouane El Gharniti
** 
** CRML UQTR Stage 2013
**
** Library Qt5.1
**
***********************************/

#include "apropos.h"

APropos::APropos(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

APropos::~APropos()
{

}

void APropos::on_btnFermer_clicked()
{
	close();
}