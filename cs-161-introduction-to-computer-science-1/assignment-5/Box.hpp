/***************************************************************
**** Author : Arjun Kahlon
**** Date: May 1, 2017 
**** Description: This program creates a class calld Box which
**** contains constructors to initialize the values, functions to
**** set height, width, and length, as well as 2 function to calculate
**** volume and surface area. This program was tested with the Main
**** provided on Canvas.  
******************************************************************/

#ifndef Box_HPP
#define Box_HPP

#include <iostream>
using namespace std;

class Box
{
private:
   double height, width, length;

public:

Box();

Box(double, double, double);

void setHeight(double);

void setWidth(double);

void setLength(double);

double calcVolume();

double calcSurfaceArea();
};

#endif
