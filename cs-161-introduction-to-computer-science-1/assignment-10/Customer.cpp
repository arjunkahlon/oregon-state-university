/********************************************************************
*Name: Arjun Kahlon
*Date: June 6th, 2017
*Description: This is the definition file for the Customer class.
It contains the constructor for the Customer class. It contains
member function, getAccountID(), which returns the accountID. getCart()
returns the cart vector. addProductToCart() adds the passed in parameter
into the vector. emptyCart() clears the vector. isPremiumMember() returns 
wheter or not the customer is a premium member.  
************************************************************************/

#include "Customer.hpp"
#include "Product.hpp"

Customer::Customer(string n, string a, bool pm) 
{
   name = n;
   accountID = a;
   premiumMember = pm;
}
   
string Customer::getAccountID() 
{
   return accountID;
}
   
vector<string> Customer::getCart() 
{
   return cart;
}
   
void Customer::addProductToCart(string addCart) 
{
   cart.push_back(addCart);
}
   
bool Customer::isPremiumMember() 
{
   return premiumMember;
}
   
void Customer::emptyCart() 
{
   cart.clear();
}


