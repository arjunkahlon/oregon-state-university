/***************************************************************
**** Author : Arjun Kahlon
**** Date: May 15, 2017 
**** Description: This is the declaration and definition file for
**** the function stdDev. It passes in an array of the object Person
**** and returns the standard deviation of the ages. These age 
**** values are passed into the array through constructors in the 
**** main.   
******************************************************************/

#include "Person.hpp"

double stdDev(Person[], int);

double stdDev(Person people[], int arraySize)
{
  double sum = 0;
  double mean = 0;

  for (int i = 0; i < arraySize; i++)

  {
    sum += people[i].getAge();
  }

  mean = (double)sum/(double)arraySize;

  sum = 0;

  for (int a = 0; a < arraySize; a++)
  {
    sum += pow((people[a].getAge() - mean),2);
  }
  return sqrt(sum/arraySize);
}

