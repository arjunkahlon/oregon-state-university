#include "readMatrix.h"

void readMatrix(int** matrixPtr, int s)
{
	cout << "\n\nYou will need to enter in your desired numbers for your " << s << "x" << s << " calculator" << endl;

	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cout << "\nPlease enter a number for index " << "[" << i << "]" << "[" << j << "]: ";
			cin >> matrixPtr[i][j];
		}
	}
}