/************************************************************
Beginning.cpp: This is the defnition file for my Beginning
class.
************************************************************/

#include "Beginning.h"



Beginning::Beginning(string hint)
{
	riddleHint = hint;
}

void Beginning::printOptions()
{
	cout << "\nRoom 1" << endl;
	cout << "\nOptions: " << endl;

	if (!pickedUpRiddle)
	{

		cout << "1. Pick up Riddle Hint" << endl;
		cout << "2. Proceed to right room" << endl;
		cout << "3. Proceed to bottom room and take the detour" << endl;
	}
	else  //if riddle hint is picked up
	{
		cout << "1. Proceed to right room" << endl;
		cout << "2. Proceed to bottom room and take the detour" << endl;
	}
}

bool Beginning::validateChoice(int c)
{
	if (!pickedUpRiddle)
	{
		return (c >= 1 && c <= 3);  //validates user input
	}

	return (c >= 1 && c <= 2);
}

Space * Beginning::doChoice(int c, vector<string> *bag, int capacity)
{
	if (validateChoice(c))  //ensures that user choice is valid
	{
		if (!pickedUpRiddle)
		{
			if (c == 1)
			{
				pickedUpRiddle = true;
				bag->push_back(riddleHint);  //adds riddle hint to bag
				if (bag->size() > capacity)  //replaces oldest riddle hint if bag exceeds capacity
				{
					cout << "\nThe oldest hint in the bag has been removed to make room for the new Riddle Hint" << endl;
					bag->erase(bag->begin());
				}
				return this;  //returns current Space object
			}
			else if (c == 2)
			{
				return move(right);  //moves to Space to the right
			}
			else
			{
				return move(down);   //moves to Space to the bottom
			}
		}
		else
		{
			if (c == 1)
			{
				return move(right);
			}
			else
			{
				return move(down);
			}
		}
	}
	return this;
}

void Beginning::reset()
{
	pickedUpRiddle = false;  //resets boolean value for next game iteration
}

Beginning::~Beginning()  //no allocated memory that needs to be cleared
{
}
