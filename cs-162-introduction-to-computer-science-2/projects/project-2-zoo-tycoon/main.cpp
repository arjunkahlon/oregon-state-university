/*************************************************************************
main.cpp: This is the main function for the program. It includes a function
that verifies the input of a range of integer types. It includes Zoo.h.
************************************************************************/

#include "Zoo.h"

#include <iostream>
#include <limits>

using namespace std;


int getInput(int min, int max);

int main()
{
	Zoo zoo;
	int dayNum = 0;
	char userInput, userContinue;
	int animalChoice = 0;
	bool userQuit = false;
	bool inputSuccess, inputSuccess2;

	cout << "\nWelcome to zoo tycoon. Your starting balance is $100,000.";     //tells user starting balance
    cout << " You will begin by choosing quantities of 1 or 2 of the following animals: tigers, penguins, turtles." << endl << endl;

	cout << "\nPlease enter how many tigers you would like to purchcase (1 or 2): ";     //initial tigers
	zoo.buyAnimals(getInput(1, 2), 1, Zoo::tiger);

	cout << "\n\nPlease enter how many penguins you would like to purchcase (1 or 2): ";      //initial penguins
	zoo.buyAnimals(getInput(1, 2), 1, Zoo::penguin);

	cout << "\n\nPlease enter how many turtles you would like to purchcase (1 or 2): ";       //initial turtles
	zoo.buyAnimals(getInput(1, 2), 1, Zoo::turtle);
	cout << endl;

	do            //game loop
	{
		cout << "\nToday is Day " << ++dayNum << endl;      //Current Day
		zoo.dayOccurs();     //subtracts feeding costs, generated random event, calculates payoff
		cout << "\nYour current balance is $" << zoo.getBalance() << endl;      //Current balance

		do
        {
           cout << "\nBefore Day " << dayNum << " is over, would you like to buy an Adult animal? (Enter yes or no): ";
		   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		   cin.clear();
		   cin.get(userInput);
		   if (userInput == 'Y' || userInput == 'y')     //If user wants to buy another animal
		   {
			   cout << "\n1. Tiger" << endl;
			   cout << "2. Turtle" << endl;
			   cout << "3. Penguin" << endl;

			   cout << "\nPlease enter choice from the above options: ";
			   animalChoice = getInput(1, 3);
			   zoo.buyAnimals(1, 3, static_cast<Zoo::animal_t>(animalChoice - 1));
               inputSuccess2 = true;
		   }
           else if (userInput == 'N' || userInput == 'n')
           {
               inputSuccess2 = true;
           }
           else
            {
               cout << "\n\nInvalid input." << endl;    //User does not enter y or n
               inputSuccess2 = false;
            }
        } while (!inputSuccess2);

		do       //loop that prompts user on whether to continue or exit
		{
			cout << "\nDay " << dayNum << " is complete. Would you like to continue? (Enter yes or no): ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.clear();
			cin.get(userContinue);
			if (userContinue == 'Y' || userContinue == 'y')
			{
				cout << "\nYou have chosen to continue. Game will proceed to next day." << endl << endl;
				userQuit = false;
				inputSuccess = true;
			}
			else if (userContinue == 'N' || userContinue == 'n')
			{
				cout << "\nYou have chosen to quit. Game will now exit." << endl;
				userQuit = true;
				inputSuccess = true;
			}
			else
			{
				cout << "\n\nInvalid input." << endl;
				inputSuccess = false;
			}
		} while (!inputSuccess);
	} while (!userQuit || zoo.getBalance() < 0);     //ends if user chooses to quit or if balance falls below $0

	if (zoo.getBalance() < 0)    //if balance if below 0, program informs user that the game is over
	{
		cout << "Sorry, your balance has fallen below $0. Game will now end." << endl;
	}

	//zoo.deleteArrays();        //frees the memory by deleted dynamically allocated memory

	//system("Pause");

	return 0;
}

int getInput(int min, int max)
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

/*
void zooTest1()              //this required all members of Zoo to be public
{
	Zoo z1;

	for (int i = 0; i < 5; i++)
	{
		z1.buyAnimal(2, 1, Zoo::tiger);
		cout << z1.capacityTiger << "    this should be 10" << endl;
	}
	z1.buyAnimal(2, 1, Zoo::tiger);
	cout << z1.capacityTiger << "        this should be 20" << endl;
	cout << z1.sizeTiger << "         this should be 12" << endl;

	for (int i = 0; i < z1.sizeTiger; i++)
	{
		cout << z1.tigers[i]->getAge() << endl;
	}

}
*/
