#include<iostream>
#include<string>
#include <stdlib.h>     
#include <time.h>

#include "Log.h"
#include "Player.h"
#include "Computer.h"
#include "Cards.h"

using namespace std;

int main()
{
	char userInput;
	bool play;
	bool result;
	bool log = true;

	cout << "Welcome to Pontoon." << endl;
	Cards c;
	Computer comp(c);
	Player p(comp);
	Log l(comp, p);
	do
	{
		if (log)		//only creates log file once and not every time player wants to play the game
		{
			l.generateLogFile();
			l.gameStartTime();
		}
		log = false;

		comp.shuffleCards();
		comp.insertCardsinStack();

		int playerPlay = p.play();

		if (playerPlay < 21)
		{
			comp.play(playerPlay);
		}

		l.getPlayerCompData();		//identifies if player has lost or won and stores it in string array

		do
		{
			cout << "Do you want to play again? y/n: ";
			cin >> userInput;
			if (userInput == 'y')
			{
				play = true;
				result = false;
			}
			else if (userInput == 'n')
			{
				l.storeDatainFile();	//stores data in log file	
				l.deleteString();		//deletes string associated with storing data
				l.closeLogFile();		//closes log file
				comp.deleteObjects();		//deletes cards,suits, and allCardsSuits
				play = false;
				result = false;
				cout << "Thanks, bye." << endl;
			}
			else
			{
				cout << "Either Enter y or n" << endl;
				play = true;
				result = true;
			}
		} while (result);

	} while (play);

	system("pause");
	return 0;
}