#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CasinoGame.h"
#include "Blackjack.h"

class CasinoGame : public QMainWindow
{
	Q_OBJECT

public:
	CasinoGame(QWidget *parent = Q_NULLPTR);

private slots:
	void startBlackjack();

private:
	Ui::CasinoGameClass ui;
};
