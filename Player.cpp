#include<iostream>
#include "Player.h"
using namespace std;

Player::Player(Computer &allCards) : cards(allCards) {}	//player class constructor

int Player::play()				//a method which enables player to play and returns player hand value
{
	winCount = 0;
	cout << endl;
	cout << "Your hand is: " << "\n\n";
	cards.dealInitialCompCards();
	cards.dealInitialPlayerCards();
	handCount = cards.getPlayerHandCount();
	p = cards.getPlayerHandValue();
	cout << "Value: " << p << "\n\n";
	
	if (p < 21)
	{
		do
		{ 
			cout << "Stick or Twist? s/t: ";
			cin >> userInput;
			if (userInput == 's')
			{
				break;
			}
			else if (userInput == 't')
			{
				cout << endl;
				cout << "Your hand is: " << "\n\n";
				cards.dealLaterPlayerCards();
				handCount = cards.getPlayerHandCount();
				p = cards.getPlayerHandValue();
				cout << "Value: " << p << "\n\n";
			}
			else
			{
				cout << "Either Enter s or t " << endl;
			}
		} while (p < 21 && handCount < 5);
	}

	if ( p == 21)
	{
		winCount++;
		cout << "You Won." << endl;
	}
	else if (p > 21)
	{
		winCount--;
		cout << "BUST..." << endl;
		cout << "Sorry, Computer Won." << endl;
	}
	return p;
}