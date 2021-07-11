/*************************************************************************
Turtle.cpp: This is the definition file for the turle class. It inherits
from the base class: Animal.
************************************************************************/

#include "Turtle.h"



Turtle::Turtle(int age) : Animal(age, 100.0, 10, 0.5, 5)
{

}

string Turtle::getAnimalType()
{
	return "turtle";
}