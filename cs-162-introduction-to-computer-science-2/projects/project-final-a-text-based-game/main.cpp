/************************************************************
main.cpp: This the main function for the Final Project. It
contains the game loop. 
************************************************************/

#include <iostream>
#include <cstdlib>
#include "Space.h"
#include "Beginning.h"
#include "Passage.h"
#include "Final.h"
#include "getInput.h"

void printPlay();

int main()
{
	vector<string> bag;
	bool play = false;
	int userPlay = 0;

	//Beginning Room
	Beginning startingRoom("What do you need to do after you bathe?");
	int userInput;
	int steps = 0;
	const int totalSteps = 20;
	Space* currentSpace = &startingRoom;

	//Riddle Room 1
	string choices1[5] = { "dog", "cat", "kitchen floor", "towel", "clothes"};
	Passage p1("Room 2", "What gets wetter as it dries?", 4, choices1, 5, "Think geography");
	startingRoom.setRightLink(&p1);

	//Riddle Room 2
	string choices2[6] = { "clown", "mime", "river", "puppet", "alligator" };
	Passage p2("Room 3", "What runs but never walks, has a mouth but never talks?", 3, choices2, 5, "A mouth without teeth");
	p1.setRightLink(&p2);

	//Detour Room 1
	string detourChoices1[5] = { "addition", "short", "word", "letters", "pony" };
	Passage d1("Detour Room 1", "What word becomes shorter when you add two letters?", 2, detourChoices1, 5, "It's in the riddle");
	startingRoom.setBottomLink(&d1);

	//Detour Room 2
	string detourchoices2[5] = { "photographs", "cookies", "flowers", "seashells", "footsteps" };
	Passage d2("Detour Room 2", "The more of these you take, the more you leave", 5, detourchoices2, 5, "Walks on the beach are nice");
	d1.setRightLink(&d2);
	

	//Final Room
	string finalChoices1[5] = { "kayak", "scooter", "cart", "motorcycle", "chariot"};
	string finalChoices2[5] = { "a, a, s", "t, t, t", "e, s, t", "e, n, t", "t, n, t"};
	Final finalRoom("Which of the following choices is the same word type as: racecar?", "Complete this sequence of letters: o, t, t, f, f, s, s, _, _, _", 1, 4, finalChoices1, finalChoices2, 5, 5, "Think backwards", "Start Counting");
	p2.setRightLink(&finalRoom);
	d2.setRightLink(&finalRoom);

	cout << "Welcome to Riddle Dungeon. In this game, you will make your way through the dungeon by answering a riddle in each room." << endl;
	cout << "\nEach room contains a Riddle Hint that can be picked up and stored in your Riddle Hint Bag. ";
	cout << "This bag has a capacity of 4 Riddle Hints.\nWhen you exceed this capactiy, your oldest hint will be discarded." << endl;
	cout << "Riddle Hints do not necessarily correspond to the Room they are picked up in. Be warned!" << endl;
	cout << "\nYou will have " << totalSteps << " total steps. Answering a riddle will count as a step. As will picking up a Riddle Hint.";
	cout << "\nMoving to the next room will also count as a step. Use your steps wisely." << endl;
	cout << "\nThere are two paths to this game. You can continue right to take the normal path. Or you can travel down to take the detour path." << endl;
	cout << "If you get stuck on one path, you can return to the starting room and take the other path." << endl;
	cout << "\nTo win the game, you must complete the Final Room Challenge within " << totalSteps << " steps. Good luck!" << endl;

	printPlay();
	userPlay = getInput(1, 2);
	if (userPlay == 1)
	{
		play = true;  //starts game
	}

	while (play)
	{
		while (steps < totalSteps)  //LCV
		{
			do
			{
				cout << "\nSteps Remaining: " << (totalSteps - steps) << endl;  //outputs remaining steps
				if (!bag.empty())
				{
					cout << "\nYour Riddle Hint bag contains: " << endl << endl;  //prints Riddle Hint Bag
					for (vector<string>::const_iterator i = bag.begin(); i != bag.end(); ++i)
					{
						cout << *i << endl;
					}
					cout << endl << endl;
				}
				currentSpace->printOptions();
				cout << "\nPlease enter a choice: ";
				userInput = getInput(1, 10);  //verifies user Input 
			} while (!currentSpace->validateChoice(userInput));


			currentSpace = currentSpace->doChoice(userInput, &bag, 4);
			steps++;
			if (currentSpace == nullptr)  //returns user to starting room
			{
				currentSpace = &startingRoom;
			}
			if (currentSpace->checkWin())  //checks if user correctly answered Riddles in Final Room
			{
				cout << "\nYou have won the game!" << endl;
				break;
			}
		}
		if (steps == totalSteps)  //tells the user that they lost for exceeding step limit
		{
			cout << "\n\nYou have gone over the step limit. You lose!" << endl;
		}
		printPlay();  //Play Again
		userPlay = getInput(1, 2);
		if (userPlay == 1)  //resets all boolean values for next game iteration
		{
			startingRoom.reset();
			p1.reset();
			p2.reset();
			d1.reset();
			d2.reset();
			finalRoom.reset();
			currentSpace = &startingRoom;
			bag.clear();
			steps = 0;
		}
		else
		{
			play = false;  //exits game
		}
	}

	return 0;
}

void printPlay()
{
	cout << "\n1. Play Riddle Dungeon";
	cout << "\n2. Exit";
	cout << "\n\nPlease choose from the above options: ";
}
