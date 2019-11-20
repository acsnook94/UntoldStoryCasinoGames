#include "Blackjack.h"

Blackjack::Blackjack(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
	
}

void Blackjack::setupGame()
{
	this->numDecks = 1;
	this->numPlayers = 4;
	this->allHands = new std::vector<Card*>[numPlayers];
	this->nextCard = -1;
	srand(time(nullptr));

	//Build combined card deck
	for (int d = 1; d <= this->numDecks; d++)
	{
		for (int i = 0; i < CARDS_PER_DECK; i++)
		{
			this->deck.push_back(const_cast<Card*>(this->allCardTypes) + i);
		}
	}

	for (int i = 0; i < this->numPlayers; i++)
	{
		nextCard = rand() % this->deck.size();
		this->allHands[i].push_back(this->deck.at(nextCard));
		this->deck.erase(this->deck.begin() + nextCard);
	}
	
}