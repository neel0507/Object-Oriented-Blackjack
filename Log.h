#ifndef LOG_H_
#define LOG_H_
#include "Computer.h"
#include "Player.h"
#include<string>
#include<time.h>
#include <fstream>

class Log
{
public:
	Log(Computer &, Player &);	//log class constructor which takes references of computer class object and player class object

	std::string fileName;		//file to store log data
	int count = 0;				//a counter which is associated with getString
	int winCount = 0;			//identifies number of times player won
	int lostCount = 0;			//identifies number of times player lost
	int drawCount = 0;			//identifies number of draws
	int fileCount = 0;			//a counter which is associated with storing counters and associating them with file names of logs

	time_t currentTime = time(NULL);			//stores current time
	struct tm *cTime = localtime(&currentTime);	//stores current local time
	int hour = cTime->tm_hour;					//displays current hour
	int min = cTime->tm_min;					//displays current minute
	int day = cTime->tm_mday;					//displays current day
	int month = cTime->tm_mon + 1;				//displays current month
	int year = cTime->tm_year + 1900;			//displays current year
	std::string stringMonth;					//converts month values to strings
	std::string stringMonthvalue;				//converts month values of 1 to 9 to 01 to 09
	std::ofstream storeTimeData;				//ofstream associated with "counter.txt" which stores counts
	std::ifstream readData;						//ifstream associated with "counter.txt" which reads counts

	void generateLogFile();						//generates log file
	std::string* getDataString();				//returns getString
	void getPlayerCompData();					//gets computer and player's win or losses
	void storeDatainFile();						//stores data in every new log file
	void closeLogFile();						//closes log file after each program termination
	void deleteString();						//deletes string which is dynamically allocated in memory
	void gameStartTime();						//calculates games start time and stores it in to log file
	void changeMonthValue();					//associated with "stringMonth" and "stringMonthValue"

private:
	std::string* getString = new std::string[100];	//string array to store strings of wins and losses or draws
	std::ofstream storeData;						//associated with each log file
	Computer& c;									//computer object
	Player& p;										//player object
};
#endif 