#include "forCard.h"
#include "Card.h"
#include <iostream>

using namespace std;

Card::Card(CardRank rank, CardSuit suit) {
	this->rank = rank;
	this->suit = suit;
}

void Card::printCard() {
	switch (this->rank) {
	case RANK_2:  cout << '2'; break;
	case RANK_3:  cout << '3'; break;
	case RANK_4:  cout << '4'; break;
	case RANK_5:  cout << '5'; break;
	case RANK_6:  cout << '6'; break;
	case RANK_7:  cout << '7'; break;
	case RANK_8:  cout << '8'; break;
	case RANK_9:  cout << '9'; break;
	case RANK_10:  cout << 'T'; break;
	case RANK_JACK:  cout << 'J'; break;
	case RANK_QUEEN: cout << 'Q'; break;
	case RANK_KING:  cout << 'K'; break;
	case RANK_ACE:  cout << 'A'; break;
	}

	switch (this->suit) {
	case SUIT_CLUB:  cout << 'C'; break;
	case SUIT_DIAMOND: cout << 'D'; break;
	case SUIT_HEART: cout << 'H'; break;
	case SUIT_SPADE: cout << 'S'; break;
	}
}

int Card::getCardValue() {
		if ((this->rank == RANK_JACK) || (this->rank == RANK_QUEEN) || (this->rank == RANK_KING)) {
			return 10;
		}
		else if ((this->rank == RANK_ACE)) {
			return 11;
		}
		else {
			return this->rank + 2;
		}
}

