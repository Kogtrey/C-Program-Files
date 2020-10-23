#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Deck.h"
using namespace std;

int Deck::deckSize(){
	return mydeck.size();
}

void Deck::newDeck(){
	mydeck.clear();
	Card currCard;
	vector<string> Names = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
	vector<string> Suit = {"Spades","Clubs","Hearts","Diamonds"};
	for(int x = 0; x < 4; x++){
		for(int i = 0; i < 13; i++){
			if(i < 10){
			currCard.setName(Names[i]);
			currCard.setSuit(Suit[x]);
			currCard.setValue(i+1);	
			mydeck.push_back(currCard);
			}else{
			currCard.setName(Names[i]);
			currCard.setSuit(Suit[x]);
			currCard.setValue(10);
			mydeck.push_back(currCard);
			}
		}
	}
}

Card Deck::dealCard(){
	srand((int)time(0));
	int random = rand() % mydeck.size();
	
	Card currCard;
	currCard = mydeck.at(random);
	vector<Card>::iterator it;
	it=mydeck.begin();
	mydeck.erase(it+random);
	return currCard;
}