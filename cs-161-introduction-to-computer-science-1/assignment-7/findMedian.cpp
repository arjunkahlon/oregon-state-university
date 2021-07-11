/***************************************************************
*** Author : Arjun Kahlon
*** Date: May 14, 2017
*** Description: This functions takes two parameters, an array of
*** int and an int value for arraySize. It then sorts the array in
*** ascending order using Bubble Sort. It then returns a median, by
*** utilizing conditional statements which account for whether the 
*** size of the array is even or odd. 
********************************************************************/
#include <iostream>
using namespace std;

double findMedian(int [], int);

double findMedian(int array[], int arraySize)
{

  int flag = 1;
  int temp;

  for (int x = 0; x < arraySize; x++)
  {
     cout << array[x] << endl;
  }

  cout << endl;

  for(int a = 1; (a <= arraySize) && flag; a++)    //bubble sort
  {
    flag = 0;
    for(int b = 0; b < arraySize-1; b++)
    {
      if (array[b] > array[b+1])
       {
         temp = array[b];
         array[b] = array[b+1];
         array[b+1] = temp;
         flag = 1;
       }
    }

   }


  for (int x = 0; x < arraySize; x++)
  {
    cout << array[x];
    cout << endl;
  }

  cout << endl;

  if(arraySize % 2 == 0)  //array size is even
  {
    return ((array[(arraySize/2)-1] + (array[(arraySize/2)]))/2.00);
  }
  else                    //array size is odd
  {
    return  array[(arraySize-1)/2];
  }

}

