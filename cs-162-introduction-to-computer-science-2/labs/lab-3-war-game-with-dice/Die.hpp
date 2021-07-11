/********************************************
Delcartion file for the Die class. 
********************************************/


#ifndef DIE_HPP
#define DIE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Die
{

protected: 
    int numberSides;            //number of sides on Die object
    string dieType;             //type of Die (Loaded or Not Loaded)


public:
    Die(int);
    int getNumberSides();
    string getDieType();
    virtual int roll();        
};

#endif
