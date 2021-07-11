/************************************************************
Final.cpp: This is the definition file for my Final class.
************************************************************/

#include "Final.h"

Final::Final(string riddle1, string riddle2, int correctAnswer1, int correctAnswer2, string * choices1, string * choices2, int numChoices1, int numChoices2, string hint1, string hint2)
{
	this->riddle1 = riddle1;
	this->riddle2 = riddle2;
	this->correctAnswer1 = correctAnswer1;
	this->correctAnswer2 = correctAnswer2;
	this->choices1 = new string[numChoices1];
	this->choices2 = new string[numChoices2];
	this->numChoices1 = numChoices1;
	this->numChoices2 = numChoices2;
	riddleHint1 = hint1;
	riddleHint2 = hint2;

	//checks if hint1 is included in parameter
	if (riddleHint1.size() > 0 || riddleHint2.size() > 0)
	{
		hintsAvailable = true;
	}
	//fills choices for riddle 1
	for (int i = 0; i < numChoices1; i++)
	{
		this->choices1[i] = choices1[i];
	}
	//fills choices for riddle 2
	for (int i = 0; i < numChoices2; i++)
	{
		this->choices2[i] = choices2[i];
	}
}

void Final::printOptions()
{
	cout << "You have reached the Final Room. BUT...you have not won the game. You must answer the Final Two Riddles." << endl;

	int option = 1; //increments in the conditionals to print menu
	if (!answeredCorrectly1)
	{
		cout << endl << option << ". Answer Riddle 1";
		option++;
	}
	if (!answeredCorrectly2)
	{
		cout << endl << option << ". Answer Riddle 2";
		option++;
	}
	if (hintsAvailable)
	{
		cout << endl << option << ". Pick up two final Riddle Hints";
		option++;
	}
	cout << endl << option << ". Return to starting room";
}

bool Final::validateChoice(int c)  //verifies user input
{
	int option = 1;
	if (!answeredCorrectly1)
	{
		option++;
	}
	if (!answeredCorrectly2)
	{
		option++;
	}
	if (hintsAvailable)
	{
		option++;
	}

	return (c >= 1 && c <= option);
}

Space* Final::doChoice(int c, vector<string> *bag, int capacity)
{
	int option = 1;
	if (!answeredCorrectly1)
	{
		if (c == option)
		{
			doRiddle(1);
			return this;  //returns Current Space
		}
		option++;
	}
	if (!answeredCorrectly2)
	{
		if (c == option)
		{
			doRiddle(2);
			return this;  //returns Current Space
		}
		option++;
	}
	if (hintsAvailable)
	{
		if (c == option)
		{
			bag->push_back(riddleHint1);  //adds hint 1 to riddle bag
			bag->push_back(riddleHint2);  //adds hint 2 to riddle bag
			hintsAvailable = false;
			if (bag->size() > capacity)
			{
				cout << "\nThe oldest hint in the bag has been removed to make room for the new Riddle Hint" << endl;
				bag->erase(bag->begin());  //removes oldest riddle hint to make room for new hint
			}
			if (bag->size() > capacity)
			{
				cout << "\nThe oldest hint in the bag has been removed to make room for the new Riddle Hint" << endl;
				bag->erase(bag->begin());  //removes oldest riddle hint to make room for new hint
			}
			return this;
		}
		option++;
	}
	if (c == option)
	{
		return nullptr;  //return NULL
	}
	else
	{
		return this;   //return Current Space
	}
}

void Final::doRiddle(int r)
{
	int userChoice;

	if (r == 1)
	{
		cout << endl << riddle1 << endl;
		for (int i = 0; i < numChoices1; i++)
		{
			cout << i + 1 << ". " << choices1[i] << endl;   //prints riddle 1 choices
		}
	}
	else
	{
		cout << endl << riddle2 << endl;
		for (int i = 0; i < numChoices2; i++)
		{
			cout << i + 1 << ". " << choices2[i] << endl;   //prints riddle 2 choices
		}
	}

	cout << "Please enter the corresponding int value for your choice: ";
	if (r == 1)
	{
		userChoice = getInput(1, numChoices1);  //verifies user input
	}
	else
	{
		userChoice = getInput(1, numChoices2);  //verifies user input
	}

	if (r == 1 && userChoice == correctAnswer1)
	{
		answeredCorrectly1 = true;
		cout << "\nCorrect!" << endl;
	}
	else if (r == 1 && userChoice != correctAnswer1)
	{
		cout << "\nIncorrect Answer. Try again." << endl;
	}
	if (r == 2 && userChoice == correctAnswer2)
	{
		answeredCorrectly2 = true;
		cout << "\nCorrect!" << endl;
	}
	else if (r == 2 && userChoice != correctAnswer2)
	{
		cout << "\nIncorrect Answer. Try Again." << endl;
	}
}

bool Final::checkWin()
{
	return (answeredCorrectly1 && answeredCorrectly2); //checks if riddle 1 and riddle 2 were answered correctly to verify win
}

void Final::reset()  //resets boolean values for next game iteration 
{
	if (riddleHint1.size() > 0 || riddleHint2.size() > 0)
	{
		hintsAvailable = true;
	}
	answeredCorrectly1 = false;
	answeredCorrectly2 = false;
}

Final::~Final()  //frees allocated memory
{
	delete[] choices1;
	delete[] choices2;
}
