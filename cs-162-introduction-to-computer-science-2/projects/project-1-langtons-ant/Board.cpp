/****************************************************************************
Board.cpp : This is the declaration file for my Board class. The default
constructor initializes rows/columns to 1 and the starting x,y to 0,0. The
constructor changes these values with the passed in parameters. printBoard()
outputs the board to the user's screen. setXY sets the x and y coordinates.
setCurrentColor() sets the color of the current x,y to the passed in char
paramteter. getCurrenColor() returns the current color of  the current x,y.
deleteBoard() frees the memory allocated for the board.
*****************************************************************************/

#include "Board.hpp"

Board::Board()
{
   Board(1, 1, 0, 0);
}

Board::Board(int r, int c, int x_c, int y_c)
{
   total_rows = r;
   total_columns = c;
   x_coord = x_c;
   y_coord = y_c;

   board = new char*[total_rows];     //dynamically alocates new board object

   for (int i = 0; i < total_rows; i++)
      {
         board[i] = new char[total_rows];
      }

   for (int i = 0; i < total_rows; i++)
      {
         for (int j = 0; j < total_columns; j++)
         {
            board[i][j] = ' ';       //initiallizes board to empty space
         }
      }
}

void Board::printBoard()
{
   for (int i = 0; i < total_rows + 2; i++)
   {
      cout << '-';       //upper portion of board
   }

   for (int i = 0; i < total_rows; i++)
   {
      cout << "\n|";          //left side of board
      for (int j = 0; j < total_columns; j++)
         {
            if (i == x_coord && j == y_coord)
            {
               cout << '*';           //prints ant
            }
            else
            {
               cout << board[i][j];     //prints color of board
            }
         }
      cout << "|";    //right side of board
   }

   cout << endl;
   for (int i = 0; i < total_rows + 2; i++)
   {
      cout << '-';           //bottom portion of board
   }

}

void Board::setXY(int x, int y)         //sets x_coord and y_coord
{
   x_coord = x;
   y_coord = y;
}

int Board::getXCoord()         //returns x coordinate
{
   return x_coord;
}

int Board::getYCoord()          //returns y coordinate
{
   return y_coord;
}

void Board::setCurrentColor(char c)
{
   board[x_coord][y_coord] = c;
}

char Board::getCurrentColor()         //return current color (type: char)
{
   return board[x_coord][y_coord];
}

void Board::deleteBoard()           //deletes the board
{
   for (int i = 0; i < total_rows; i++)
   {
      delete [] board[i];
   }

   delete [] board;
}

