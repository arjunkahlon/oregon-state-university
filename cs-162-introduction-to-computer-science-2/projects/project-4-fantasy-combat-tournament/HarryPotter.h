/***************************************************************************************
HarryPotter.h: This is the header file for my HarryPotter class. It is derived from the
Character class. This character will feature the special ability to reviving after death.
***************************************************************************************/

#ifndef HarryPotter_H
#define HarryPotter_H

#include "Character.h"

class HarryPotter : public Character
{
private:
	int livesUsed;
public:
	HarryPotter(string);
	int defense(int);
};
#endif