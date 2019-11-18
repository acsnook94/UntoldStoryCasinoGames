#include "CasinoGame.h"

CasinoGame::CasinoGame(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void CasinoGame::startBlackjack()
{
	/*Blackjack* bj = new Blackjack(this); 
	bj->setAttribute(Qt::WA_DeleteOnClose);
	bj->show(); */
	Blackjack bj;
	bj.exec();
}
