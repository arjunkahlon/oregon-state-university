/*************************************************************
*Name: Arjun Kahlon
*Date: June 6th, 2017
*Description: This is the header file for the Customer class
***************************************************************/

#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <vector>
#include "Product.hpp"

class Customer
{
private:
   vector<string> cart;
   string name;
   string accountID;
   bool premiumMember;
public:
   Customer(std::string n, std::string a, bool pm);
   string getAccountID();
   vector<string> getCart();
   void addProductToCart(std::string);
   bool isPremiumMember();
   void emptyCart();
};

#endif
