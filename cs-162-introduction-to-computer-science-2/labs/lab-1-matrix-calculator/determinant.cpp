#include "determinant.h"

int determinant(int** matrixPtr, int s)
{
	if (s == 2)
	{
		return (matrixPtr[0][0] * matrixPtr[1][1]) - (matrixPtr[0][1] * matrixPtr[1][0]);
	}
	else if (s == 3)
	{
		int a = matrixPtr[0][0];
		int b = matrixPtr[0][1];
		int c = matrixPtr[0][2];
		int d = matrixPtr[1][0];
		int e = matrixPtr[1][1];
		int f = matrixPtr[1][2];
		int g = matrixPtr[2][0];
		int h = matrixPtr[2][1];
		int i = matrixPtr[2][2];

		return (a * ((e*i) - (f*h))) - (b * ((d*i) - (f*g))) + (c * ((d*h) - (e*g)));
	}
}