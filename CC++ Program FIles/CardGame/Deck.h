#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
using namespace std;

class Deck {
	public:
		int deckSize();
		void newDeck();
		Card dealCard();
		
	private:
		vector<Card> mydeck;


};


#endif