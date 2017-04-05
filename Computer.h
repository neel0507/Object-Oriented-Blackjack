#ifndef COMPUTER_H_
#define COMPUTER_H_
#include "Cards.h"

class Computer : public Cards
{
public:
	Computer(Cards &);	//constructors which references object of Cards class
	int winCount;		//win counter which is used in log file
	void play(int &);	//a method which takes integer reference of player hand value and enables computer to play and returns computer hand value
	int handValue;		//associated with getting computer hand value
	int handCount;		//associated with getting computer hand count
	int playerHandCount;	//associated with getting player hand count
private:
	Cards cards;	//cards object
};
#endif
