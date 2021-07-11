/*************************************************************************
Zoo.h: This is the declaration file for the Zoo class.
************************************************************************/

#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"
#include "Tiger.h"
#include "Turtle.h"
#include "Penguin.h"
#include <cstdlib>
#include <iostream>

using namespace std;

class Zoo
{
private:
	double balance;
	int sizeTiger;
	int capacityTiger;
	int sizeTurtle;
	int capacityTurtle;
	int sizePenguin;
	int capacityPenguin;
	//bool allInfertile, tigerFertile, turtleFertile, penguinFertile, babySuccess;

	void resizeArray(Animal***, int&, int, int);

	Tiger** tigers;       // pointer to an array of pointers that point to Tiger objects
	Turtle** turtles;     //ponter to an array of pointers that point to Turtle objects
	Penguin** penguins;   //pointer to an array of poitners that point to Penguin objects

public:
	enum animal_t { tiger, turtle, penguin };   //enumerated type

	Zoo();
	double getBalance();
	void buyAnimals(int, int, animal_t);
	Animal* addAnimals(int, int, animal_t);
	void removeAnimal(animal_t);
	void dayOccurs();
	//void deleteArrays();
	//void dayEnds();
};

#endif