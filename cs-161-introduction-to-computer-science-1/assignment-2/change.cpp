/************************************************************
 * Author: Arjun Kahlon
 * Date: April 10, 2017
 * Description: This program has the user enter an input for
 * change between 0 and 99, and outputs the minimum number of each 
 * coin you would need to reach this amount of change
 * **********************************************************/
  

#include <iostream>

using namespace std;

int main ()
{
int cents;
static int QUARTER = 25; //value of Quarter
static int DIME = 10;    //value of Dime
static int NICKEL = 5;   //value of Nickel 
static int PENNY = 1;    //value of Penny
int numQuarts = 0;
int numDimes = 0;
int numNickels = 0;
int numPennies = 0;

 
cout << "Please enter an amount in cents less than a dollar.\n";
cin >> cents;

numQuarts = (cents / QUARTER);
cents = (cents % QUARTER);   //remainder after dividing by 75

numDimes = (cents / DIME);
cents = (cents % DIME);      //remainder after dividing by 10 

numNickels = (cents / NICKEL);
cents = (cents % NICKEL);    //remainder after dividing by 5

numPennies = (cents / PENNY);
cents = (cents % PENNY);     //remainder after dividing by 1

cout << "Your change will be:\n";
cout << "Q: " << numQuarts << endl;
cout << "D: " << numDimes << endl;
cout << "N: " << numNickels << endl;
cout << "P: " << numPennies << endl;

return 0;
}
