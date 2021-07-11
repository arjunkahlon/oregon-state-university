/***************************************************************
 **** Author : Arjun Kahlon
 **** Date: April 24, 2017
 **** Description: This program promps the user to enter a starting
 **** integer and then passes that integer value into a function
 **** named hailstone. I then used a while statement that made the 
 **** loop run until the int reached 1. If the int was even, I divided 
 **** it by 2. If it was odd, I multiplied it by 3 and added 1. The
 **** loop runs untli the int reaches 1. I included a tally at the bottom
 **** of the while loop in order to count the number of times the loop ran.
 **** The function returns tally, which is an int variable.
******************************************************************/

#include <iostream>

using namespace std;

int hailstone (int userInt);

/*
int main ()

{
  int input;

  cout << "Please enter a starting integer: ";
  cin >> input;

  cout << "It took " << hailstone(input) << " tries." << endl;

return 0;
}
*/

int hailstone (int userInt)
{
int tally = 0;

while (userInt != 1)
{
  if (userInt%2 == 0)
  {
    userInt /= 2;
  }
   else if (userInt%2 != 0)
     {
       userInt = (userInt*3) + 1;
     }

    tally++;
}


return tally;
}


