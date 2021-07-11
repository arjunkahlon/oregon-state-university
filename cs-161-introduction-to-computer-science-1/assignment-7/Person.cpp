/***************************************************************
**** Author : Arjun Kahlon
**** Date: May 15, 2017 
**** Description: This is the declaration file for the Person class. It
**** contains the default constructor, constructor, and get functions.
******************************************************************/

#include "Person.hpp"

Person::Person()
{
  name = "";
  age = 0;
}

Person::Person(string s, double a)
{
  name = s;
  age = a;
}

string Person::getName()
{
  return name;
}

double Person::getAge()
{
  return age;
}

