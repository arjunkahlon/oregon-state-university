/***********************************************
bufferSimulation.cpp: This is the definition
file for my bufferSimulation function. It 
includes the definition for getInput function.
***********************************************/

#include "bufferSimulation.h"

void bufferSimulation()
{
	queue<int> q;
	int rounds;          //total rounds (LCV)
	int percentInsert;   //percent chance to put RNG number 
	int percentRemove;   //percent chance to remove RNG number
	int n = 0;          //RNG number that will be later randomized
	int percentageChance; //Randomly generated percentage chance
	double averageLength = 0;

	cout << "How many rounds would you like to play: ";
	rounds = getInput(1, 2147483647);

	cout << "What percentage chance to put randomly generated number at end of buffer: ";
	percentInsert = getInput(0, 100);

	cout << "What percentage chance to remove randomly generated number at end of buffer: ";
	percentRemove = getInput(0, 100);

	for (int i = 1; i <= rounds; i++)
	{
		n = rand() % 1000 + 1;        //randomly generated number
		percentageChance = rand() % 100 + 1;
		if (percentageChance <= percentInsert)
		{
			q.push(n);   //inset n
		}

		percentageChance = rand() % 100 + 1;
		if ((percentageChance <= percentRemove) && !q.empty())
		{
			q.pop();   //remove
		}

		queue<int> copy(q);  //creates a copy of queue for the purposes of printing the queue
		while (!copy.empty())
		{
			cout << copy.front() << " ";
			copy.pop();
		}
		cout << endl << "Length of the buffer: " << q.size() << endl;
		averageLength = (averageLength * (i - 1) + q.size()) / i;   //formula for average Length

		cout << "Average Length: " << averageLength << endl << endl;
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
