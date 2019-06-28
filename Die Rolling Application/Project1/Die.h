//Jonathan Winters
//Zack Schunk
//Audra Joslyn
#include <iostream>
#include <iomanip>
#ifndef DIEHEADER_H_INCLUDED
#define DIEHEADER_H_INCLUDED
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    : Die                                          	*
//*                                                                     *
//* Written by      : Jonathan Winters									*
//*					  Zack Schunk										* 
//*                   Audra Joslyn                                      * 
//* Purpose         : To declare Die class and give them members	    * 
//*																		* 
//*																		* 
//*									                                    * 
//*                                                                     * 
//* Inputs          :												    * 
//*                                                                     *
//*											                            * 
//*											                            * 
//*                                                                     * 
//* Outputs         :	getNum returns the num variable value		    * 
//*																		*
//*                                                                     * 
//* Calls           : No internal or external calls.                    *
//*															            * 
//*                                                                     * 
//*---------------------------------------------------------------------* 
//* Change Log:                                                         * 
//*                         Revision                                    * 
//*       Date    Changed  Rel Ver Mod Purpose                          * 
//* 02/09/16      jwinters 000.000.000 Initial release of class         * 
//*                                                                     * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
using namespace std;

class Die
{
public:
	Die();
	//Default constructor
	//Sets the default number rolled by a die to 1
	void roll();
	//Function to roll a die.
	//This function uses a random number generator to randomly
	//generate a number between 1 and 6, and stores the number
	//in the instance variable num
	int getNum() const;
	//Function to return the number on the top face of the die.
	//Returns the value of the instance variable num.
private:
	int num;
};

#endif