/*********************************************************************************
main.cpp: This is the test driver for Project 3. It contains the game flow in 
which Characters are chosen. The game carries on until the user chooses to exit.
Memory is cleared at the end of the main function. 
*********************************************************************************/

#include "Barbarian.h"
#include "Vampire.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "HarryPotter.h"
#include <limits>
#include <time.h>

void printCharacterMenu(int);
void printPlayAgain();
Character* getCharacter(int);
int getInput(int min, int max);

int main()
{
	Character* c1 = NULL;         //initializes c1 to NULL
	Character* c2 = NULL;         //initializes c2 to NULL
	int characterChoice, playAgain = 0;
	bool gameEnd = false;      //LCV for Game Loop

	srand(time(0));         //seeds random generated number
 
	do
	{
		if (c1 != NULL)
		{
			delete c1;    //deletes any existing Characters from previous game iteration
			c1 = NULL;    //resets c1 to NULL
		}

		if (c2 != NULL)
		{
			delete c2;   //deletes any previous existing characters
			c2 = NULL;   //resets c2 to NULL
		}

		while (c1 == NULL)
		{
			printCharacterMenu(1);    //prints Character Menu for c1
			characterChoice = getInput(1, 5);
			c1 = getCharacter(characterChoice);   //sets c1 to character
		}

		while (c2 == NULL)
		{
			printCharacterMenu(2);      //prints Character Menu for c2
			characterChoice = getInput(1, 5);
			c2 = getCharacter(characterChoice);  //sets c2 to character
		}

		while (!gameEnd)
		{
			int attackerRoll = c1->attack();      //c1 attacks
			int strenght = c2->getStrength();

			cout << "\n\n1. Attacker Type: " << c1->getType();
			cout << "\n2. Defender Type: " << c2->getType() << " Armor: " << c2->getArmor() << " Strength: " << strenght;
			cout << "\n3. Attacker's Dice Roll: " << attackerRoll;
			if (c1->getType().compare("Medusa") == 0 && attackerRoll == 12)          //Medusa uses glare
			{
				cout << "  ***Medusa uses glare***";
				c2->setStrength(0);
			}

			int defenseRoll = c2->defense(attackerRoll);
			cout << "\n4. Defender's Dice Roll: " << defenseRoll;
			if (defenseRoll == 0)
				cout << "  ****Attacker didn't attack****";        //Vampire uses Charm/Attacker doesn't attack
			cout << "\n5. Total Inflicted Damage: " << strenght - c2->getStrength();
			cout << "\n6. The Defender's Current Strength: " << c2->getStrength();

			if (c2->getStrength() <= 0)
			{
				cout << "\nThe " << c2->getType() << " has perished in battle." << endl << endl;     //Defender dies
				printPlayAgain();    //Play Again Menu
				playAgain = getInput(1, 2);
				if (playAgain == 2)
				{
					gameEnd = true;     //game ends
				}
				break;
			}
			else
			{
				attackerRoll = c2->attack();     //c2 attacks
				strenght = c1->getStrength();

				cout << "\n\n1. Attacker Type: " << c2->getType();
				cout << "\n2. Defender Type: " << c1->getType() << " Armor: " << c1->getArmor() << " Strength: " << strenght;
				cout << "\n3. Attacker's Dice Roll: " << attackerRoll;
				if (c2->getType().compare("Medusa") == 0 && attackerRoll == 12)      //Medusa uses glare
				{
					cout << "   ***Medusa uses glare***";
					c1->setStrength(0);
				}
				defenseRoll = c1->defense(attackerRoll);
				cout << "\n4. Defender's Dice Roll: " << defenseRoll;
				if (defenseRoll == 0)
					cout << "  ****Attacker didn't attack****";       //Vampire uses Charm/Attacker doesn't attack
				cout << "\n5. Total Inflicted Damage: " << strenght - c1->getStrength();
				cout << "\n6. The Defender's Current Strength: " << c1->getStrength();

				if (c1->getStrength() <= 0)
				{
					cout << "\nThe " << c1->getType() << " has perished in battle." << endl << endl;   //Defender dies
					printPlayAgain();
					playAgain = getInput(1, 2);
					if (playAgain == 2)
					{
						gameEnd = true;      //game ends
					}
					break;
				}
			}
		}
	} while (!gameEnd);

	if (c1 != NULL)
	{
		delete c1;
		c1 = NULL;
	}

	if (c2 != NULL)
	{
		delete c2;
		c2 = NULL;
	}

	//system("PAUSE");

	return 0;
}

void printCharacterMenu(int c)
{
	cout << "\n1. Barbarian";
	cout << "\n2. Vampire";
	cout << "\n3. Blue Men";
	cout << "\n4. Medusa";
	cout << "\n5. Harry Potter";
	cout << "\n\nPlease choose an option for character " << c << ": ";
}

void printPlayAgain()
{
	cout << "\n1. Play Again";
	cout << "\n2. Exit";
	cout << "\n\nPlease choose an option: ";
}

Character* getCharacter(int characterChoice)
{
	switch (characterChoice)
	{
	case 1:
		return new Barbarian();
	case 2:
		return new Vampire();
	case 3:
		return new BlueMen();
	case 4:
		return new Medusa();
	case 5:
		return new HarryPotter();
	default:
		cout << "\nIncorrect value entered" << endl;
		return NULL;
	}

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