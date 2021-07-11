/***************************************************************
**** Author : Arjun Kahlon
**** Date: May 1, 2017
**** Description: This program creates a class called Taxicab that
**** holds 3 integer varaibles. The functions within the class change
**** the values held in these variables. I demoed with the included Main
**** on Canvas.
******************************************************************/

#ifndef TAXICAB_HPP
#define TAXICAB_HPP

#include <iostream>

using namespace std;

class Taxicab
{
private:
   int xCoord, yCoord, distanceTraveled;

public:
   Taxicab();

   Taxicab(int, int);

   int getXCoord();

   int getYCoord();

   int getDistanceTraveled();
 
   void moveX(int);

   void moveY(int);

};

#endif
