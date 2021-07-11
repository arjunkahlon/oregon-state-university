/*******************************************************************
*Name: Arjun Kahlon
*Date: June 6th, 2017
*Description: This is the definition file for the Product class. It 
contains the constructor which sets the values of the member varaibles.
getIdCode() returns member variable idCode. getTitle() returns member 
variable title. getDescription() returns member variable Description.
getPrice() returns member variable price. getQuantityAvailable returns
member variable Quantity Available. decreaseQuantity() decreases member
variable Quantity Available by 1. 
*********************************************************************/ 

#include "Product.hpp"

Product::Product(string id, string t, string d, double p, int qa) 
{   
   idCode = id;
   title = t;
   description = d;
   price = p;
   quantityAvailable = qa;
}

string Product::getIdCode() 
{   
   return idCode;
}
   
string Product::getTitle() 
{
   return title;
}

string Product::getDescription() 
{   
   return description;
}

double Product::getPrice() 
{
   return price;
}

int Product::getQuantityAvailable() 
{
   return quantityAvailable;
}

void Product::decreaseQuantity() 
{
   quantityAvailable -= 1;
}
