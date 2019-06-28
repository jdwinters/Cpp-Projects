#include <iostream>
#include "Die.h"
#include <cstdlib>

//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    : DieFunctions.cpp                                  * 
//*                                                                     * 
//* Written by      : Jonathan Winters                                  *
//*					  Zack Schunk										*
//*                   Audra Joslyn			                            * 
//* Purpose         : To define Die objects and do things with them		*
//*																		* 
//*									                                    * 
//*                                                                     * 
//* Inputs          : Die.h prototype definitions					    * 
//*                                                                     *
//*                         Die();										* 
//*							int getNum() const;                         * 
//*											                            * 
//*                         void roll();								* 
//*											                            * 
//*											                            * 
//*												                        * 
//*												                        * 
//* Outputs         : None												* 
//*                   													*
//*                                                                     * 
//* Calls           : No internal or external calls.                    *
//*                   Incline test code for Dice object		            * 
//*                                                                     * 
//*---------------------------------------------------------------------* 
//* Change Log:                                                         * 
//*                         Revision                                    * 
//*       Date    Changed  Rel Ver Mod Purpose                          * 
//* 02/09/16      jwinters 000.000.000 Initial release of class         * 
//*                                                                     * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
using namespace std;

Die::Die()			// Die constructor
{
	num = 1;
	srand(time(0));
}
void Die::roll()	// rolls the die randomly from 1 to 6
{
	num = rand() % 6 + 1;
}
int Die::getNum() const //returns the number, can be used to sum up die
{
	return num;
}
