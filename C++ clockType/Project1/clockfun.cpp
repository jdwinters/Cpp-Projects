#include <iostream>
#include "clockHeader.h"

using namespace std;

//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    : clockfun												* 
//*																			* 
//* Written by      : Jonathan Winters										* 
//*																			* 
//* Purpose         : To emulate standard clock for displaying the			* 
//*                   time on the console.	It will validate given time		* 
//*					  parameters, print them, and increment the hours		*
//*					  minutes and seconds. It will also compare two			* 
//*                   clock times.											* 
//*																			* 
//*																			* 
//* Inputs          : User will create instance objects of this class		* 
//*                   to store the hour, minute and second. User			*
//*                   may also change the time or increment the hour,		*
//*                   minute or second.										* 
//*																			* 
//* Outputs         : Program displays various output from clockType		* 
//*                   object manipulations.									*
//*																			* 
//* Calls           :clockType() - constructor with or without parameters   *
//*                  setTime()          - sets the time in the object	    *
//*                  getTime()          - returns the time in the object	* 
//*                  printTime()        - prints time to console			* 
//*                  incrementSeconds() - adds 1 to seconds				    * 
//*                  incrementMinutes() - adds 1 to minutes				    * 
//*                  incrementHours()   - adds 1 to hours				    * 
//*                  equalTime()        - compares 2 objects for time	    * 
//*                                      for equal time values			    * 
//*---------------------------------------------------------------------	* 
//* Change Log:																* 
//*                         Revision										* 
//*       Date    Changed  Rel Ver Mod Purpose								* 
//* 01/19/16      jwinters 000.000.000 Initial release of class				* 
//*																			* 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

clockType::clockType(int hours, int minutes, int seconds)
{
	if (0 <= hours && hours < 24)
		hr = hours;
	else
		hr = 0;

	if (0 <= minutes && minutes < 60)
		min = minutes;
	else
		min = 0;

	if (0 <= seconds && seconds < 60)
		sec = seconds;
	else
		sec = 0;
}
clockType::clockType() // default constructor
{
	hr = 0;
	min = 0;
	sec = 0;
}
void clockType::setTime(int hours, int minutes, int seconds)
{
	if (0 <= hours && hours < 24)
		hr = hours;
	else
		hr = 0;
	if (0 <= minutes && minutes < 60)
		min = minutes;
	else
		min = 0;
	if (0 <= seconds && seconds < 60)
		sec = seconds;
	else
		sec = 0;
}
void clockType::getTime(int& hours, int& minutes, int& seconds) const
{
		hours = hr;
		minutes = min;
		seconds = sec;
}
void clockType::printTime() const
{
	if (hr < 10)
		cout << "0";
	cout << hr << ":";

	if (min < 10)
		cout << "0";
	cout << min << ":";
	
	if (sec < 10)
		cout << "0";
	cout << sec;
}
int clockType::incrementSeconds()
{
		sec++;
		if (sec > 59)
		{
			sec = 0;
			incrementMinutes(); // increment mins
		}
	return 0;
}
int clockType::incrementMinutes()
{
	min++;
		if (min > 59)
		{
			min = 0;
			incrementHours(); // increment hours
		}
	return 0;
}
int clockType::incrementHours()
{
	hr++;
	if (hr > 23)
		hr = 0;
	return 0;
}
bool clockType::equalTime(const clockType& otherClock) const
{
	return (hr == otherClock.hr
			&& min == otherClock.min
			&& sec == otherClock.sec);
}