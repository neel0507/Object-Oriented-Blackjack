#include<iostream>
#include<string>
#include<array>
#include <stdlib.h>     
#include <time.h>
#include "Stack.h"
#include "Cards.h"

using namespace std;

Cards::Cards()	//constructors sets cards and suits by assining values from A to K and Spades to Diamonds
{
	cards[0] = "Ace"; cards[1] = "Two"; cards[2] = "Three"; cards[3] = "Four";
	cards[4] = "Five"; cards[5] = "Six"; cards[6] = "Seven"; cards[7] = "Eight";
	cards[8] = "Nine"; cards[9] = "Ten"; cards[10] = "Jack"; cards[11] = "Queen";
	cards[12] = "King";

	suits[0] = "Spades"; suits[1] = "Hearts"; suits[2] = "Clubs"; suits[3] = "Diamonds";
}

string* Cards::getCards() const //a get method to return all cards
{
	return cards;
}

string* Cards::getSuits() const //a get method to return all suits
{
	return suits;
}

string* Cards::getAllCards()	//a get method to return all cards and suits
{
	cardCount = 0;
	pointerToAllCards = getCards();
	pointerToAllSuits = getSuits();

	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			allCardsSuits[cardCount] = pointerToAllCards[i] + " of " + pointerToAllSuits[j];
			cardCount++;
		}
	}
	return allCardsSuits;
}

void Cards::shuffleCards()	//a method to shuffle cards
{
	popCardsfromStack();

	pointerToAllCardsSuits = getAllCards();
	srand(time(NULL));

	for (int i = 0; i < 52; i++)
	{
		count = 0;
		randValues[i] = rand() % 52;
		if (i == 0)
		{
			shuffledCards[i] = pointerToAllCardsSuits[randValues[i]];
		}
		if (i > 0)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (randValues[i] != randValues[j])
				{
					count++;
				}
				else if (randValues[i] == randValues[j])
				{
					count = 0;
					i = i - 1;
					break;
				}
			}
			if (count > 0)
			{
				shuffledCards[i] = pointerToAllCardsSuits[randValues[i]];
			}
		}
	}
}

void Cards::insertCardsinStack() //a method to insert cards in stack
{
	for (int i = 0; i < 52; i++)
	{
		stringStack.push(shuffledCards[i]);
	}
}

void Cards::popCardsfromStack()	//a method which pop cards from stack
{
	while (!stringStack.isEmpty())
	{
		stringStack.pop();
	}
}

int Cards::getPlayerHandCount()	//a method which returns player hand count
{
	return playerHandCount;
}

int Cards::getCompHandCount()	//a method which returns computer hand count
{
	return compHandCount;
}

int Cards::getPlayerHandValue()	//a method which returns player hand value
{
	return playerHandValue;
}

int Cards::getCompHandValue()	//a method which returns computer hand value
{
	return compHandValue;
}

void Cards::dealInitialPlayerCards()	//a method which deals initial 2 cards to player
{

	if (!stringStack.isEmpty())
	{
		for (int i = 0; i < 2; i++)
		{
			playerCards[playerHandCount] = stringStack.top();
			cout << playerCards[playerHandCount] << endl;
			playerHandCount++;
			playerCardValue();
			stringStack.pop();
		}
	}
}

void Cards::dealLaterPlayerCards()		//a method which deals later player cards
{
	for (int i = 0; i < playerHandCount; i++)
	{
		cout << playerCards[i] << endl;
	}
	if (!stringStack.isEmpty())
	{
		playerCards[playerHandCount] = stringStack.top();
		cout << playerCards[playerHandCount] << endl;
		playerHandCount++;
		playerCardValue();
		stringStack.pop();
	}
}

void Cards::dealInitialCompCards()		//a method which deals initial 2 cards to computer
{
	playerHandValue = 0;
	playerHandCount = 0;
	compHandValue = 0;
	compHandCount = 0;

	if (!stringStack.isEmpty())
	{
		for (int i = 0; i < 2; i++)
		{
			compCards[compHandCount] = stringStack.top();
			compHandCount++;
			compCardValue();
			stringStack.pop();
		}
	}
}

