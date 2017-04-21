#include<iostream>
#include "Log.h"

using namespace std;

Log::Log(Computer &comp, Player &play) : c(comp), p(play){}	//log constructor

void Log::changeMonthValue()	//converts month to string months and month values
{
	if (month == 1)
	{
		stringMonth = "Jan";
		stringMonthvalue = "01";
	}
	else if (month == 2)
	{
		stringMonth = "Feb";
		stringMonthvalue = "02";
	}
	else if (month == 3)
	{
		stringMonth = "Mar";
		stringMonthvalue = "03";
	}
	else if (month == 4)
	{
		stringMonth = "Apr";
		stringMonthvalue = "04";
	}
	else if (month == 5)
	{
		stringMonth = "May";
		stringMonthvalue = "05";
	}
	else if (month == 6)
	{
		stringMonth = "Jun";
		stringMonthvalue = "06";
	}
	else if (month == 7)
	{
		stringMonth = "Jul";
		stringMonthvalue = "07";
	}
	else if (month == 8)
	{
		stringMonth = "Aug";
		stringMonthvalue = "08";
	}
	else if (month == 9)
	{
		stringMonth = "Sep";
		stringMonthvalue = "09";
	}
	else if (month == 10)
	{
		stringMonth = "Oct";
		stringMonthvalue = "10";
	}
	else if (month == 11)
	{
		stringMonth = "Nov";
		stringMonthvalue = "11";
	}
	else if (month == 12)
	{
		stringMonth = "Dec";
		stringMonthvalue = "12";
	}
}

void Log::generateLogFile()		//generates log file
{
	changeMonthValue();
	readData.open("counter.txt", ifstream::in);
	if (readData.is_open())
	{
		readData >> fileCount;
		fileCount++;
	}
	else
	{
		fileCount = 1;
	}
	fileName = to_string(year % 100) + stringMonthvalue + to_string(day) + "_" + to_string(hour) + to_string(min) + "_" + to_string(fileCount) +".txt";
	storeData.open(fileName, ofstream::out);
	storeTimeData.open("counter.txt", ofstream::out);
	storeTimeData << fileCount;
	storeTimeData.close();
}

void Log::gameStartTime()			//calculates games start time and stores it in to log file
{
	changeMonthValue();
	if (storeData.is_open())
	{
		storeData << "Game started at: " << hour << ":" << min << " " << day << "-" << stringMonth << "-" << year << endl;
	}
}

void Log::increaseStoringLimit()
{
	max = max * 2;
	
	tempString = new string[max];
	for (int i = 0; i < count; i++)
	{
		tempString[i] = getString[i];
	}
	
	delete[] getString;
	getString = tempString;
}

std::string* Log::getPlayerCompData()		//gets computer and player's win or losses
{
	if(count >= max)
	{
		increaseStoringLimit();
	}
	if (p.winCount == 1)
	{
		getString[count] = "Won";
	}
	else if (p.winCount == -1)
	{
		getString[count] = "Lost";
	}
	else if (c.winCount == 1)
	{
		getString[count] = "Lost";
	}
	else if (c.winCount == -1)
	{
		getString[count] = "Won";
	}
	else if (c.winCount == 2)
	{
		getString[count] = "Draw";
	}
	count++;
	return getString;
}

void Log::storeDatainFile()				//stores data in every new log file
{
	pointerToString = getPlayerCompData();
	
	for (int i = 0; i < count-1; i++)
	{
		if (pointerToString[i] == "Won")
		{
			winCount++;
		}
		else if (pointerToString[i] == "Lost")
		{
			lostCount++;
		}
		else
		{
			drawCount++;
		}
	}

	if(storeData.is_open())
	{ 
		time_t newCurrentTime = time(NULL);		
		struct tm *newCTime = localtime(&newCurrentTime);
		hour = newCTime->tm_hour;
		min = newCTime->tm_min;

		storeData << "Game finished at: " << hour << ":" << min << " " << day << "-" << stringMonth << "-" << year << endl;
		storeData << "Rounds: " << count-1 << endl;
		storeData << "Won: " << winCount << endl;
		storeData << "Lost: " << lostCount << endl;
		storeData << "Drawn: " << drawCount << endl;
		storeData << "--" << endl;
		for (int i = 0; i < count-1; i++)
		{
			storeData << "Round " << i+1 << ": " << pointerToString[i] << endl;
		}
	}
}

void Log::closeLogFile()		//closes log file
{
	storeData.close();
}

void Log::deleteString()		//deletes string which is dynamically allocated in memory
{
	delete[] tempString;
}
