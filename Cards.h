#ifndef CARDS_H_
#define CARDS_H_
#include<string>
#include "Stack.h"

class Cards
{
public:
	Cards();							//Cards constructor
	int cardCount = 0;					//a counter for "allCardsSuits"
	int count = 0;						//a counter which helps in randomising cards
	int randValues[52];					//an array which stores random values from 0 to 51
	Stack<std::string> stringStack;		//a stack of string which stores all cards
	std::string shuffledCards[52];		//a string array which stores shuffled cards
	std::string* pointerToAllCards;		//a string pointer which points to all cards
	std::string* pointerToAllSuits;		//a string pointer which points to all suits
	std::string* pointerToAllCardsSuits;//a string pointer which points to all cards and suits	
	std::string playerCards[5];			//a string array which stores players played cards
	std::string compCards[5];			//a string array which stores computers played cards
	
	std::string* getCards() const;		//a get method to return all cards
	std::string* getSuits() const;		//a get method to return all suits
	std::string* getAllCards();			//a get method to return all cards and suits
	int getPlayerHandValue();			//a method which returns player hand value
	int getPlayerHandCount();			//a method which returns player hand count
	int getCompHandValue();				//a method which returns computer hand value
	int getCompHandCount();				//a method which returns computer hand count
	void shuffleCards();				//a method to shuffle cards
	void insertCardsinStack();			//a method to insert cards in stack
	void popCardsfromStack();			//a method which pop cards from stack
	void dealInitialPlayerCards();		//a method which deals initial 2 cards to player
	void dealLaterPlayerCards();		//a method which deals later player cards
	void dealInitialCompCards();		//a method which deals initial 2 cards to computer
	void displayInitialCompCards();		//a method which displays initial computer cards as they are dealt in player class
	void dealLaterCompCards();			//a method which deals later computer cards
	void deleteObjects();				//a method which deletes objects which are dynamically stored in memory

private:
	int playerHandValue = 0;			//sets players hand value to 0
	int playerHandCount = 0;			//sets player hand count to 0
	int compHandValue = 0;				//sets comp hand value to 0
	int compHandCount = 0;				//sets comp hand count to 0
	int compCardValue();				//return computer's card value
	int playerCardValue();				//returns player's card value
	std::string* cards = new std::string[13];	//stores all cards
	std::string* suits = new std::string[4];	//stores all suits
	std::string* allCardsSuits = new std::string[52];	//stores all cards and suits
};
#endif