void Cards::displayInitialCompCards()
{
	for (int i = 0; i < compHandCount; i++)
	{
		cout << compCards[i] << endl;
	}
}

void Cards::dealLaterCompCards()		//a method which deals later computer cards
{
	compCards[compHandCount] = stringStack.top();
	compHandCount++;
	compCardValue();
	for (int i = 0; i < compHandCount; i++)
	{
		cout << compCards[i] << endl;
	}
	stringStack.pop();
}

int Cards::playerCardValue()			//returns player's card value
{
	if ((stringStack.top()).substr(0, 3) == "Ace")
	{
		playerHandValue += 1;
	}
	else if ((stringStack.top()).substr(0, 3) == "Two")
	{
		playerHandValue += 2;
	}
	else if ((stringStack.top()).substr(0, 5) == "Three")
	{
		playerHandValue += 3;
	}
	else if ((stringStack.top()).substr(0, 4) == "Four")
	{
		playerHandValue += 4;
	}
	else if ((stringStack.top()).substr(0, 4) == "Five")
	{
		playerHandValue += 5;
	}
	else if ((stringStack.top()).substr(0, 3) == "Six")
	{
		playerHandValue += 6;
	}
	else if ((stringStack.top()).substr(0, 5) == "Seven")
	{
		playerHandValue += 7;
	}
	else if ((stringStack.top()).substr(0, 5) == "Eight")
	{
		playerHandValue += 8;
	}
	else if ((stringStack.top()).substr(0, 4) == "Nine")
	{
		playerHandValue += 9;
	}
	else if ((stringStack.top()).substr(0, 3) == "Ten")
	{
		playerHandValue += 10;
	}
	else if ((stringStack.top()).substr(0, 4) == "Jack")
	{
		playerHandValue += 10;
	}
	else if ((stringStack.top()).substr(0, 5) == "Queen")
	{
		playerHandValue += 10;
	}
	else if ((stringStack.top()).substr(0, 4) == "King")
	{
		playerHandValue += 10;
	}
	return playerHandValue;
}

int Cards::compCardValue()			//return computer's card value
{
	if ((stringStack.top()).substr(0, 3) == "Ace")
	{
		compHandValue += 1;
	}
	else if ((stringStack.top()).substr(0, 3) == "Two")
	{
		compHandValue += 2;
	}
	else if ((stringStack.top()).substr(0, 5) == "Three")
	{
		compHandValue += 3;
	}
	else if ((stringStack.top()).substr(0, 4) == "Four")
	{
		compHandValue += 4;
	}
	else if ((stringStack.top()).substr(0, 4) == "Five")
	{
		compHandValue += 5;
	}
	else if ((stringStack.top()).substr(0, 3) == "Six")
	{
		compHandValue += 6;
	}
	else if ((stringStack.top()).substr(0, 5) == "Seven")
	{
		compHandValue += 7;
	}
	else if ((stringStack.top()).substr(0, 5) == "Eight")
	{
		compHandValue += 8;
	}
	else if ((stringStack.top()).substr(0, 4) == "Nine")
	{
		compHandValue += 9;
	}
	else if ((stringStack.top()).substr(0, 3) == "Ten")
	{
		compHandValue += 10;
	}
	else if ((stringStack.top()).substr(0, 4) == "Jack")
	{
		compHandValue += 10;
	}
	else if ((stringStack.top()).substr(0, 5) == "Queen")
	{
		compHandValue += 10;
	}
	else if ((stringStack.top()).substr(0, 4) == "King")
	{
		compHandValue += 10;
	}
	return compHandValue;
}

void Cards::deleteObjects()		//a method which deletes objects which are dynamically stored in memory
{
	delete[] allCardsSuits;
	delete[] cards;
	delete[] suits;
}