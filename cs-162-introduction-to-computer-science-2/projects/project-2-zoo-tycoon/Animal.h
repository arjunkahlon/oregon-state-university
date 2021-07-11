/*************************************************
Animal.h: This is the declaration file for the
animal class. This class will serve as a base
class for inherited animal types.
*************************************************/

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

class Animal
{

private:
	static const int BASEFOODCOST = 10;

	int age;
	double cost;
	int numberOfBabies;
	double baseFoodCost;
	int payoff;

public:
	//Animal();
	Animal(int, double, int, double, int);
	int getAge();
	double getCost();
	int getNumberofBabies();
	double getBaseFoodCost();
	int getPayoff();
	void incrementAge();
	virtual string getAnimalType() = 0;
};

#endif
