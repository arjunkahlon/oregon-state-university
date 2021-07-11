/************************************************
arraySum.cpp: This is the delcaration file for
my arraySum function. Is uses recursion to 
calculate the sum of an array
************************************************/

#include "arraySum.h"

#include <iostream>
using namespace std;

int arraySum(int array[], int size)
{
   if (size == 1)    //array size is 1 element
   {
      return array[0];  //return the element
   }
   else 
   {
      return array[0] + arraySum(array + 1, size - 1); //recursive definition
   }
}

