#include "HarryPotter.h"

HarryPotter::HarryPotter(string name) : Character("2d6", "2d6", "Harry Potter", 0, 10, name)
{
	livesUsed = 0;      //will increment to 1 when Harry dies and revives to 20 strength
}

int HarryPotter::defense(int dmg)
{
	int diceRoll = Character::defense(dmg);
	if (getStrength() <= 0)
	{
		if (livesUsed == 0)
		{
			setStrength(20);   //Harry Potter Strength increases to 20 after first death
			livesUsed++;   //Harry has used his sinlge life
		}
	}
	return diceRoll;
}