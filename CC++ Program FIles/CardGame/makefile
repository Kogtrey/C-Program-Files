CardGame.exe: main.o Deck.o Card.o Player.o
	g++ --std=c++11 main.o Deck.o Card.o Player.o -o CardGame.exe

main.o: main.cpp Card.o Deck.o Player.o
	g++ --std=c++11 -c main.cpp
	
Deck.o: Deck.cpp Deck.h Card.o
	g++ --std=c++11 -c Deck.cpp
	
Card.o: Card.cpp Card.h
	g++ --std=c++11 -c Card.cpp

Player.o: Player.cpp Player.h Card.o
	g++ --std=c++11 -c Player.cpp;
	
Clean: 
	rm *.o CardGame.exe