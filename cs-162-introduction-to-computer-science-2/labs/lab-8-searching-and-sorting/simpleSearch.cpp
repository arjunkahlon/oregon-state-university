/****************************************************
This is the definition file for simpleSearch function.
*****************************************************/

#include "simpleSearch.h"

void simpleSearch(string filename, int* array, int compare, int arraySize)
{
	int value;
	bool found = false;

	for (int i = 0; i < arraySize; i++)
	{
		if(array[i] == compare)
		{
			found = true;    //value found
		}
	}
	if (found)
	{
		cout << filename << ": target value found" << endl;
	}
	else
	{
		cout << filename << ": target value not found" << endl;
	}

}
