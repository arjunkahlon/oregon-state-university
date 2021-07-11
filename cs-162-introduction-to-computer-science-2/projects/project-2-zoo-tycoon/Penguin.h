/*************************************************************************
Penguin.h: This is the declaration file for the penguin class. It inherits
from the base class: Animal.
************************************************************************/

#ifndef PENGUIN_H
#define PENGUIN_H

#include "Animal.h"

class Penguin: public Animal
{
public:
	Penguin(int);
	string getAnimalType();


};

#endif
