/************************************************************
getInput.cpp: User input verification function for int type.
************************************************************/

#include "getInput.h"

int getInput(int min, int max)
{
	int userInput;
	do
	{
		cin >> userInput;
		if (userInput < min || userInput > max)
		{
			cout << "\nPlease enter a valid choice from above: ";
		}
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (userInput < min || userInput > max);

	return userInput;
}
