/***************************************************************
 * Author : Arjun Kahlon
 * Date: April 17, 2017
 * Description: This program asks the user to enter a specified
 * number of integers, and this program determines the min and 
 *  max values,
 ****************************************************************/

#include <iostream>

using namespace std;

int main()
{
int input = 0;
int  max = 0;
int min = 0;
int numTotal = 0;

cout << "How many integers would you like to enter" << endl;
cin >> numTotal;

cout << "Please enter " << numTotal << " integers." << endl;

cin >> input;
max = input;
min = input;

for (int x = 0; x < numTotal-1; x++)
{
   cin >> input;
   if (input > max)
    {
     max = input;
    }
   if (input < min)
    {
     min = input;
    }
}

cout << "min: " << min;
cout << "\nmax: " << max << endl;


return 0;
}

