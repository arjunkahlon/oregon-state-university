/************************************************************************
**** Author : Arjun Kahlon
**** Date: May 1, 2017
**** Description: This program creates a class called Taxicab that
**** holds 3 integer varaibles. The functions within the class change
**** the values held in these variables. I demoed with the included Main
**** on Canvas.
**************************************************************************/

#include "Taxicab.hpp"


Taxicab::Taxicab()    //defualt constructor
{
  xCoord = yCoord = distanceTraveled = 0;
}

Taxicab::Taxicab(int x, int y)    //initialize constructor
{
   xCoord = x;
   yCoord = y;
   distanceTraveled = 0;
}

int Taxicab::getXCoord()    //returns X Coordinate
{
  return xCoord;
}

int Taxicab::getYCoord()    //returns Y Coordinate
{
  return yCoord;
}

int Taxicab::getDistanceTraveled()    //returns Distance Traveled
{
  return distanceTraveled;
}

void Taxicab::moveX(int dist)    //updates xCoord and distanceTraveled
{
  xCoord += dist;
  (dist > 0) ? distanceTraveled += dist : distanceTraveled -= dist;
}

void Taxicab::moveY(int dist)    //updates yCoord and distanceTraveled
{
  yCoord += dist;
  (dist > 0) ? distanceTraveled += dist : distanceTraveled -= dist;
}

