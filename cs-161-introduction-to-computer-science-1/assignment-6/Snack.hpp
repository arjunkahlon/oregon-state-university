/***************************************************************************
 * Author: Arjun Kahlon
 * Date: May 8, 2017
 * Description: This assignment had us create 3 classes: Snack,
 * VendSlot, and MiniVend. These are 3 objects that have their own 
 * private variable, as well as public functions, which are accesible
 * from other objects and the main. MiniVend represents a machine object
 * with 4 slots. VendSlot represents a slot object, which contains a snack
 * and the amount of that snack. For the snack object, there are member
 * variables for the snack name, price, and calories. This program
 * showed us how the different objects we create work with one another. 
 * *************************************************************************/

#ifndef Snack_HPP
#define Snack_HPP

#include <iostream>
#include <string>

using namespace std;

class Snack
{
  private:
    string snackName;
    double snackPrice;
    int calories;

  public:

  Snack();

  Snack(string, double, int);

  string getName();

  double getPrice();

  int getNumCalories();
};

#endif
