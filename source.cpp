#include  "Card.h"
#include "forCard.h"
#include <vector>
#include "Deck.h"
#include <iostream>
#include <ctime>

using namespace std;

int main() {
	srand(time(0));
	Deck ppi;
	ppi.play();

	system("pause");
	return 0;
}