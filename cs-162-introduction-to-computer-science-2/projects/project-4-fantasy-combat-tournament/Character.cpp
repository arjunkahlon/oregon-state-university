#include "Character.h"

Character::Character(string attack, string defense, string t, int a, int s, string name)
{
	armor = a;
	strength = s;
	characterType = t;
	originalStrength = s;
	characterName = name;

	attackNumOfDies = atoi(attack.substr(0, 1).c_str());    //stores first element of string to attackNumofDies
	attackNumOfSides = atoi(attack.substr(2).c_str());      //stores attackNumofSides from passed in string
	defenseNumOfDies = atoi(defense.substr(0, 1).c_str());  //stores defenseNumofDies from passed in string
	defenseNumOfSides = atoi(defense.substr(2).c_str());    //stores defenseNumofSides from passed in string

}

int Character::attack()
{
	int damage = 0;

	for (int i = 0; i < attackNumOfDies; i++)     //Die Count as LCV
	{
		damage += rand() % attackNumOfSides + 1;    //random generated number from range given by 1 to attackNumOfSides
	}

	return damage;
}

int Character::defense(int dmg)
{
	int totalRoll = 0;

	for (int i = 0; i < defenseNumOfDies; i++)     //Die Count ast LCV
	{
		totalRoll += rand() % defenseNumOfSides + 1;   //random generated number from range given by 1 to defenseNumOfSides
	}
	int totalDefense = totalRoll + armor;      //calculates total defense

	if (totalDefense < dmg)
	{
		strength -= (dmg - totalDefense);
	}
	return totalRoll;
}

void Character::decrementDefenseNumOfDies()      //decrements number of Defense Dies
{
	defenseNumOfDies--;
}

int Character::getStrength()
{
	return strength;
}

void Character::setStrength(int newStrength)
{
	strength = newStrength;
}

int Character::getArmor()
{
	return armor;
}

string Character::getType()
{
	return characterType;
}

string Character::getName()
{
	return characterName;
}

void Character::recover()
{
	int randNum = rand() % 6;
	strength += (int)(originalStrength * ((randNum * 10) / 100.0));
}

