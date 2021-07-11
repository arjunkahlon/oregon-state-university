/************************************************************
Final.h: This is the header file for my Final class. It is
derived from Space which is an abstract class. Definitions
are found in Final.cpp.
************************************************************/

#ifndef Final_H
#define Final_H

#include "Space.h"
#include <iostream>
#include <string>
#include "getInput.h"

using namespace std;

class Final : public Space
{
private:
	string riddle1;
	string riddle2;
	int correctAnswer1;  //correct answer for riddle 1
	int correctAnswer2;  //correct answer for riddle 2
	string* choices1;    //chocies for Riddle 1
	string* choices2;    //choices for Riddle 2
	string riddleHint1;  //hint for riddle 1
	string riddleHint2;  //hint for riddle 2
	int numChoices1;     //number of answer choices for riddle 1
	int numChoices2;     //number of answer choices for riddle 2
	bool hintsAvailable = true;   //are the hints still available to be picked up?
	bool answeredCorrectly1 = false;   //has riddle 1 been answered correctly?
	bool answeredCorrectly2 = false;   //has riddle 2 been answered correctly?
	void doRiddle(int);
public:

	Final(string, string, int, int, string*, string*, int, int, string, string);
	virtual void printOptions();
	virtual bool validateChoice(int);
	virtual Space* doChoice(int, vector<string> *, int);
	virtual bool checkWin();
	virtual void reset();

	~Final();
};

#endif