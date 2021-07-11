/*********************************************************************************
BlueMen.h: This is the header file for my BlueMen class. It is derived from the
Character class. This character will lose a defense die after his strength drops
below certain thresholds. This will be shown in the definition file for this class.
*********************************************************************************/

#ifndef BlueMen_H
#define BlueMen_H

#include "Character.h"

class BlueMen : public Character
{
private:
	int decrementCounter;   //counts number of dies that are lost

public:
	BlueMen(string);
	int defense(int);
};
#endif

