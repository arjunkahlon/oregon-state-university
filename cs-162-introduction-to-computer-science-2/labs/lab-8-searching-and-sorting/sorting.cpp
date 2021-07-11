/****************************************************
This is the declaration file for sorting function.
*****************************************************/

#include "sorting.h"

string sorting(string filename, int* array, int arraySize)
{
	ofstream outFile;
	string outputName;
	int temp;

	cout << "\nWhat would you like to name the output file: ";
	getline(cin, outputName);

	outFile.open(outputName.c_str());


	for (int i = 0; i < arraySize; i++)
	{
		for (int j = i+1; j < (arraySize - i); j++)
		{
			if (array[i] > array[j])
				{
					temp = array[i];
	         		array[i] = array[j];
					array[j] = temp;
				}
		}

	}
	cout << "Sorted values of " << filename << ": ";
	for (int i = 0; i < arraySize; i++)
	{
		cout << array[i] << " ";
		outFile << array[i];
	}
	outFile.close();
	cout << endl;
	return outputName;
}
