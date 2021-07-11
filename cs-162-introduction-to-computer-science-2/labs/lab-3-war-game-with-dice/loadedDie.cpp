/********************************************************************
This is the file declaration page for the loadedDie
class. It defaults the dieType variable (from Die class)
to "Loaded" rather than the default of "Not Loaded" in the
Die class. It also has the roll return an upper half value
for every alternative roll. If the die has 8 sides, it returns
a random generation number from 5, 6, 7, 8 on every alternative roll. 
If the die has 7 sides, it returns a randomly generated number
from 5, 6, 7 on every alternative roll.
**********************************************************************/


#include "loadedDie.hpp"

loadedDie::loadedDie(int a) : Die(a)
{
dieType = "Loaded";       //defaults dieType to "Loaded"
altRoll = 1;              //control variable which allows the Loaded Die to return biased value on alternate rolls
}

/**********************************************************
loadedDie overloads the roll function so it returns a number
value from the upper half the possible side values on every
alternative roll. On the first roll, the loaded die rolls a
biased return. On the next roll, it rolls a normal roll. On 
the third roll, it returns a biased roll again. These 
alternation is controlled by the int variable altRoll which
and conditional statement which evaluate its current value.
************************************************************/

int loadedDie::roll()
{
   if (altRoll == 1)
   {
      altRoll = 0;                 //updates control variable
      return ((numberSides + 1)/2) + (rand() % (numberSides/2) + 1);   //returns an upper half value for the Die
   } 
   else  
   {
      altRoll = 1;                 //updates control variable
      return Die::roll();          //returns regular roll of all possible values
   } 
}
