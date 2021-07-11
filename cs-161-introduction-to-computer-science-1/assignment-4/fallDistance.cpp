/***************************************************************
 *** Author : Arjun Kahlon
 *** Date: April 24, 2017
 *** Description: This program promps the user to enter a double value 
 *** for fall time, and passes that value into a function named
 *** fallDistance. The function plugs that value into t in the formula
 *** d = ((1/2) * g * (t*t)) and returns d (for distance).
 *****************************************************************/

#include <iostream>
#include <math.h>

using namespace std;

double fallDistance(double a);    //function declaration

/*
int main ()
{
  double input;

  cout << "Please enter a value (to two decimal spaces) for falling time" << endl;
  cin >> input;

  cout << fallDistance(input) << endl;    //function call

  return 0;
}
*/

double fallDistance(double a)
{
double distance;
double g = 9.8;

distance = (1.00/2.00)*g*(pow(a,2.00));   //calculates distance

return distance;         //function return
}
