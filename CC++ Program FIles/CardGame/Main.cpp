#include <iostream>
#include <string>
#include <unistd.h>
#include "Card.h"
#include "Deck.h"
#include "Player.h"


using namespace std;
void printCards(vector<Card> PersonH){
	for(int j = 0; j < PersonH.size(); j++){
		PersonH[j].printCard();
	}
}
bool endGame(int playerHandValue, int dealerHandValue){
	if(dealerHandValue > 21 || playerHandValue > dealerHandValue ){
		if(dealerHandValue > 21){
			cout << "Dealer Busts..." << endl;
		}
		cout << "You Win!!" << endl << endl;
		return true;
	}else if(playerHandValue == dealerHandValue){
		cout << "Push!" << endl << endl;
		return false;
	}
	cout << "Dealer Wins..." << endl;
	return false;
}
bool isBlackJack(Player &player){
	vector<Card> PlayerH = player.getHandList();
	if(PlayerH[0].getName().compare("Ace") == 0){
		
		if(PlayerH[1].getName().compare("Ten") == 0){
			return true;
		}else if(PlayerH[1].getName().compare("Jack") == 0){
			return true;
		}else if(PlayerH[1].getName().compare("Queen") == 0){
			return true;
		}else if(PlayerH[1].getName().compare("King") == 0){
			return true;
		}
	}else if(PlayerH[1].getName().compare("Ace") == 0){
		if(PlayerH[0].getName().compare("Ten") == 0){
			return true;
		}else if(PlayerH[0].getName().compare("Jack") == 0){
			return true;
		}else if(PlayerH[0].getName().compare("Queen") == 0){
			return true;
		}else if(PlayerH[0].getName().compare("King") == 0){
			return true;
		}
	}
	return false;
	
}
void genHand(Deck &deck, Player &person, bool isDealer){
	vector<Card> newHand;
	if(!isDealer){
		newHand.push_back(deck.dealCard());
		cout << "Dealing Card to you";
		for(int i = 0; i < 5; i++){
			usleep(200000);
			cout << endl;
			cout << ".";
		}	
		cout << endl;
		newHand[0].printCard();
		newHand.push_back(deck.dealCard());
		cout << "Dealing Card to you";
		for(int i = 0; i < 5; i++){
			usleep(200000);
			cout << endl;
			cout << ".";
		}	
		cout << endl;
		newHand[1].printCard();
		person.setHandList(newHand);
		return;
	}
	newHand.push_back(deck.dealCard());
	cout << "Dealing Card to dealer";
		for(int i = 0; i < 5; i++){
			usleep(200000);
			cout << endl;
			cout << ".";
		}	
		cout << endl;
		newHand[0].printCard();
	person.setHandList(newHand);
	for(int i = 0; i < 5; i++){
			usleep(200000);
		cout << ".";
		}	
}
void reshuffle(Deck &deck){
	deck.newDeck();
}
void dealCards(Deck &deck, Player &player, Player &dealer){
	
	genHand(deck, player, false);
	player.updateHandValue();
	genHand(deck, dealer, true);
	dealer.updateHandValue();
	
	cout << "Your hand: " << endl;
	printCards(player.getHandList());
	cout << "Total Value: " << player.getHandValue() << endl << endl;
	
	cout << "Dealer's Hand: " << endl;
	printCards(dealer.getHandList());
	cout << "Dealer's Value: " << dealer.getHandValue() << endl << endl;
	
}
void gameStart(Deck &deck, Player &player, Player &dealer){
	cout << "----Game Start----" << endl 
		<< "----BlackJack----" << endl
		<< "Try to get 21 without going over" << endl;
	
	dealCards(deck, player, dealer);
}
bool playerTurn(Deck &deck, Player &player){
	cout << "Your Turn started..." << endl;
	bool isBust = false;
	char hitOrStand;
	char playerAnswer;
	
	for(;;){
		
		if(player.getHandValue() <= 21){
			cout << endl << "Hit or Stand with " << player.getHandValue() << " (s,h)" << endl;
			cin >> hitOrStand;
			if(hitOrStand == 'h'){
				vector<Card> newHand = player.getHandList();
				newHand.push_back(deck.dealCard());
				cout << "Dealing Card to you";
				for(int i = 0; i < 5; i++){
					usleep(200000);
					cout << endl;
					cout << ".";
				}	
				cout << endl;
				player.setHandList(newHand);
				player.updateHandValue();
				
				cout << endl << "---- Your Cards ----" << endl;
				printCards(player.getHandList());
				
				cout << "Total Value: " << player.getHandValue() << endl;
				cout << "--------------------" << endl << endl;
			}else{
				break;
			}
		}else{
			if(player.hasAce()){
				player.changeAceValue();
			}
			cout << "Bust!" << endl;
			return true;
		}
	}
	return false;
}
void dealerTurn(Deck &deck, Player &dealer){
	cout << "Dealer's Turn Started..." << endl << endl;
	cout << "Dealer has: " << dealer.getHandValue() << endl;
	while(dealer.getHandValue() < 17){
		cout << "The dealer hits..." << endl;
		vector<Card> newHand = dealer.getHandList();
		newHand.push_back(deck.dealCard());
		cout << "Dealing Card to dealer";
		for(int i = 0; i < 5; i++){
			usleep(200000);
			cout << endl;
			cout << ".";
		}	
		cout << endl;
		dealer.setHandList(newHand);
		dealer.updateHandValue();
		
		cout << "---- Dealer Hand ----" << endl;
		printCards(dealer.getHandList());
		cout << "Total: " << dealer.getHandValue() << endl;
		if(dealer.hasAce() && dealer.getHandValue() > 21){
			dealer.changeAceValue();
			cout << "The dealer chose to change Ace's value to 1..." << endl;
			break;
		}
		cout << "Dealer is Deciding..." << endl;
		for(int i = 0; i < 5; i++){
			usleep(200000);
		cout << ".";
		}	
	}
	if(dealer.getHandValue() > 21){
		return;
	}
	cout << "The dealer Stands with: " << dealer.getHandValue();
	return;
}

