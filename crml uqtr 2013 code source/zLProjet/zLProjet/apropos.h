/** apropos.h    ******************/
/**
** Auteur : Marouane El Gharniti
** 
** CRML UQTR Stage 2013
**
** Library Qt5.1
**
***********************************/

#ifndef APROPOS_H
#define APROPOS_H

#include <QDialog>
#include "ui_apropos.h"

class APropos : public QDialog
{
	Q_OBJECT

public:
	APropos(QWidget *parent = 0);
	~APropos();

private slots:
	void on_btnFermer_clicked();
private:
	Ui::APropos ui;
};

#endif // APROPOS_H
