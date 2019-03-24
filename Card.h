#include "forCard.h"
#pragma once

class Card
{
public:
	CardRank rank;
	CardSuit suit;
	Card(CardRank rank, CardSuit suit);
	void printCard();
	int getCardValue();
};

