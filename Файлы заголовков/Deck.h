#pragma once
#include  "Card.h"
#include "forCard.h"
#include <vector>
#include <iostream>

using namespace std;

const int DECK_SIZE = 52;

class Deck
{
public:
	vector<Card *> *plaersDeck = new vector<Card *>();
	vector<Card *> *dillersDeck = new vector<Card *>();
	vector<Card *> *deckOfCard = new vector<Card *>();
	Deck();
	void swapCard(int index1, int index2);
	void printDeck();
	int getDdeckValue(vector<Card *>  *lastdeck);
	void play();
};

