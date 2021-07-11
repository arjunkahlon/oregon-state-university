/**********************************************************
*Name: Arjun Kahlon
*Date: June 6th, 2017
*Description: This is the header file for the Store class
*************************************************************/

#ifndef STORE_HPP
#define STORE_HPP

#include <string>
#include "Customer.hpp"
#include "Product.hpp"

class Store
{
private:
    vector<Product*> inventory;
    vector<Customer*> members;
public:
    void addProduct(Product* p);
    void addMember(Customer* c);
    Product* getProductFromID(string);
    Customer* getMemberFromID(string);
    void productSearch(string str);
    void addProductToMemberCart(string pID, string mID);
    void checkOutMember(string mID);
};

#endif
