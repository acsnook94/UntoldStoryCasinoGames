#pragma once

#include <QDialog>
#include "ui_Blackjack.h"
#include "Card.h"
#include <vector>

class Blackjack : public QDialog
{
	Q_OBJECT

public:
	Blackjack(QWidget *parent = Q_NULLPTR);
	~Blackjack() { if (this->allHands != nullptr) { delete[] this->allHands; } }

private:
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		/* CLASS FIELDS */
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	const Card allCardTypes[52] =
	{
		Card("2", Heart), Card("2", Diamond), Card("2", Club), Card("2", Spade), Card("3", Heart), Card("3", Diamond), Card("3", Club), Card("3", Spade),
		Card("4", Heart), Card("4", Diamond), Card("4", Club), Card("4", Spade), Card("5", Heart), Card("5", Diamond), Card("5", Club), Card("5", Spade),
		Card("6", Heart), Card("6", Diamond), Card("6", Club), Card("6", Spade), Card("7", Heart), Card("7", Diamond), Card("7", Club), Card("7", Spade),
		Card("8", Heart), Card("8", Diamond), Card("8", Club), Card("8", Spade), Card("9", Heart), Card("9", Diamond), Card("9", Club), Card("9", Spade),
		Card("10", Heart), Card("10", Diamond), Card("10", Club), Card("10", Spade), Card("J", Heart), Card("J", Diamond), Card("J", Club), Card("J", Spade),
		Card("Q", Heart), Card("Q", Diamond), Card("Q", Club), Card("Q", Spade), Card("K", Heart), Card("K", Diamond), Card("K", Club), Card("K", Spade),
		Card("A", Heart), Card("A", Diamond), Card("A", Club), Card("A", Spade)
	};

	std::vector<Card*>* allHands = nullptr;
	std::vector<Card*> deck;
	//Card deck[CARDS_PER_DECK];

	const int CARDS_PER_DECK = 52;
	int numPlayers = 0;
	int numDecks = 0;
	int currPlayer = 0;


	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		/* CLASS METHODS */
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//Non-UI Methods
	void runGame();

	//UI Methods
	Ui::Blackjack ui;

private slots:
	void exitGame() { this->close(); }
};
