#include "bufferSimulation.h"
#include "palindrome.h"

void printMenu();

int main()
{ 
	int userChoice = 0;   //initialized user choice
	bool menuExit = false;  //menu control variable

	do
	{	
		printMenu();  //prints menu
		userChoice = getInput(1, 3);  //validates user input
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (userChoice == 1)
		{
			bufferSimulation();  //runs buffer simulation
		}
		else if (userChoice == 2)
		{
			palindrome();   //runs palindrome
		}
		else
		{
			menuExit = true;   //menu exits
		}
	} while (!menuExit);
	

	return 0;
}

void printMenu()
{
	cout << "\n1. Test the Buffer";
	cout << "\n2. Create a palindrome";
	cout << "\n3. Exit";
	cout << "\n\nPlease choose from the above options: ";
}



