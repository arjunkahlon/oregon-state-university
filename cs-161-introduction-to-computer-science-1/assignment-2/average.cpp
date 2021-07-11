/************************************************************
 ** Author: Arjun Kahlon
 ** Date: April 10, 2017
 ** Description: This program has the user enter five numbers
 ** ant then calculates the average of the five numbers.
 ************************************************************/


#include <iostream>

using namespace std;

int main ()
{

double average, num1, num2, num3, num4, num5; //double variables 

cout << "Please enter five numbers." << endl;
cin >> num1;
cin >> num2;
cin >> num3;
cin >> num4;
cin >> num5;

average = (num1+num2+num3+num4+num5)/5;   //formula for average

cout << "The average for those numbers is:\n" << average; 



return 0;
} 
