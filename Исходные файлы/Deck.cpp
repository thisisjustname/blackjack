#include  "Card.h"
#include "forCard.h"
#include <vector>
#include "Deck.h"
#include <iostream>
#include <string>


using namespace std;

Deck::Deck() {
	for (int suiteIndex = 0; suiteIndex < MAX_SUITS; suiteIndex++) {
		for (int rankIndex = 0; rankIndex < MAX_RANKS; rankIndex++) {
			CardRank rank = static_cast<CardRank>(rankIndex);
			CardSuit suit = static_cast<CardSuit>(suiteIndex);
			this->deckOfCard->push_back(new Card(rank, suit));
		}
	}
	for (int i = 1; i < 2000; i++) {
		swapCard(rand() % DECK_SIZE, rand() % DECK_SIZE);
	}
}

void Deck::swapCard(int index1, int index2) {
	Card * tmp = (*this->deckOfCard)[index1];
	(*this->deckOfCard)[index1] = (*this->deckOfCard)[index2];
	(*this->deckOfCard)[index2] = tmp;
}

void Deck::printDeck() {
	for (int i = 0; i < DECK_SIZE; i++) {
		Card *card = this->deckOfCard->at(i);
		card->printCard();
		cout << endl;
	}
}

int Deck::getDdeckValue(vector<Card *>  *lastdeck) {
	int count = 0;
	Card *opo;
	bool ace = false;
	int countOfAce = 0;
	for (int i = 0; i < lastdeck->size(); i++) {
		opo = lastdeck->at(i);
		if (opo->rank == RANK_ACE) {
			ace = true;
			countOfAce++;
		}
		count += opo->getCardValue();
	}
	if (ace == true) {
		if (count > 21 && countOfAce > 0) {
			count -= 10;
			if (count > 21 && countOfAce > 1) {
				count -= 10;
				if (count > 21 && countOfAce > 2) {
					count -= 10;
					if (count > 21 && countOfAce > 3) {
						count -= 10;
					}
				}
			}
		}
	}
	return (count);
}

void Deck::play() {
	bool stop = true;
	string ppi;
	bool tyy = false;
	int countOfPlaer = 0;
	int countOfDiller = 0;
	bool error = true;
	int number = 0;

	Card *opo = this->deckOfCard->at(number);
	//opo->rank = RANK_ACE;
	opo->printCard();
	countOfPlaer += opo->getCardValue();
	plaersDeck->push_back(new Card(opo->rank, opo->suit));
	number++;
	cout << endl;

	while (error == true) {
		cout << "Your count - " << countOfPlaer << " stand or hit? - ";
		cin >> ppi;
		tyy = false;

		while (tyy == false) {
			if (ppi == "stand") {
				error = false;
				tyy = true;
			}
			else if (ppi == "hit") {
				error = true;
				number++;
				opo = this->deckOfCard->at(number);
				plaersDeck->push_back(new Card(opo->rank, opo->suit));
				opo->printCard();
				cout << endl;
				countOfPlaer = this->getDdeckValue(plaersDeck);
				if (getDdeckValue(plaersDeck) == 21) {
					cout << "Your count - " << this->getDdeckValue(plaersDeck) << ". Uhhuu !! You won, but you won nothing !!!!!" << endl;
					stop = false;
					error = false;
				}
				else if (getDdeckValue(plaersDeck) > 21) {
					cout << "Your count - " << this->getDdeckValue(plaersDeck) << ". Ha ha, you los'" << endl;
					error = false;
					stop = false;
				}
				tyy = true;
			}
			else {
				cout << "try again - ";
				cin >> ppi;
				tyy = false;
			}
		}
	}
	if (stop == true) {
		cout << endl;
		while (countOfDiller < 17) {
			number++;
			opo = this->deckOfCard->at(number);
			dillersDeck->push_back(new Card(opo->rank, opo->suit));
			opo->printCard();
			cout << endl;
			countOfDiller += opo->getCardValue();
			cout << "Diller's count - " << getDdeckValue(dillersDeck) << endl;
		}
		cout << endl;
		if (countOfDiller == 21) {
			cout << "Diller won. You are los'!";
		}
		else if ((getDdeckValue(dillersDeck) > getDdeckValue(plaersDeck)) && (getDdeckValue(dillersDeck) <= 21)) {
			cout << "Diller won. You are los'!";
		}
		else if (getDdeckValue(dillersDeck) < getDdeckValue(plaersDeck)) {
			cout << "Uhhuu !! You won, but you won nothing !!!!!" << endl;
		}
		else if (getDdeckValue(dillersDeck) > 21) {
			cout << "Uhhuu !! You won, but you won nothing !!!!!" << endl;
		}
		else if (getDdeckValue(dillersDeck) == getDdeckValue(plaersDeck)) {
			cout << "Uhhuu !! You won, but you won nothing !!!!!" << endl;
		}
	}
	cout << endl;
}
