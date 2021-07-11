/*********************************************************************************
*Name: Arjun Kahlon
*Date: May 30, 2017
*Description: This is the header file for my Board class. This include the private
*member array boardArray[3][3], as well as the enum definition for Status, the
*prototype for the Board class constructor, prototype for the makeMove function,
*prototype for the gameState function, and prototype for the printBoard function.
**********************************************************************************/

#ifndef Box_HPP
#define Box_HPP

#include <iostream>
#include <iomanip>

using namespace std;

class Board {

private:
  char boardArray[3][3];
  

public:

enum Status {

X_WON,
O_WON,
DRAW,
UNFINISHED,
};

Board();

bool makeMove(int, int, char p);

Status gameState();

void printBoard();

};


#endif
