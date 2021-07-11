/****************************************************
This is the definition file for binarySearch function.
*****************************************************/

#include "binarySearch.h"



int binarySearch(int *array, int l, int r, int target)
{
	if (r >= 1)
	{
		int array[10];

		int mid = l + (r - 1) / 2;
		if (array[mid] == target)
		{
			return mid;
		}
		if (array[mid] > target)
		{
			return binarySearch(array, 1, mid-1, target);
		}
		return binarySearch(array, mid + 1, r, target);
	}
	return -1;
}
