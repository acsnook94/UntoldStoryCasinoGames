#include "CasinoGame.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CasinoGame w;
	w.show();
	return a.exec();
}
