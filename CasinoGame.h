#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CasinoGame.h"
#include "Blackjack.h"

class CasinoGame : public QMainWindow
{
	Q_OBJECT

public:
	CasinoGame(QWidget *parent = Q_NULLPTR);
	~CasinoGame() {};

private:
	Ui::CasinoGameClass ui;

private slots:
	void loadBlackjack();
};
