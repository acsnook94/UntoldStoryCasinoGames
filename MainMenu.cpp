#include "MainMenu.h"

MainMenu::MainMenu(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void MainMenu::loadBlackjack()
{
	/*Blackjack* bj = new Blackjack(this); 
	bj->setAttribute(Qt::WA_DeleteOnClose);
	bj->show(); */
	Blackjack bj(this);
	bj.exec();
}
