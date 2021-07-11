/********************************************************************************
main.cpp : This is the main file for Project 1. It contains the loop that runs
the Langton's simulation. I implemented a menu by writing a function called
menuLangton(). It returns type bool. If menuLangton() returns true, then the
simulation runs. If it returns false, then the main function exits. When the simulation
begins, this program asks the user to enter in integer calues for rows, columns,
starting x coordinate, starting y coordinate, and total steps. It then uses these
values to create an Ant object. total_steps is the loop control variable for the
simulation loop. I use ant.getBoard()->deleteBoard() to free the allocated
memory.
********************************************************************************/

#include "Ant.hpp"
#include "Board.hpp"
#include "menuLangton.h"

#include <iostream>

using namespace std;

int main()
{

   int total_steps, input_rows, input_columns, user_x, user_y;


   cout << "\nWelcome to a Langton's Ant Simulation." << endl;
   cout << "\nIn this simulation, you will create a board by inputting integer values";
   cout << "\nfor the desired number of rows and columns.";
   cout << endl << endl;


   if (menuLangton() == true)        //menuLangton() returns true and starts Langton simulation
   {
      cout << "\n\nPlease enter an integer value for your desired number of rows: ";
      cin >> input_rows;        //total rows of board

      cout << "\nPlease enter an integer value for your desired number of columns: ";
      cin >> input_columns;     //total columns of board

      cout << "\nPlease enter an integer value for your desired starting x coordinate: ";
      cin >> user_x;        //starting x coordinate of ant

      cout << "\nPlease enter an integer value for your desired starting y coordinate: ";
      cin >> user_y;        //starting y coordinate of ant

      cout << "\nPlease enter an integer value for your desired number of steps: ";
      cin >> total_steps;     //total loops


      Ant ant(input_rows, input_columns, user_x, user_y);      //creates Ant object


      for (int i = 0; i < total_steps; i++)     //Langton's Simulation loop
      {
         cout << "\nThe ant's current index coordinates are " << "[" << ant.getBoard()->getXCoord() << "] [" << ant.getBoard()->getYCoord() << "]" << endl;

         ant.getBoard()->printBoard();      //outputs board to screen
         ant.move(input_rows, input_columns);    //calls move function from ant class
      }

      ant.getBoard()->deleteBoard();     //deletes dynamically allocated memory for the board. deleteBoard located in Board class
   }
   else         //menuLangton() returns false
   {
       cout << "\n\nProgram will now exit" << endl << endl;
   }

return 0;
}
