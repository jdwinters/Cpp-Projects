#include "clockHeader.h"
#include <iostream>

using namespace std;

//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    : JWclo                                             * 
//*                                                                     * 
//* Written by      : Jonathan Winters                                  * 
//*                                                                     * 
//* Purpose         : To create clockType objects and exercise their    * 
//*                   functions.										* 
//*																		* 
//*									                                    * 
//*                                                                     * 
//* Inputs          : Create instance objects and test the following    * 
//*                                                                     *
//*                         setTime()                                   * 
//*                         getTime()                                   * 
//*                         printTime()                                 * 
//*                         incrementSeconds()                          * 
//*                         incrementMinutes()                          * 
//*                         incrementHours()                            * 
//*                         equalTime()                                 * 
//*                                                                     * 
//* Outputs         : Program displays various output from clockType    * 
//*                   object manipulations.                             *
//*                                                                     * 
//* Calls           : No internal or external calls.                    *
//*                   Incline test code for clockType object            * 
//*                                                                     * 
//*---------------------------------------------------------------------* 
//* Change Log:                                                         * 
//*                         Revision                                    * 
//*       Date    Changed  Rel Ver Mod Purpose                          * 
//* 01/19/16      jwinters 000.000.000 Initial release of class         * 
//*                                                                     * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

int main()
{

	int hours;
	int minutes;
	int seconds;

	int myHrs = 9,
		myMins = 30,
		mySecs = 0;
	
	int yourHrs = 11,
		yourMins = 30,
		yourSecs = 0;

	clockType myClock(myHrs, myMins, mySecs);
	clockType yourClock;

	yourClock.setTime(yourHrs, yourMins, yourSecs);
	myClock.getTime(myHrs, myMins, mySecs);
//	myClock.printTime();

		//Set the time of myClock
//	myClock.setTime(5, 4, 30);

	cout << "Line 2: myClock: ";
	myClock.printTime();
	cout <<endl;

	cout << "Line 5: yourClock: ";
	yourClock.printTime();
	cout <<endl;
		
		//Set the time of yourClock
	yourClock.setTime(5, 45, 16);

	cout << "Line 9: After setting, yourClock: ";
	yourClock.printTime();
	cout <<endl;

		//Compare myClock and yourClock
	if (myClock.equalTime(yourClock))
		cout << "Line 13: Both thimes are equal." <<endl;
	else
		cout << "Line 15: The two times are not equal." <<endl;

	cout << "Line 16: Enter the hours, minutes, and seconds: ";
	cin >> hours >> minutes >> seconds;
	cout <<endl;

		//Set the time of myClock using the value of variables hours, minutes and seconds
	myClock.setTime (hours, minutes, seconds);

	cout <<"Line 20: New myClock: ";
	myClock.printTime();	// print the time of myClock
	cout <<endl;

		//Increment the time of myClock by one second
	myClock.incrementSeconds();

	cout << "Line 24: After incrementing myClock by one second, myClock: ";
	myClock.printTime();	// print the time of myClock
	cout <<endl;

		//Retrieve the hours, minutes, and seconds of the object myClock
	myClock.getTime(hours, minutes, seconds);

		//Output the value of hours, minutes, and seconds
	cout << "Line 28: hours = " << hours << ", minutes = " << minutes << ", seconds = " << seconds <<endl;

	return 0;
} //end main
