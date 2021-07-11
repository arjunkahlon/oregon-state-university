/**********************************************************************************************
main.cpp: This is my main file for Project 4.
**********************************************************************************************/

#include "Character.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Vampire.h"
#include "Medusa.h"
#include "HarryPotter.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include <limits>
#include <string>

void printCharacterMenu(int);
void printPlay(string);
Character* getCharacter(int, string);
int getInput(int min, int max, string);
Character* battle(Character*, Character*);

int main()
{
    Queue q1, q2;      //teams
    Stack s;         //loser pile
    bool play = false;   //Loop Control Variable
    int fighterNum, fighterChoice, rounds = 0, team1 = 0, team2 = 0, userPlay = 0, playAgain = 0;
    string viewStack;

    printPlay(" ");
    userPlay = getInput(1, 2, "Please choose 1 or 2");

    if (userPlay == 1)
    {
        play = true;
    }

	while (play)
	{
		cout << "Welcome to Fantasy Combat Tournament. Please enter the number of fighters you would like for each team: ";
		fighterNum = getInput(1, 2147483647, "Please enter a positive number 1 or higher");

		cout << "\n\nChoose fighers for Team 1" << endl << endl;

		for (int i = 0; i < fighterNum; i++)    //fills team
		{
			string fighterName = " ";

			printCharacterMenu(i + 1);
			fighterChoice = getInput(1, 5, "Please choose a value from 1 to 5");
			cout << "Please enter a name for the  fighter: ";
			getline(cin, fighterName);

			q1.insert(getCharacter(fighterChoice, fighterName));   //inserts to Queue

		}

		cout << "\n\nChoose fighers for Team 2" << endl << endl;

		for (int i = 0; i < fighterNum; i++)    //fills team
		{
			string fighterName = " ";

			printCharacterMenu(i + 1);
			fighterChoice = getInput(1, 5, "Please choose a value from 1 to 5");
			cout << "Please enter a name for the  fighter: ";
			getline(cin, fighterName);

			q2.insert(getCharacter(fighterChoice, fighterName));   //inserts to Queue
		}

		while (!q1.isEmpty() && !q2.isEmpty())
		{

			Character* c1 = q1.remove();
			Character* c2 = q2.remove();
			cout << "\n\nRound: " << ++rounds << endl << endl;
			cout << "\nTeam 1: " << c1->getName() << "      " << "Team 2: " << c2->getName() << endl << endl;
			Character* winner = battle(c1, c2);   //battle returns winner

			if (winner == c1)
			{
				cout << endl << c1->getName() << " has won the battle." << endl;
				team1 += 2;  //winner points
				team2 -= 1;  //loser points
				c1->recover();   //winner recovers health
				q1.insert(c1);  //Inserts winner to Queue
				s.push(c2);  //pushes loser to Stack
			}
			else
			{
				cout << endl << c2->getName() << " has won the battle." << endl;
				team2 += 2;  //reference above comments (roles reversed)
				team1 -= 1;
				c2->recover();
				q2.insert(c2);
				s.push(c1);
			}
		}

		cout << "\n\nTeam 1: " << team1 << endl;
		cout << "\n\nTeam 2: " << team2 << endl;

		if (team1 > team2)  //team1 has more points
		{
			cout << "\n\nTeam 1 has won the tournament" << endl;
		}
		else if (team2 > team1)  //team2 has more points
		{
			cout << "\n\nTeam 2 has won the tournament" << endl;
		}
		else  //tie
		{
			cout << "\n\nTeam 1 and Team 2 have tied" << endl;
		}

		cout << "\nWould you like to view the content of the loser pile (yes or no) : ";
		getline(cin, viewStack);  //displays loser pile
		if (viewStack[0] == 'Y' || viewStack[0] == 'y')
		{
			while (!s.isEmpty())
			{
				cout << endl << s.pop()->getName();
			}
			cout << endl;
		}

		printPlay("Again");   //Play Again mennu
		playAgain = getInput(1, 2, "Please choose 1 or 2");
		if (playAgain == 2)
		{
			break;   //program exits
		}
	}




	return 0;
}

void printCharacterMenu(int c)
{
	cout << "\n1. Barbarian";
	cout << "\n2. Vampire";
	cout << "\n3. Blue Men";
	cout << "\n4. Medusa";
	cout << "\n5. Harry Potter";
	cout << "\n\nPlease choose an option for fighter " << c << ": ";
}

void printPlay(string s)
{
	cout << "\n1. Play " << s;
	cout << "\n2. Exit";
	cout << "\n\nPlease choose an option: ";
}

Character* getCharacter(int characterChoice, string name)
{
	switch (characterChoice)
	{
	case 1:
		return new Barbarian(name);
	case 2:
		return new Vampire(name);
	case 3:
		return new BlueMen(name);
	case 4:
		return new Medusa(name);
	case 5:
		return new HarryPotter(name);
	default:
		cout << "\nIncorrect value entered" << endl;
		return NULL;
	}

}

int getInput(int min, int max, string message)       //input verification function
{
	int userInput;
	do
	{
		cin >> userInput;
		if (userInput < min || userInput > max)
		{
			cout << "\n\n" << message << ": ";
		}
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (userInput < min || userInput > max);

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return userInput;
}

Character* battle(Character* c1, Character* c2)
{

	while (true)
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
			return c1;
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
				return c2;
			}
		}
	}
}
