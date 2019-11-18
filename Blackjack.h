#pragma once

#include <QDialog>
#include "ui_Blackjack.h"

class Blackjack : public QDialog
{
	Q_OBJECT

public:
	Blackjack(QWidget *parent = Q_NULLPTR);
	~Blackjack() {};

private:
	Ui::Blackjack ui;
};
