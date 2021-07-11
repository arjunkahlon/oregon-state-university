/***************************************************************
**** Author : Arjun Kahlon
**** Date: May 15, 2017 
**** Description: This is the header file for the Person class. It
**** contains the private variables, name and age. It also contains
**** the declarations for the public functions.
******************************************************************/


#ifndef Person_HPP
#define Person_HPP

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Person
{
  private:
    string name;
    double age;

  public:

  Person();

  Person(string, double);

  string getName();

  double getAge();

};

#endif
