/************************************************************
menuLangton.cpp : This is the declaration file for menuLangton
formula. This prompts the user to select between two options
and returns a boolean value.
*************************************************************/

#include "menuLangton.h"

bool menuLangton()
{
	int userChoice;

	do
	{

		cout << "\n1. Start Langton's Ant simulation";
		cout << "\n2. Quit";
		cout << "\n\nPlease choose from the above options: ";
		cin >> userChoice;
	} while (userChoice != 1 && userChoice != 2);     //loops if user enters int value other than 1 or 2

	if (userChoice == 1)        //Start Langton's Ant simulation
	{
		return true;
	}
	else if (userChoice == 2)        //Quit
	{
		return false;
	}
}