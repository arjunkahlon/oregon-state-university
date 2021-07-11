/*******************************************************
**Author: Arjun Kahlon
**Date: May 23, 2017
**Decription: This function takes in two parameters, a
**reference to a pointer to an array of doubles, and the
**array size. The function doubles the size of the array,
**and repeats the values in the original array. I tested
**with the included main on Canvas
***********************************************************/

#include <iostream>

using namespace std;

void repeatArray(double *&, int);

void repeatArray(double *&myArray, int arraySize)
{
 int newSize = 0;
 newSize = arraySize * 2;
 double *newArray = new double[newSize];

 for (int i=0; i<arraySize; i++)
 {
      newArray[i] = myArray[i];
 }

 for (int i=0; i<newSize-arraySize; i++)
 {
      newArray[i+arraySize] = myArray[i];
 }

 myArray = newArray;
}

/*int main()
{
 double *myArray = new double[3];
   for (int i=0; i<3; i++)
      myArray[i] = (i+1)*2;

   repeatArray(myArray, 3);

   for (int i=0; i<6; i++)
      cout << myArray[i] << endl;

   delete []myArray;


return 0;
}*/

