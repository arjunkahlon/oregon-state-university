/*************************************************************
Passage.cpp: This is the definition file for my Passage class.
*************************************************************/

#include "Passage.h"




Passage::Passage(string roomNum, string riddle, int correctAnswer, string* choices, int numChoices, string hint)
{
	this->roomNum = roomNum;
	this->riddle = riddle;
	this->correctAnswer = correctAnswer;
	this->choices = new string[numChoices];
	this->numChoices = numChoices;
	riddleHint = hint;
	if (riddleHint.size() > 0)   //checks to see if riddle hint was actually inputted
	{
		hintAvailable = true;
	}

	for (int i = 0; i < numChoices; i++)
	{
		this->choices[i] = choices[i];
	}
}

void Passage::printOptions()
{
	cout << roomNum << endl;
	cout << "Options: " << endl;

	if (!answeredCorrectly && hintAvailable)
	{
		cout << "\n1. Answer the Riddle";
		cout << "\n2. Pick up Riddle Hint";
		cout << "\n3. Return to starting room";
	}
	else if (!answeredCorrectly && !hintAvailable)
	{
		/*for (std::vector<string>::const_iterator i = bag.begin(); i != bag.end(); ++i)
			std::cout << *i << endl;*/

		cout << "\n1. Answer the Riddle";
		cout << "\n2. Return to starting room";
	}

	else
	{
		if (hintAvailable)
		{
			cout << "1. Proceed to right room" << endl;
			cout << "2. Pick up Riddle Hint" << endl;
			cout << "3. Return to starting room" << endl;
		}
		else
		{
			cout << "1. Proceed to right room" << endl;
			cout << "2. Return to starting room" << endl;
		}
	}
}

bool Passage::validateChoice(int c)
{
	if (hintAvailable)
	{
		return (c >= 1 && c <= 3);    //validates user input
	}

	return (c == 1 || c == 2);
}

Space * Passage::doChoice(int choice, vector<string> *bag, int capacity)
{
	
	if (!answeredCorrectly && hintAvailable)
	{
		switch (choice)
		{
		case 1:
			doRiddle();
			return this;  //remain on current Space
		case 2: 
			bag->push_back(riddleHint);
			hintAvailable = false;
			if (bag->size() > capacity)  //if bag exceeds capacity
			{
				cout << "\nThe oldest hint in the bag has been removed to make room for the new Riddle Hint" << endl;
				bag->erase(bag->begin());   //removes oldest riddle hint
			}
			return this;
		case 3: 
			return nullptr;
		}
	}
	else if (!answeredCorrectly && !hintAvailable)
	{
		switch (choice)
		{
		case 1:
			doRiddle();
			return this;
		case 2:
			return nullptr;
		}
	}
	else
	{
		if (hintAvailable)
		{
			switch (choice)
			{
			case 1:
				return move(right);  //move to right space
			case 2:
				bag->push_back(riddleHint);  //adds riddle hint to bag
				hintAvailable = false;
				if (bag->size() > capacity)  //if bag exceeds capacity
				{
					cout << "\nThe oldest hint in the bag has been removed to make room for the new Riddle Hint" << endl;
					bag->erase(bag->begin());  //removes oldest riddle hint
				}
				return this;
			case 3:
				return nullptr;
			}
		}
		else
		{
			switch (choice)
			{
			case 1:
				return move(right);
			case 2:
				return nullptr;
			}
		}
	}
	return this;
}

void Passage::doRiddle()
{
	int userChoice;

	cout << endl << riddle << endl;
	for (int i = 0; i < numChoices; i++)   //prints choices to screen
	{
		cout << i+1 << ". " << choices[i] << endl;
	}

	cout << "Please enter the corresponding int value for your choice: ";
	userChoice = getInput(1, numChoices);  //validates user input 

	if (userChoice == correctAnswer)
	{
		cout << "\nCorrect!" << endl;
		answeredCorrectly = true;
	}
	else
	{
		cout << "\nIncorrect Answer. Try again." << endl;
	}

}

void Passage::reset()   //resets booleans for next game ieration 
{
	if (riddleHint.size() > 0)
	{
		hintAvailable = true;
	}
	answeredCorrectly = false;
}

Passage::~Passage()
{
	delete[] choices;  //frees allocated memory
}
