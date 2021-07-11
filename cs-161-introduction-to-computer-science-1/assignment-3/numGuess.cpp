/***************************************************************
 ** Author : Arjun Kahlon
 ** Date: April 17, 2017
 ** Description: This program promps the user to enter an integer 
 ** for that player (or another player) to guess. If the player  
 ** guesses a value too low, the program outputs "Too Low." If the
 ** the guess is too high, it outputs "Too High". One the player
 ** guesses the right integer value, the program outputs the number
 ** of tries is the took the user.
 *****************************************************************/

#include <iostream>

using namespace std;

int main ()
{
int number;
int userGuess;
bool numFound = false;
int tally = 0;

cout << "Enter the number for the player to guess." << endl;
cin >> number;

cout << "Enter your guess." << endl;
cin >> userGuess;

if (userGuess == number)
  {
    numFound = true;
    tally++;
    cout << "You guessed it in 1 try.";
  }
if (userGuess > number)
  {
   cout << "Too high - try again." << endl;
   tally++;
   }
if (userGuess < number)
  {
   cout << "Too low - try again." << endl;
   tally++;
  }

while (numFound != true)
 {
  cout << "Enter you guess." << endl;
  cin >> userGuess;
  tally ++;

    if (userGuess == number)
    {
    numFound = true;
    cout << "You guessed it in " << tally << " tries." << endl;
    }
    if (userGuess > number)
    {
    cout << "Too high - try again." << endl;
    }
    if (userGuess < number)
    {
    cout << "Too low - try again." << endl;
    }
 }

return 0;
}


