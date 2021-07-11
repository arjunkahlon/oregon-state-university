/*********************************************************************************
Vampire.h: This is the header file for my Vampire class. It is derived from the
Character class. This character will have the special ability of Charm which is
based on a 50-50 chance. 
*********************************************************************************/

#ifndef Vampire_H
#define Vampire_H

#include "Character.h"

class Vampire : public Character
{
public:
	Vampire();
	int defense(int);    //accounts for special ability Charm
};
#endif