/************************************************************
Definition file for Die class. Contains class constructor,
roll function which returns randonly generated number between
1 and the number of sides, and get functions for numberSides
and DieType. Die is defaulted to "Not Loaded" as this is a 
standard die.
***********************************************************/


#include "Die.hpp"

Die::Die(int s)
{
   numberSides = s;
   dieType = "Not Loaded";    //not loaded standard die
}

int Die::getNumberSides()
{
   return numberSides;         //returns number of Sides
}

string Die::getDieType()
{
   return dieType;             //returns "Loaded" or "Not Loaded"
}

int Die::roll()
{
   return rand() % numberSides + 1;  //generated random number between 1 and numberSides
}
