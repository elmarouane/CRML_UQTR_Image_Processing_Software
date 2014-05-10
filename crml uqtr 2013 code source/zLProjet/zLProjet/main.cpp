#include "zlprojet.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	zLProjet w;
	w.show();
	return a.exec();
}
