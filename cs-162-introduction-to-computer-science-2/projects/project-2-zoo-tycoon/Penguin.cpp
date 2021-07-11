/***************************************************************************
Penguin.cpp: This is the definition file for the penguin class. It inherits
from the base class: Animal.
***************************************************************************/

#include "Penguin.h"



Penguin::Penguin(int age) : Animal(age, 1000.0, 5, 1.0, 100)
{

}

string Penguin::getAnimalType()
{
	return "penguin";
}

