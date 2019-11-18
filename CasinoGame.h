#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CasinoGame.h"

class CasinoGame : public QMainWindow
{
	Q_OBJECT

public:
	CasinoGame(QWidget *parent = Q_NULLPTR);

private:
	Ui::CasinoGameClass ui;
};
