/************************************************************
Passage.h: This is the header file for my Passage class. It
is derived from Space, which is an abstract class. Definitions
are found in Passage.cpp
************************************************************/

#ifndef Passage_H
#define Passage_H
#include <iostream>
#include "Space.h"
#include "getInput.h"

class Passage : public Space
{
private: 
	string riddle;     //riddle entered as cosntructor
	int correctAnswer; //correct answer choice to riddle
	string roomNum;    //room name
	string* choices;   //riddle choices
	string riddleHint; //riddle hint
	int numChoices;    //numer of answer chocies for riddle
	bool hintAvailable = true;  //is the riddle hint still available in the room?
	bool answeredCorrectly = false;  //has the riddle been asnwered correctly?
	void doRiddle();    //outputs riddle
	
public:
	Passage(string, string, int, string*, int, string);
	virtual void printOptions();  //prints options for Passage class
	virtual bool validateChoice(int);  //validates user Input
	virtual Space* doChoice(int, vector<string> *, int);  //performs operations based on user Input
	virtual void reset();  //resets all booleans in class

	~Passage();
};

#endif

