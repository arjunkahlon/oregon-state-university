/*************************************************
This is the main function for the game. It creates
a Game object, runs a userMenu() function for the
game object, playGame() function for the game object,
and Results() function for the game object. 
************************************************/

#include "Die.hpp"
#include "loadedDie.hpp"
#include "game.hpp"

int main()
{

   Game g;           //creates Game object.
   g.userMenu();
   
   if (g.getMenuSuccess())    //user has selected Play Game in the userMenu() function
   {
      g.playGame(); 
      g.Results();
   }

   return 0;
}
