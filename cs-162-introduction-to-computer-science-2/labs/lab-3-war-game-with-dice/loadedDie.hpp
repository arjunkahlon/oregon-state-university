/******************************************************
Declaration file for loadedDie class. This class is 
derived from the Die class. 
******************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include "Die.hpp"

class loadedDie : public Die   //derives loadedDie from Die class
{

public:
    loadedDie();
    loadedDie(int);
    int roll();     //overloads the roll() function from Die class

private: 
    int altRoll; //control variable which allows roll() function to return biased value on alternate rolls

};

#endif
