/************************************************************
Animal.cpp: This is the definition file for the Animal class.
This class will serve as the base class for future
animal types.
************************************************************/

#include "Animal.h"



Animal::Animal(int a, double c, int n, double b, int p)   //initializes Animal class to parameters
{
	age = a;
	cost = c;
	numberOfBabies = n;
	baseFoodCost = BASEFOODCOST * b;
	payoff = p;
}

int Animal::getAge()    //returns age of animal
{
	return age;
}

double Animal::getCost()    //returns cost of animal
{
	return cost;
}

int Animal::getNumberofBabies()   //returns number of babies animal is capable of producing
{
	return numberOfBabies;
}

double Animal::getBaseFoodCost()   //returns base feeding cost for animal
{
	return baseFoodCost;
}

int Animal::getPayoff()   //returns payoff for animal
{
	return payoff;
}

void Animal::incrementAge()    //increments age of animal
{
	age++;
}
