#include "Snack.hpp"

Snack::Snack()      //default constructor
{
   snackName = "bottled water";
   snackPrice = 1.75;
   calories = 0;
}

Snack::Snack(string n, double p, int c)
{
   snackName = n;
   snackPrice = p;
   calories = c;
}

string Snack::getName()
{
   return snackName;
}

double Snack::getPrice()
{
   return snackPrice;
}

int Snack::getNumCalories()
{
   return calories;
}
