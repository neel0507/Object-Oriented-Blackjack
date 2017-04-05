#ifndef PLAYER_H_
#define PLAYER_H_
#include "Computer.h"

class Player
{
public:
	Player(Computer &);	//constructors which references object of Cards class
	char userInput;		//user input for stick or twist
	int play();			//a method which enables player to play and returns player hand value
	int winCount;	//win counter which is used in log file
	int handCount; //associated with getting player hand count
	int p;			//associated with getting player hand value
private:
	Computer& cards;		//cards object
};
#endif 
