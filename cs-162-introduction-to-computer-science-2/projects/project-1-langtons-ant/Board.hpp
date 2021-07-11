/******************************************************************
Board.hpp : This is the header file for my Board class. It
contains the declarations for my Board constructors, setXY(),
printBoard(), getXCoord(), getYCoord(), getCurrentColor(),
setCurrentColor(), and deleteBoard(). char** board is initialized
to empty spaces in the board constructor. The dynamically allocated
memory is deleted in deleteBoard().The declaration file for this
class is located in Board.cpp.
*******************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
using namespace std;

class Board {

private:

char** board;
int total_rows, total_columns, x_coord, y_coord;

public:

   Board();       //initializes board to empty spaces

   Board(int, int, int, int);     //rows, columns, x coordinate, y coordinate

   void setXY(int, int);        //sets X, Y

   void printBoard();          //displays the board to the screen

   int getXCoord();        //returns X

   int getYCoord();         //returns Y

   char getCurrentColor();        //returnsCurrentColor of current X, Y coordinates

   void setCurrentColor(char);     //sets the currentColor to passed in char type

   void deleteBoard();        //deletes the Board object and clears the memory

};

#endif

