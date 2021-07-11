#include "Barbarian.h"
#include "Vampire.h"



Vampire::Vampire(string name) : Character("1d12", "1d6", "Vampire", 1, 18, name)
{

}

int Vampire::defense(int dmg)
{
	int charm = 0;
	charm = rand() % 2;

	if (charm == 1)     //1 implies that charm doesn't work
	{
		return Character::defense(dmg);
	}
	else
	{
		return 0;         //Charm
	}
}
