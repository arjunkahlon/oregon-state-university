/****************************************************************
main.cpp: This is the main function for Lab 7. It includes the
header file for my Queue class. All Queue functions are defined
in the Queue.cpp file. 
***************************************************************/

#include "Queue.h"
#include <iostream>
#include <limits>

using namespace std;

void printMenu();
int getInput(int min, int max);
void addToQueue(Queue &);

int main()
{
	Queue q1;           //creates Queue 
	int userChoice, val;
	bool menuExit = false;      //loop LCV
	do
	{
		printMenu();  //displays menu options
		userChoice = getInput(1, 5);  //stores user Input into userChoice. getInput validates input
		switch (userChoice)   //switch case for userChoice
		{
		case 1:
			addToQueue(q1);    //addToQueue declared and defined within main function. push() used to add value to q1. 
			break;
		case 2:
			if (q1.isEmpty())     //checks to see if Queue is empty
				cout << "\nThere are no stored values in the Queue" << endl;
			else
				cout << "\nThe first node value is " << q1.getFront() << endl;   //shows value stored in head node
			break;
		case 3:
			q1.removeFront();      //deletes head node and sets head pointer to former head->next
			break;
		case 4:
			q1.printQueue();  //displays the Queue to the user
			break;
		case 5:
			menuExit = true;   //user choose to exit menu
			break;
		}
	} while (!menuExit);
	
	return 0;
}

void printMenu()
{
	cout << "\n1. Enter a value to be added to the back of queue";
	cout << "\n2. Dispaly the first node (front) value";
	cout << "\n3. Remove the first node (front) value";
	cout << "\n4. Display the queue's content";
	cout << "\n5. Exit" << endl; 

	cout << "\nPlease choose from the above options: ";
}

int getInput(int min, int max)       //input verification function
{
	int userInput;
	do
	{
		cin >> userInput;
		if (userInput < min || userInput > max)  //defined in function call
		{
			cout << "\n\nPlease enter a number from " << min << " to " << max << ": ";
		}
		if (cin.fail())
		{
			cin.clear();   ///clears input buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (userInput < min || userInput > max);

	return userInput;
}

void addToQueue(Queue &queue)
{
	int value;
	
	cout << "\nPlease enter a positive integer: ";
	value = getInput(1, 2147483647);   //had to hard code INT_MAX since FLIP's server doesn't support it 
	queue.addBack(value);       //adds value to Queue
}
