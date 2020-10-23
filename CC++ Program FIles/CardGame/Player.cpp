#include <iostream>
#include <cstdlib>
#include <string>
#include "Player.h"
using namespace std;
void Player::updateHandValue(){
	handValue = 0;
	for(int i = 0; i < playerHand.size(); i++){
		handValue += playerHand[i].getValue();
	}
}
int Player::getHandValue(){
	updateHandValue();
	return handValue;
}
void Player::changeAceValue(){
	for(int i = 0; i < playerHand.size(); i++){
		if(playerHand[i].getValue() == 11){
			playerHand[i].setValue(1);
			break;
		}
	}
	updateHandValue();
}
void Player::setHandList(vector<Card> playerHand){
	this->playerHand = playerHand;
}
vector<Card> Player::getHandList(){
	return playerHand;
}
bool Player::hasAce(){
	for(int i = 0; i < playerHand.size(); i++){
		if(playerHand[i].getValue() == 11){
			return true;
		}
	}
	return false;
}
Player::Player(){
	playerHand.empty();
	handValue = 0;
}
Player::Player(vector<Card> playerHand){
	this->playerHand = playerHand;
}