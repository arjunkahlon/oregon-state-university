/*******************************************************
This is the main function for Lab 8.
*******************************************************/

#include "readValues.h"
#include "simpleSearch.h"
#include "sorting.h"
#include "binarySearch.h"
#include <limits>

int getInput(int min, int max, string);

int main()
{
	int original[10];     //array to hold the value in original.txt
	int early[10];        //array to hold the values in early.txt
	int middle[10];       //array to hold the values in middle.txt
	int end[10];         //array to hold the values in end.txt
	int target;          //user inputted value that program will search for
	string output1 = " ";
	string output2 = " ";
	string output3 = " ";
	string output4 = " ";


	int arraySizeOrginal =  readValues("original.txt", original);
	int arraySizeEarly = readValues("early.txt", early);
	int arraySizeMiddle = readValues("middle.txt", middle);
	int arraySizeEnd = readValues("end.txt", end);


	cout << "What is target value: ";
	target = getInput(-2147483647, 2147483647, "Please enter an integer");


	cout << "\nSearching for target value" << endl << endl;
	simpleSearch("original.txt", original, target, arraySizeOrginal);
	simpleSearch("early.txt", early, target, arraySizeMiddle);
	simpleSearch("middle.txt", middle, target, arraySizeMiddle);
	simpleSearch("end.txt", end, target, arraySizeEnd);


	cout << "\nSorting the files" << endl << endl;
	output1 = sorting("original.txt", original, arraySizeOrginal);
	output2 = sorting("early.txt", early, arraySizeEarly);
	output3 = sorting("middle.txt", middle, arraySizeMiddle);
	output4 = sorting("end.txt", end, arraySizeEnd);


	int result;
	int newOriginal[10];
	int newEarly[10];
	int newMiddle[10];
	int newEnd[10];

	readValues(output1, newOriginal);
	readValues(output2, newEarly);
	readValues(output3, newMiddle);
	readValues(output4, newEnd);



	result = binarySearch(newOriginal, 0, arraySizeOrginal - 1, target);
	if (result == -1)
	{
		cout << "\nValue is not in array (Original)" << endl;
	}
	else
	{
		cout << "\nValue was found in array (Original)" << endl;
	}

	result = binarySearch(newEarly, 0, arraySizeEarly - 1, target);
	if (result == -1)
	{
		cout << "\nValue is not in array (Early)" << endl;
	}
	else
	{
		cout << "\nValue was found in array (Early)" << endl;
	}

	result = binarySearch(newMiddle, 0, arraySizeMiddle - 1, target);
	if (result == -1)
	{
		cout << "\nValue is not in array (Middle)" << endl;
	}
	else
	{
		cout << "\nValue was found in array (Middle)" << endl;
	}

	result = binarySearch(newEnd, 0, arraySizeEnd - 1, target);
	if (result == -1)
	{
		cout << "\nValue is not in array (End)" << endl;
	}
	else
	{
		cout << "\nValue was found in array (End)" << endl;
	}


	return 0;
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
