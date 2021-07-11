/********************************************************************
Ant.hpp : This is the header file for my Ant class. It contains an
enumerated type called Direction, a pointer to a Board object, and
x & y coordinates. The declaration file for this class is located in
Ant.cpp.
********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "Board.hpp"
#include <iostream>

class Ant
{

private:

   enum Direction   //enumerated type for ant direction
   {
    up,
    down,
    left,
    right
   };

   Board* board;   //pointer to a Board object called board
   Direction drct;
   int x_temp, y_temp;

public:

   Ant();    //default constructor
   Ant(int, int, int, int);   //constructor for ant object
   void setDirection(Direction);   //sets direction of ant
   Direction getDirection();     //returns direction of ant
   void move(int, int);     //performs ant movement based on conditional statements
   Board* getBoard();      //returns pointer to Board object
};

#endif

