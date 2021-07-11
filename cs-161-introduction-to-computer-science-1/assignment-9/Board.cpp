/*********************************************************************************
*Name: Arjun Kahlon
*Date: May 30, 2017
*Description: This is the definition file for my Board class. It contains a 
*constructor that sets each value in the boardArray to ' '. It contains the 
*makeMove definition which passes in two ints and a char, and sets an index of the
*array by using the two ints ([x][y]) to the char value passed in. It also contains
*the gameState definition, which returns an Enum (Status) of the current state of
*the game (X_Won, O_Won, UNFINISHED, DRAW). It also contains the printBoard definition
*which prints the current board to the screen.   
**********************************************************************************/

#include "Board.hpp"


Board::Board() {           //sets each array index to an empty character

   for (int i = 0; i < 3; i++) {
      for (int j=0; j < 3; j++) {
         boardArray[i][j] = ' ';
       }
    }
}  

bool Board::makeMove(int x, int y, char p) {    //takes in player input to set array index
   if (boardArray[x][y] == ' ') {
      boardArray[x][y] = p;
      return true;
   }
      return false;
}
       


Board::Status Board::gameState() {       //current status of game
 if (boardArray[0][0] == boardArray[0][1] && boardArray [0][0] == boardArray[0][2]) {
      if (boardArray[0][0] == 'X') {
         return X_WON;
      }
      else if (boardArray[0][0] == 'O') {
         return O_WON;
      }
  }
  if (boardArray[1][0] == boardArray[1][1] && boardArray[1][0] == boardArray[1][2]) {
     if (boardArray[1][0] == 'X') {
        return X_WON;
     }
     else if (boardArray[1][0] == 'O') {
        return O_WON;
     }
  }
  if (boardArray[2][0] == boardArray[2][1] && boardArray[2][0] == boardArray [2][2]) {
     if (boardArray[2][0] == 'X') {
        return X_WON;
     }
     else if (boardArray[2][0] == 'O') {
        return O_WON;
     }
  }
  if (boardArray[0][0] == boardArray[1][0] && boardArray[0][0] == boardArray [2][0]) {
     if (boardArray[1][0] == 'X') {
        return X_WON;
     }
     else if (boardArray[1][0] == 'O') {
        return O_WON;
     }
  }
  if (boardArray[0][1] == boardArray[1][1] && boardArray[0][1] == boardArray [2][1]) {
     if (boardArray[0][1] == 'X') {
        return X_WON;
     }
     else if (boardArray[0][1] == 'O') {
        return O_WON;
     }
  }
  if (boardArray[0][2] == boardArray[1][2] && boardArray[0][2] == boardArray [2][2]) {
     if (boardArray[0][2] == 'X') {
        return X_WON;
     }
     else if (boardArray[0][2] == 'O') {
        return O_WON;
     }
  }
  if (boardArray[0][0] == boardArray[1][1] && boardArray[0][0] == boardArray [2][2]) {
     if (boardArray[0][0] == 'X') {
        return X_WON;
     }
     else if (boardArray[0][0] == 'O') {
        return O_WON;
     }
  }
  if (boardArray[0][2] == boardArray[1][1] && boardArray[0][2] == boardArray [2][0]) {
     if (boardArray[0][2] == 'X') {
        return X_WON;
     }
     else if (boardArray[0][2] == 'O') {
        return O_WON;
     }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
       if (boardArray[i][j] == ' ') {
          return UNFINISHED;
       }
     } 
  }
return DRAW;
}

void Board::printBoard() {           //prints Board to screen
    cout << setw(10) << "0" << setw(8) << "1" << setw(9) << "2\n";
    for (int i = 0; i < 3; i++) {
       cout << setw(7) << "[" << i << "][0] | " << "[" << i;
       cout << "][1] | " << "[" << i << "][2]" << endl;
       cout << setw(14) << "|" << setw(9) << "|" << endl;

          for (int j = 0; j < 3; j++) {

             switch (j) {
                case 0:
                   cout << i << setw(9) << boardArray[i][j];
                   cout << setw(4) << "|";
                   break;
                case 1:
                   cout << setw(4) << boardArray[i][j];
                   cout << setw(5) << "|";
                   break;
                case 2:
                   cout << setw(4) << boardArray[i][j] << endl;
                   break;
                default:
                   cout << "ERROR!\n\n";
              }
            }
           cout << setw(14) << "|" << setw(10) << "|\n";
              if (i != 2) {
                 cout << setw(32) << "--------------------------\n";
              }
        }
       cout << endl << endl;

}
