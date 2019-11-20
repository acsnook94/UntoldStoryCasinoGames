#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainMenu.h"
#include "Blackjack.h"

class MainMenu : public QMainWindow
{
	Q_OBJECT

public:
	MainMenu(QWidget *parent = Q_NULLPTR);
	~MainMenu() {};

private:
	Ui::MainMenu ui;

private slots:
	void loadBlackjack();
};