int main() {
	Deck deck;
	Player player;
	Player dealer;
	bool isEndGame = false;
	deck.newDeck();
	bool firstTime = true;
	bool bust = false;
	
	int playerMoney = 0;
	int handValue = 0;
	int bet = 0;
	char playAgain;
	
	//Begin game
	cout << "Enter your balance" << endl;
	cin >> playerMoney;
	
	for(;;){
		//Check for playing again
		if(!firstTime){
			cout << "Current Balance: $" << playerMoney << endl;
			cout << "--------------------" << endl << endl;
			cout << "Do you want to play again? (y,n)" << endl;
			cin >> playAgain;
			if(playAgain == 'n'){
				break;
			}else{
				if(playAgain != 'y'){
					cout << "Invalid answer..." << endl;
					break;
				}
			}
		}else{
			firstTime = false;
		}
		cout << "Enter your bet" << endl;
		cin >> bet;
		playerMoney -= bet;
		cout << "--------------------" << endl;
		cout << "Current Balance: $" << playerMoney << endl;
		cout << "Current Bet: $" << bet << endl;
		cout << "--------------------" << endl;
		gameStart(deck, player, dealer);
		
		if(deck.deckSize() < (52 * .2)){
			reshuffle(deck);
		}
		//Check for Black Jack
		/*
		Test For Player and Dealer BlackJack Push
		------------------------------------------
		Card testCard1;
		testCard1.setName("Ace");
		testCard1.setSuit("Spades");
		testCard1.setValue(11);
		Card testCard2;
		testCard2.setName("Ten");
		testCard2.setSuit("Spades");
		testCard2.setValue(10);
		
		Card testCardD1;
		testCardD1.setName("Ace");
		testCardD1.setSuit("Spades");
		testCardD1.setValue(11);
		vector<Card> testHandP = {testCard1, testCard2};
		Card testCardD2;
		testCardD2.setName("Ten");
		testCardD2.setSuit("Spades");
		testCardD2.setValue(10);
		vector<Card> testHandD = {testCardD1, testCardD2};
		
		player.setHandList(testHandP);
		printCards(player.getHandList());
		dealer.setHandList(testHandD);
		printCards(dealer.getHandList());*/
		if(isBlackJack(player)){
			cout << "BlackJack!" << endl;
			endGame(player.getHandValue(), dealer.getHandValue());
			break;
		}
		if(!playerTurn(deck, player)){
			cout << endl << "your Turn Finished..." << endl;
			
			dealerTurn(deck, dealer);
			cout << endl << "Dealer's Turn Finished..." << endl;
			if(endGame(player.getHandValue(), dealer.getHandValue()) == true){
				playerMoney += bet * 2;
			}
		}else if(player.getHandValue() == dealer.getHandValue()){
			playerMoney += bet;
		}else{
			cout << endl << "The Dealer wins..." << endl << endl;
		}
	}
 
 return 0;
 
} 