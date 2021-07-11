/*********************************************************
printMenu.cpp: Definition file for printMenu function.
Includes input verification which only allows the user
to input an int variable between 1 and 6. The function
getInput verifies input. 
*********************************************************/

#include "printMenu.h"

int getInput(int min, int max); 

int printMenu()
{
   int choice;
  
   cout << "\n1. Add a new node to the head";
   cout << "\n2. Add a new node to the tail";
   cout << "\n3. Delete from head";
   cout << "\n4. Delete from tail";
   cout << "\n5. Traverse the list reversely";
   cout << "\n6. Exit";
   cout << "\n\nPlease choose from the above options: ";
   choice = getInput(1, 6);

   return choice;
}

int getInput(int min, int max)       //input verification function
{
	int userInput;
	do
	{
		cin >> userInput;
		if (userInput < min || userInput > max)
		{
			cout << "\n\nPlease enter a number from " << min << " to " << max << ": ";
		}
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (userInput < min || userInput > max);

	return userInput;
}
