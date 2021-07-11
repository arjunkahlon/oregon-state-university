/**********************************************************************
Declaration file for Game class. Create two Die object pointers as 
private member variables. These objects are initiliazed in the 
userMenu() function. This class contains the menu function which
obtains user input, the playGame() function which fills the results
into a 2D int array (int resultsArray[100][2], and a Results() function
which outputs the results and declares the winner.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Die.hpp"
#include "loadedDie.hpp"
#include <climits> 

#include <iostream>

using namespace std;

class Game
{

private:
    Die *die1, *die2;      //creates two Die object pointers
    int rounds;            //total rounds for game
    int resultsArray[100][2];   //holds results from playGame() and outputs them in Results()
    bool menuSuccess;           //allows game to successfully output on user input
public:
    Game();
    bool getMenuSuccess();      //returns MenuSuccess value
    void userMenu();            //obtains user input to initialize Die Objects and rounds
    void playGame();            //obtains and stores results
    void Results();             //displays the results
};


#endif
