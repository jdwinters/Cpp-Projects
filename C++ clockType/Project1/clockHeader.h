// Jonathan Winters
// 1/14/2016
// clockType Header file
#include <iomanip>
#include <iostream>
#ifndef CLOCKHEADER_H_INCLUDED
#define CLOCKHEADER_H_INCLUDED


using namespace std;

class clockType
{
public:
	void setTime(int, int, int);					// sets the time
	void getTime(int&, int&, int&) const;			// gets the time 
	void printTime() const;							// prints the time
	int incrementSeconds();							// increments seconds by 1
	int incrementMinutes();							// increments minutes
	int incrementHours();							// increments hours
	bool equalTime(const clockType&) const;			// check between two clocks if they are equal
	clockType(int, int, int);						// constructor with parameters
	clockType();									// default constructor

private:											// hours
	int hr;											// minutes
	int min;										// seconds
	int sec;
};
class stopclockType
{
public:
	void setStopTime(int, int, int);
	void setTime(int, int, int);					// sets the time
	void getTime(int&, int&, int&) const;			// gets the time 
	void printTime() const;							// prints the time
	bool incrementSeconds();							// increments seconds by 1
	int incrementMinutes();							// increments minutes
	int incrementHours();							// increments hours
	bool equalTime(const stopclockType&) const;			// check between two clocks if they are equal
	stopclockType(int, int, int);						// constructor with parameters
	stopclockType();									// default constructor

private:											// hours
	int stopHr;											// minutes
	int stopMin;										// seconds
	int stopSec;

	int hr;											// minutes
	int min;										// seconds
	int sec;
};

#endif 