/*********************************************************************************
Character.h: This is the header file for my Character class. It is the base class
that future classes I create will derive from. It contains two virtual functions for
attack and defense that will be overridden in derived classes.
*********************************************************************************/

#ifndef Character_H
#define Character_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Character
{
private:
	int armor;      //character armor
	int strength, originalStrength;   //character strength
	int attackNumOfDies;
	int attackNumOfSides;
	int defenseNumOfDies;
	int defenseNumOfSides;
	string characterType;   //character type (Barbarian, Vampire, Medusa, HarryPotter, BlueMen)
	string characterName;

protected:
	void decrementDefenseNumOfDies();    //decreases number of defensive dies (used in BlueMen)

public:
	Character(string, string, string, int, int, string);   //constructor for Character
	virtual int attack();     //is overridden by subclasses
	virtual int defense(int);  //is overridden by subclasses
	void setStrength(int);     //sets strength of character
	int getStrength();         //returns strength of character
	int getArmor();            //returns armor
	string getType();          //returns character type
	string getName();
	void recover();
};
#endif
