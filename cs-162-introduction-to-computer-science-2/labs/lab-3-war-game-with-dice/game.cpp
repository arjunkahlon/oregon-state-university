/***********************************************************************
This is the declaration file for the game class. It contains all function
declarations. The userMenu() function obtains user input and creates 
the Die objects as well as obtains the number of rounds for the game.
The playGame() function loops using rounds as a loop control varaible.
It stores the resutls into a 2D int array. The Results() function outputs
the array onto the screen as well as tallies the earned points for user 
1 and 2. It then displays the winner. 
***********************************************************************/

#include "game.hpp"

Game::Game()
{
   die1 = NULL;      //initializes Die Object pointers
   die2 = NULL;
}

void Game::userMenu()    //obtains user input and creates Die objects
{
   bool menuExit = false;
   bool userSuccess = false;
   char userInput;
   char response;
   int sides = 0;

   cout << "\n\nWelcome to War. This is a 2 player game in which each player will tally ";  
   cout << "\npoints based on rolls of a user selected die. Each player has the choice ";
   cout << "\nbetween a regular die and a loaded die. The loaded die will roll a randomly ";
   cout << "\ngenerated number between the upper half possible values on every alternative ";
   cout << "\nroll. Each user will be allowed to choose their desired number of sides." << endl;
 
   while (!menuExit)           //allows user to succesfully star or exit game from menu 
   {
      userInput = ' ';

      cout << "\nPlease select from the following options." << endl << endl;
      cout << "A: Play Game" << endl; 
      cout << "B: Exit" << endl;
  
      cout << "\n\nPlease Select an option: ";
      cin.get(userInput);
      cin.ignore(INT_MAX, '\n');
      
      if(userInput == 'A' || userInput == 'a')     //user selected to start game
      {
         cout << "\nPlayer 1. Please select your desired number of sides: ";
         cin >> sides; 
         cin.ignore(INT_MAX, '\n');          
      
         cout << "\nPlayer 1. Would you like to use a loaded die (yes or no)? ";
         cin.get(response);
         cin.ignore(INT_MAX, '\n');

         if (response == 'y' || response == 'Y')
         {
            die1 = new loadedDie(sides);
         }
         else
         {
            die1 = new Die(sides);  
         }

         cout << "\n\nPlayer 2. Please select your desired number of sides: ";
         cin >> sides;
         cin.ignore(INT_MAX, '\n');

         cout << "\nPlayer 2. Would you like to use a loaded die (yes or no)? ";
         cin.get(response);
         cin.ignore(INT_MAX, '\n');         

         if (response == 'y' || response == 'Y')
         {
            die2 = new loadedDie(sides);
         }
         else
         {
            die2 = new Die(sides);
         }

         cout << "\n\nHow many rounds would you like to play? ";
         cin >> rounds; 

         menuExit = true;
         menuSuccess = true;
      }
      else if (userInput == 'B' || userInput == 'b')   //user selected to exit game
      {
         cout << "\nThis game will now exit." << endl << endl;
         menuExit = true;
         menuSuccess = false;
      }
      else     //user inputted invalid response
      {
         cout << "\n\nI'm sorry but your response is invalid. Please try again." << endl;
         cin.ignore(255, '\n');
         cin.clear();
      }

   }
   

}

bool Game::getMenuSuccess()   //used in main function to start or exit game
{
   return menuSuccess;
}

void Game::playGame()
{
   for(int i = 0; i < rounds; i++)
   {
      resultsArray[i][0] = die1->roll();      //stores results in 2D array
      resultsArray[i][1] = die2->roll(); 
   }

}

void Game::Results()               //displays results
{
   int player1 = 0;
   int player2 = 0;

   cout << "\nPlayer 1 will use a " << die1->getDieType() << " die with " << die1->getNumberSides() << " sides." << endl;
 
   cout << "\nPlayer 2 will use a " << die2->getDieType() << " die with " << die1->getNumberSides() << " sides." << endl;

   cout << "\nThese are the results of the game";
   cout << "\nPlayer 1" << "    " << "Player 2" << endl;
   cout << "--------------------" << endl; 
   
   for(int i = 0; i < rounds; i++)  //outputs results and tallies points
   {
      cout << "       " << resultsArray[i][0] << "----" << resultsArray[i][1];
      
      if(resultsArray[i][0] > resultsArray[i][1])
      {
         player1++;     //player 1 earns a point for having higher roll
         cout << "   Player 1: " << player1 << "   Player 2: " << player2 << endl;   
      }
      else if(resultsArray[i][0] < resultsArray[i][1])
      {
         player2++;      //player 2 earns a point for having higher roll
         cout << "   Player 1: " <<player1 << "   Player 2: " << player2 << endl; 
      }
      else
      {
         cout << "   Draw!" << endl;
      }
   }   
  
   if(player1 > player2)      //player 1 wins if he/she has more points
   {
      cout << "\n\nPlayer 1 wins." << endl;
   }
   else if(player2 > player1)    //player 2 wins if he/she has more points
   {
      cout << "\n\nPlayer 2 wins." << endl;
   }
   else        //game ends in a draw
   {
      cout << "\n\nPlayer 1 and Player 2 have drawn." << endl;
   }

}
