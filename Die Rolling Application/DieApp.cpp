#include <iostream>
#include <algorithm>
#include "Die.h"

//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    : DieApp                                         	*
//*                                                                     *
//* Written by      : Jonathan Winters									*
//*					  Zack Schunk										* 
//*                   Audra Joslyn                                      * 
//* Purpose         : To create Die objects and use them to roll dice   * 
//*																		* 
//*																		* 
//*									                                    * 
//*                                                                     * 
//* Inputs          : Create instance objects and test the following    * 
//*                                                                     *
//*						getNum() const;		                            * 
//*						void roll();		                            * 
//*											                            * 
//*											                            * 
//*											                            * 
//*											                            * 
//*											                            * 
//*                                                                     * 
//* Outputs         : Program displays various output from Dice		    * 
//*                   object manipulations.                             *
//*                                                                     * 
//* Calls           : No internal or external calls.                    *
//*                   Incline test code for Die object            * 
//*                                                                     * 
//*---------------------------------------------------------------------* 
//* Change Log:                                                         * 
//*                         Revision                                    * 
//*       Date    Changed  Rel Ver Mod Purpose                          * 
//* 02/09/16      jwinters 000.000.000 Initial release of class         * 
//*                                                                     * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
using namespace std;

int main()
{
	int graphNum[60];
	int rolled,											// user inputed amount of rolls wanted
		i,												// a counter for going through an array of objects
		total,
		NumOfDice,										// the sum the user NumOfDicees
		diceGraph[5000],
		y,
		strCntr;


	Die dice[6];										// an array of objects

	do
	{
	cout << "Please enter the desired number of dice: (4 thru 6) ---> ";		// user prompt for number of dice
		cin >> NumOfDice;
		cout <<endl;
	}
	while( NumOfDice < 4 || NumOfDice > 6 );

	do
	{
	cout << "Please enter the desired number of rolls: (0 thru 5000) ";//user prompt for rolls
		cin >> rolled;
		cout <<endl;
	}
	while( rolled > 5000 || rolled < 0 );


	if(NumOfDice == 4)
		goto FourDice;
	if(NumOfDice == 5)
		goto FiveDice;
	if(NumOfDice == 6)
		goto SixDice;
//0000000000000000000000000000000000000000000000000000000000000000000000000000000
// ----------------- This is for 4 Dice ---------------------------------------//
FourDice:
for(int k = 0; k != rolled; k++)	// This will do # of inputted rolls, and stores total of those values each roll into an array
{
	total = 0;					// initialize total to 0

		for(i = 0; i != 4; i++)	// This will roll all the dice
		{
			dice[i].roll();		// roll a die
			total += dice[i].getNum();	//add dice value to total
		}
	diceGraph[k] = total;		// store each total into a different spot of the array
		
}

for(int x = 0; x <= 24; x++)						// Counts the number of times a value repeats  
{													// and store the specific value in accordinance
graphNum[x] = count(diceGraph, diceGraph+rolled, x);	// with its position in the graphing array
}


//--------------------------------		 // This will display the graph for each index, and its corresponding value
cout << "----------" << "0--------10--------20--------30--------40--------50--------60--------70--------80--------90-------100-------110-------120-------130" <<endl;
cout << "----------" << "|*********|*********|*********|*********|*********|*********|*********|*********|*********|*********|*********|*********|*********|" <<endl;
for(y = 4; y <= 24; y++)		 		 // 
{										 //
	cout << y ;					 // put out the index number
	if(y < 10)							 //
		cout << "   ";				 // This makes the graph look nice by setting bars equal length from number regardless of how many characters in number
	else								 //
	cout << " ";

	cout << " ( ";
	if(graphNum[y] < 10 && y >= 10)
	{
	cout << "  ";				 // This makes the graph look nice by setting bars equal length from number regardless of how many characters in number
	}
	else if(graphNum[y] < 10 && y < 10)
	{
		cout << " ";
	}
	else 
	{
	cout << " ";
	}
	cout << graphNum[y] << ")" << ":";
	strCntr = 1;						 // initialize strCntr and reintialize each time before it starts displaying stars

		while(strCntr <= graphNum[y])	 // This loop puts out a certain number of stars with the according index number
		{								 //
			cout << "*";				 // 
			strCntr++;					 // Increment strCntr
		}								 //

	cout <<endl;
}										 //
goto stop;
//--------------------------------		 //
//0000000000000000000000000000000000000000000000000000000000000000000000000000000

// ----------------- This is for 5 Dice ---------------------------------------//
FiveDice:
for(int k = 0; k != rolled; k++)	// This will do # of inputted rolls, and stores total of those values each roll into an array
{
	total = 0;					// initialize total to 0

		for(i = 0; i != 5; i++)	// This will roll all the dice
		{
			dice[i].roll();		// roll a die
			total += dice[i].getNum();	//add dice value to total
		}
	diceGraph[k] = total;		// store each total into a different spot of the array
		
}

for(int x = 0; x <= 30; x++)						// Counts the number of times a value repeats  
{													// and store the specific value in accordinance
graphNum[x] = count(diceGraph, diceGraph+rolled, x);	// with its position in the graphing array
}


//--------------------------------		 // This will display the graph for each index, and its corresponding value
cout << "----------" << "0--------10--------20--------30--------40--------50--------60--------70--------80--------90-------100-------110-------120-------130" <<endl;
cout << "----------" << "|*********|*********|*********|*********|*********|*********|*********|*********|*********|*********|*********|*********|*********|" <<endl;
for(y = 5; y <= 30; y++)		 		 // 
{										 //
	cout << y;					 // put out the index number
	if(y < 10)							 //
		cout << "   ";				 // This makes the graph look nice by setting bars equal length from number regardless of how many characters in number
	else								 //
	cout << " ";

	cout << " ( ";
	if(graphNum[y] < 10 && y >= 10)
	{
	cout << "  ";				 // This makes the graph look nice by setting bars equal length from number regardless of how many characters in number
	}
	else if(graphNum[y] < 10 && y < 10)
	{
		cout << " ";
	}
	else 
	{
	cout << " ";
	}
	cout << graphNum[y] << ")" << ":";
	strCntr = 1;						 // initialize strCntr and reintialize each time before it starts displaying stars

		while(strCntr <= graphNum[y])	 // This loop puts out a certain number of stars with the according index number
		{								 //
			cout << "*";				 // 
			strCntr++;					 // Increment strCntr
		}								 //

	cout <<endl;
}										 //
goto stop;
//--------------------------------		 //
//0000000000000000000000000000000000000000000000000000000000000000000000000000000
// ----------------- This is for 6 Dice ---------------------------------------//
SixDice:
for(int k = 0; k != rolled; k++)	// This will do # of inputted rolls, and stores total of those values each roll into an array
{
	total = 0;					// initialize total to 0

		for(i = 0; i != 6; i++)	// This will roll all the dice
		{
			dice[i].roll();		// roll a die
			total += dice[i].getNum();	//add dice value to total
		}
	diceGraph[k] = total;		// store each total into a different spot of the array
		
}

for(int x = 0; x <= 36; x++)						// Counts the number of times a value repeats  
{													// and store the specific value in accordinance
graphNum[x] = count(diceGraph, diceGraph+rolled, x);	// with its position in the graphing array
}


//--------------------------------		 // This will display the graph for each index, and its corresponding value
cout << "----------" << "0--------10--------20--------30--------40--------50--------60--------70--------80--------90-------100-------110-------120-------130" <<endl;
cout << "----------" << "|*********|*********|*********|*********|*********|*********|*********|*********|*********|*********|*********|*********|*********|" <<endl;
for(y = 6; y <= 36; y++)		 		 // 
{										 //
	cout << y;					 // put out the index number

	if(y < 10)							 //
		cout << "   ";				 // This makes the graph look nice by setting bars equal length from number regardless of how many characters in number
	else								 //
	cout << " ";

	cout << " ( ";
	if(graphNum[y] < 10 && y >= 10)
	{
	cout << "  ";				 // This makes the graph look nice by setting bars equal length from number regardless of how many characters in number
	}
	else if(graphNum[y] < 10 && y < 10)
	{
		cout << " ";
	}
	else 
	{
	cout << " ";
	}
	cout << graphNum[y] << ")" << ":";
	strCntr = 1;						 // initialize strCntr and reintialize each time before it starts displaying stars

		while(strCntr <= graphNum[y])	 // This loop puts out a certain number of stars with the according index number
		{								 //
			cout << "*";				 // 
			strCntr++;					 // Increment strCntr
		}								 //

	cout <<endl;
}										 //
//--------------------------------		 //
stop:
system("PAUSE");
	return 0;
}