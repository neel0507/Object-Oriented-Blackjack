#include<iostream>
#include "Computer.h"

using namespace std;

Computer::Computer(Cards &allCards) : cards(allCards) {}	//computer class constructor

void Computer::play(int &playerHandValue)						//a method which plays for computer and returns computer hand value
{
	winCount = 0;
	cout << endl;
	cout << "Banks turn to play...." << "\n\n";
	cout << "Bank hand is: " << "\n\n";
	displayInitialCompCards();
	handCount = getCompHandCount();
	handValue = getCompHandValue();
	playerHandCount = getPlayerHandCount();
	cout << "Value: " << handValue << "\n\n";

	while (handValue < playerHandValue && handCount < 5)
	{
		cout << "Bank draws a card..." << "\n\n";
		cout << "Bank hand is: " << "\n\n";
		dealLaterCompCards();
		handCount = getCompHandCount();
		handValue = getCompHandValue();
		cout << "Value: " << handValue << "\n\n";
	}

	if (handValue == playerHandValue)
	{
		if (handCount > playerHandCount)
		{
			winCount++;
			cout << "Sorry, Computer Won." << endl;
		}
		else if (handCount < playerHandCount)
		{
			winCount--;
			cout << "You Won." << endl;
		}
		else
		{
			winCount = 2;
			cout << "It is a draw." << endl;
		}
	}
	else if (handValue == 21)
	{
		winCount++;
		cout << "Sorry, Computer Won." << endl;
	}
	else if (handValue > 21)
	{
		winCount--;
		cout << "BUST..." << endl;
		cout << "You Won." << endl;
	}
	else if (handValue > playerHandValue && handValue < 21)
	{
		winCount++;
		cout << "Sorry, Computer Won." << endl;
	}
	else
	{
		winCount--;
		cout << "You Won." << endl;
	}
}