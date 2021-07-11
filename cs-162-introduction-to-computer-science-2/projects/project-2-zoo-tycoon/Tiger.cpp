/*************************************************************************
Tiger.cpp: This is the definition file for the tiger class. It inherits
from the base class: Animal.
************************************************************************/

#include "Tiger.h"



Tiger::Tiger(int age) : Animal(age, 10000.0, 1, 5.0, 2000)
{

}

string Tiger::getAnimalType()
{
	return "tiger";
}