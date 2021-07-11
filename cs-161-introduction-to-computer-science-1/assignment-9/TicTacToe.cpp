/*************************************************************************************************
*Name: Arjun Kahlon
*Date: May 30, 2017
*Description: This is the definition file for my class TicTacToe. It contains a 
*constructor definition that sets private member variable, player ,to a passed in char parameter.
*It contains the defnition for the play() function, which contains a while loop that loops
*while the game is still active. The game loops until the gameState function in the Board
*object returns an ENUM other than UNFINISHED. I incorporated the printBoard() and makeMove()
*functions within the while loop. If makeMove() returned true, I swapped 'X' to 'O' (and vice versa).
*If it returned false, I outputted to the screen that the spot is taken. After the while loop ends,
*I used conditional statements with the board::gameState() function in order to output the results of 
*the game. 
*****************************************************************************************************/

#include "TicTacToe.hpp"
#include "Board.hpp"

TicTacToe::TicTacToe(char p) {          //constructor sets player to p

   player = p;
}

void TicTacToe::play() {  

   int xInput, yInput;  //player input

   while (board1.gameState() == Board::UNFINISHED) {   //checks the status of game
   
      board1.printBoard();       //prints Board to screen

      cout << "\n\nPlayer " << player << ": please enter your move seperated by a space. ";
      cin >> xInput >> yInput;

      if (board1.makeMove(xInput, yInput, player) == true) {
      
         if(player == 'X') {         //swaps X and O
            player = 'O';
         }
         else {
            player = 'X';
         }
       }
       else {
          cout << "\n\nSpot is taken." << endl << endl;
       }
   } 

   cout << endl; 
   board1.printBoard();
         
   if (board1.gameState() == Board::X_WON) {
     cout << "\n\nPlayer X Won!" << endl << endl;
   }
   if (board1.gameState() == Board::O_WON) {
      cout << "\n\nPlayer O Won!" << endl << endl;
   }
   if (board1.gameState() == Board::DRAW) {
      cout << "\n\nIt's a Draw!" << endl << endl;;
   }
}

int main() {

char playerInput;

cout << "\nWhich player would you like to go first (X or O)? "; 
cin >> playerInput;
cout << endl << endl;

TicTacToe game1(playerInput);
game1.play();

   return 0;
}
