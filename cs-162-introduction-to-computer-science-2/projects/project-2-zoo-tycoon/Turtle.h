/*************************************************************************
Turtle.h: This is the declaration file for the turle class. It inherits
from the base class: Animal.
************************************************************************/

#ifndef TURTLE_H
#define TURTLE_H

#include "Animal.h"

class Turtle : public Animal
{
public:
	Turtle(int);
	string getAnimalType();

};

#endif

