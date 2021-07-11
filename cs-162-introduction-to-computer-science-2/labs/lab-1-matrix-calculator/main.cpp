#include "readMatrix.h"
#include "determinant.h"


void displayMatrix(int**, int);

int main()
{
	int size = 0;
	int **matrixPtr = NULL;
	bool userInputSuccess = false;

	do
	{
		cout << "How big would you like your matrix calculator calulator to be? \nPlease enter a value for rows and columns(2 for 2x2, 3 for 3x3): ";
		cin >> size;

		if (cin.fail())
		{
			cout << "\nInvalid entry. Please try again." << endl << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else
		{
			if (size == 2 || size == 3)
			{
				matrixPtr = new int*[size];
				userInputSuccess = true;
			}
			else
			{
				cout << "\nInvalid entry. Size is either too big or too small. Please try again." << endl << endl;
			}

		}
	} while (!userInputSuccess);
 
	for (int i = 0; i < size; i++)
	{
		matrixPtr[i] = new int[size];
	}

	readMatrix(matrixPtr, size);

	displayMatrix(matrixPtr, size);
	
	cout << "\n\nThe determinant is " << determinant(matrixPtr, size) << endl << endl;

	for (int i = 0; i < size; i++)
	{
		delete[] matrixPtr[i];
	}
	delete[] matrixPtr;


	return 0;
}


void displayMatrix(int** matrixPtr, int s)
{
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cout << matrixPtr[i][j] << "  ";
		}
		cout << endl;
	}
}

