/****************************************************
This is the header file for readValues function.
*****************************************************/

#include "readValues.h"

int readValues(string filename, int *array)
{
	ifstream inFile; //declares input stream
	int a = 0;
	inFile.open(filename.c_str());  //opens file to input from
	while (!inFile.eof())
	{
		inFile >> array[a];  //fills array
		a++;
	}
	inFile.close();
	return a;    //returns size
}
