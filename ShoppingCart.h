#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart{
   private:
   string customerName;
   string currentDate;
   vector <ItemToPurchase> cartItems;

   public:
   ShoppingCart();
   ShoppingCart(string n, string d);
   
   string GetCustomerName();
   string GetDate();
   
   void AddItem(ItemToPurchase item);
   void RemoveItem(string itemName);
   void ModifyItem(ItemToPurchase item);
   int GetNumItemsInCart() ;
   int GetCostOfCart();
   void PrintTotal();
   void PrintDescriptions();
   
   int SearchCart(string item);
      
   
};

#endif