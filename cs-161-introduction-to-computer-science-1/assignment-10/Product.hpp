/**********************************************************
*Name: Arjun Kahlon
*Date: June 6th, 2017
*Description: This is the header file for the Product class
*************************************************************/

#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iostream>
#include <string>

using namespace std;

class Product
{
private:
    string idCode;
    string title;
    string description;
    double price;
    int quantityAvailable;
public:
    Product(std::string id, std::string t, std::string d, double p, int qa);
    string getIdCode();
    string getTitle();
    string getDescription();
    double getPrice();
    int getQuantityAvailable();
    void decreaseQuantity();
};

#endif
