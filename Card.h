#pragma once

enum Suit
{
	Heart = 'H',
	Diamond = 'D',
	Club = 'C',
	Spade = 'S'
};

struct Card
{
	const char* value;
	Suit suit;
	
	Card() {};
	Card(const char* val, Suit suit) { this->value = val; this->suit = suit; }
};