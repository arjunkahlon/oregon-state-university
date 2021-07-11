/***********************************************************************
* Name: Arjun Kahlon
* Date: June 6th, 2017
* Description: This is the definition page for the Store clas.
* It includes the functions for adding to inventory and members.
  It contains functions that return pointers to Product or Customer,
  based on the respective id that's passed in as a parameter. It also
  contains a Product Search function that returns search results using
  string::find() and string::npos. It contains a function to add a product
  to a member cart as well as the checkOut Member function. This function
  print out the title nad price for each product in the cart, and prints
  the subtotal, shipping cost, and total. 
**************************************************************************/    

#include "Store.hpp"
#include "Product.hpp"
#include "Customer.hpp"

void Store::addProduct(Product* p) 
{
   inventory.push_back(p);
}

void Store::addMember(Customer* c) 
{
   members.push_back(c);
}
   
Product* Store::getProductFromID(string id) 
{ 
   for (int i = 0; i < inventory.size(); i++) 
   {
      Product* p = inventory.at(i);
      if(p->getIdCode() == id) 
      {
         return p;
      }

   }
   return NULL;  
   
}
   
Customer* Store::getMemberFromID(string id) 
{
   for (int i = 0; i < members.size(); i++) 
   {
   
      Customer* c = members.at(i);
      if(c->getAccountID() == id) 
      {
         return c;
      }

   }
   return NULL;
}
   
void Store::productSearch(string str) 
{
   for (int i = 0; i < inventory.size(); i++) 
   {
   
      if (inventory[i]->getDescription().find(str) != string::npos || inventory[i]->getTitle().      find(str) != string::npos) 
      {
      
         Product prSearch = *inventory[i];
         cout << prSearch.getTitle() << endl;
         cout << "ID code: " << prSearch.getIdCode() << endl;
         cout << "Price: $" << prSearch.getPrice() << endl; 
         cout << prSearch.getDescription() << endl;
      }

   }

}
   
void Store::addProductToMemberCart(string pID, string mID) 
{
   if(getProductFromID(pID) == NULL) 
   {
      
      cout << "\nProduct #" << pID << " not found." << endl << endl;

   }else if(getMemberFromID(mID) == NULL) 
   {
        
      cout << "\nMember #" << mID << " not found." << endl << endl;
   
   }else if (getProductFromID(pID)->getQuantityAvailable() <= 0) 
   {
        
      cout << "\nSorry, product #" << pID << " is currently out of stock" << endl;
          
   }else 
   {
 
      getMemberFromID(mID)->addProductToCart(pID);
   }
} 
   

void Store::checkOutMember(string mID) 
{
   double tally = 0;
   double shipCost = 0;
   Customer* c = getMemberFromID(mID); 
   if (c == NULL) 
   {
      cout << "Member #" << mID << " is not found" << endl;
 
   }else 
   {
      for (int i = 0; i < c->getCart().size(); i++) 
	      {
         if((getProductFromID(c->getCart()[i]))->getQuantityAvailable() > 0) 
         {
            cout << getProductFromID(c->getCart()[i])->getTitle() << " - $" << getProductFromID(c->getCart()[i])->getPrice() << endl;
            getProductFromID(c->getCart()[i])->decreaseQuantity();
            tally += getProductFromID(c->getCart()[i])->getPrice();
         }else 
         { 
            cout << "Sorry, product #" << getProductFromID(c->getCart()[i])->getIdCode() << ", " << getProductFromID(c->getCart()[i])->getTitle() << ", is no longer available." << endl;
         }
      }
   cout <<"\nSubtotal: $" << tally << endl;
      if (c->isPremiumMember() == false)
      {
         shipCost = tally*.07;
         cout << "Shipping Cost: $" << shipCost << endl;     
      }else
      {
         cout << "Shipping Cost: $" << shipCost << endl;
      }
   
   }   cout << "Total: $" << tally + shipCost << endl;
}

int main () 
{

Store s;

   Product p0("0", "Donut", "Glazed and Delicious", 1.50, 3); 
      s.addProduct(&p0);
   Product p1("1", "Strawberry", "Freshly grown", 4.50, 1); 
      s.addProduct(&p1);
   Product p2("2", "Chicken", "High in Protein", 5.29, 69); 
      s.addProduct(&p2);
   Product p3("3", "Lettuce", "Goes well in Sandwiches", 3.66, 10); 
      s.addProduct(&p3);
   Product p4("4", "Fruit Roll Ups", "100% Vitamin Tasty", 4.50, 7); 
      s.addProduct(&p4);

   Customer c0("ArJon James", "5", true); s.addMember(&c0);
   Customer c1("Kahlon Green", "6", false); s.addMember(&c1);
   Customer c2("Paul Darge", "7", false); s.addMember(&c2);

   s.addProductToMemberCart(p0.getIdCode(), c0.getAccountID());
   s.addProductToMemberCart(p1.getIdCode(), c1.getAccountID());
   s.addProductToMemberCart(p2.getIdCode(), c2.getAccountID());
   s.addProductToMemberCart(p3.getIdCode(), c0.getAccountID());
   s.addProductToMemberCart(p4.getIdCode(), c1.getAccountID());
   s.addProductToMemberCart(p0.getIdCode(), c2.getAccountID());
   s.addProductToMemberCart(p1.getIdCode(), c0.getAccountID());
   s.addProductToMemberCart(p2.getIdCode(), c1.getAccountID());
   s.addProductToMemberCart(p3.getIdCode(), c2.getAccountID());
   s.addProductToMemberCart(p4.getIdCode(), c0.getAccountID());

   s.productSearch("Donut"); cout << endl;
   s.productSearch("berry"); cout << endl;
   s.productSearch("Protein"); cout << endl;
   s.productSearch("sand"); cout << endl;
   s.productSearch("%"); cout << endl;
   s.productSearch("grown"); cout << endl;

   s.checkOutMember(c0.getAccountID()); cout << endl;
   s.checkOutMember(c1.getAccountID()); cout << endl;
   s.checkOutMember(c2.getAccountID()); cout << endl;


   return 0;
}
