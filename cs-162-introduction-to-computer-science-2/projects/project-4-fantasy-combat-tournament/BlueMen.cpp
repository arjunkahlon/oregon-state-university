#include "BlueMen.h"


BlueMen::BlueMen(string name) : Character("2d10", "3d6", "Blue Men", 3, 12, name)
{
	decrementCounter = 0;
}

int BlueMen::defense(int dmg)
{
	int diceRoll = Character::defense(dmg);
	int strength = getStrength();
	if (strength <= 8)
	{
		if (decrementCounter == 0)
		{
			decrementDefenseNumOfDies();
			decrementCounter++;
			//Number of dies drops to 2
		}
	}
	if (strength <= 4)
	{
		if (decrementCounter == 1)
		{
			decrementDefenseNumOfDies();
			decrementCounter++;
			//Number of dies drops to 1;
		}
	}
	return diceRoll;
}


