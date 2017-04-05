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

string* Log::getDataString()	//returns getString
{
	return getString;
}

void Log::getPlayerCompData()		//gets computer and player's win or losses
{
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
}

void Log::storeDatainFile()				//stores data in every new log file
{
	for (int i = 0; i < count; i++)
	{
		if (getString[i] == "Won")
		{
			winCount++;
		}
		else if (getString[i] == "Lost")
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
		storeData << "Rounds: " << count << endl;
		storeData << "Won: " << winCount << endl;
		storeData << "Lost: " << lostCount << endl;
		storeData << "Drawn: " << drawCount << endl;
		storeData << "--" << endl;
		for (int i = 0; i < count; i++)
		{
			storeData << "Round " << i+1 << ": " << getString[i] << endl;
		}
	}
}

void Log::closeLogFile()		//closes log file
{
	storeData.close();
}

void Log::deleteString()		//deletes string which is dynamically allocated in memory
{
	delete[] getString;
}