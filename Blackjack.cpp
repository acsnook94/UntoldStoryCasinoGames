#include "Blackjack.h"

Blackjack::Blackjack(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	this->runGame();
}

void Blackjack::runGame()
{
	this->numDecks = 3;
	this->numPlayers = 2;
	this->currPlayer = 0;
	this->allHands = new std::vector<Card*>[numPlayers];

	for (int d = 1; d <= this->numDecks; d++)
	{
		for (int i = 0; i < CARDS_PER_DECK; i++)
		{
			this->deck.push_back(const_cast<Card*>(this->allCardTypes) + i);
		}
	}
	
	for (Card*& cardPtr : this->deck)
	{
		ui.txtbOutput->append(QStringLiteral("Value=") + (cardPtr->value) + " Suit=" + (cardPtr->suit));
	}
	

}