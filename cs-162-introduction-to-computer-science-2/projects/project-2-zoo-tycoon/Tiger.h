/*************************************************************************
Tiger.h: This is the declaration file for the tiger class. It inherits
from the base class: Animal.
************************************************************************/

#ifndef TIGER_H
#define TIGER_H

#include "Animal.h"

class Tiger: public Animal
{
public:
	Tiger(int);
	string getAnimalType();



};

#endif // !TIGER_H