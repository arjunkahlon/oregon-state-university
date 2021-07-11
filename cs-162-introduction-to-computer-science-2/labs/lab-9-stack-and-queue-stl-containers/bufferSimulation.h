/********************************************
bufferSimulation.h: This is the header file
for my bufferSimulation function. It includes
the declaration for my getInput function  
which will also be used in my main file.
********************************************/

#ifndef bufferSimulation_H
#define bufferSimulation_H

#include <iostream>
#include <queue>
#include <limits>

using namespace std;

void bufferSimulation();
int getInput(int min, int max); //will be used in bufferSimulation.cpp and main.cpp

#endif