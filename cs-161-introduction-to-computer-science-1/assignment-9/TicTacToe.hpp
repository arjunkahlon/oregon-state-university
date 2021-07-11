/*********************************************************************************
*Name: Arjun Kahlon
*Date: May 30, 2017
*Description: This is the header file for my TicTacToe class. It contains my private
*Board object (board1) and private char variable player. It contains the function
*prototypes for the TicTacToe constructor and the prototype for the function play().
**********************************************************************************/

#ifndef TicTacToe_HPP
#define TicTacToe_HPP

#include "Board.hpp"

class TicTacToe {

private:

Board board1;
char player;

public:

TicTacToe(char);

void play();

};

#endif
