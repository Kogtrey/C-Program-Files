#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <vector>
using namespace std;

class Player {	
	private:
		int handValue;
		vector<Card> playerHand;
		
	public:
		void updateHandValue();
		int getHandValue();
		void changeAceValue();
		void setHandList(vector<Card> playerHand);
		vector<Card> getHandList();
		bool hasAce();
		Player();
		Player(vector<Card> playerHand);
};


#endif