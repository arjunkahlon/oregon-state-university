/***************************************************************
 ** Author: Arjun Kahlon
 ** Date: April 10, 2017
 ** Description: This program has the user input a value for
 ** the temperature in Celsius, and converts this Celsuis value
 ** to Fahrenheight  
*****************************************************************/ 

#include <iostream>

using namespace std;

int main ()
{
double cTemp;  //Celsius Temperature
double cFar;   //Fahrenheight Temperature

cout << "Please enter a Celsius temperature.\n";
cin >> cTemp;

cFar = ((9.00/5.00)*cTemp) + 32;   //calculates Fahrenheight

cout << "The equivalent Fahrenheit temperature is:\n " << cFar; 

return 0;
}

