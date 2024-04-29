#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

using namespace std;

ShoppingCart::ShoppingCart(){
   customerName = "none";
   currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string n, string d){
   customerName = n;
   currentDate = d;
}
   
string ShoppingCart::GetCustomerName(){
   return customerName;
}

string ShoppingCart::GetDate(){
   return currentDate;
}
   
int ShoppingCart::SearchCart(std::string item){
   for (unsigned int i = 0; i < cartItems.size(); i++) {
       if (cartItems.at(i).GetName() == item){
         return i;
       }
     }
   return -1;
}   
   
void ShoppingCart::AddItem(ItemToPurchase item){
   cartItems.push_back(item);
}
   
void ShoppingCart::RemoveItem(string itemName){
   int index = SearchCart(itemName);
   if (index != -1) {
      cartItems.erase(cartItems.begin() + index);
  }
  else{
     cout << "Item not found in cart. Nothing removed." << endl;
  }
}
   
void ShoppingCart::ModifyItem(ItemToPurchase item){
   bool bItemsModified = false;
   for (unsigned int i = 0; i < cartItems.size(); i++){
      if (cartItems.at(i).GetName() == item.GetName()){
         //cartItems.at(i).SetPrice(item.GetPrice());
         cartItems.at(i).SetQuantity(item.GetQuantity());
         cartItems.at(i).SetDescription(item.GetDescription());
         bItemsModified = true;
      }
   }
   if (bItemsModified == false){
      cout << " Item not found in cart. Nothing modified.";
   }
}
   
int ShoppingCart::GetNumItemsInCart(){
   int result = 0;
    for(unsigned int i=0; i<cartItems.size(); i++){
      result=result+cartItems.at(i).GetQuantity();
    }
   return result;
}
   
int ShoppingCart::GetCostOfCart(){
   int total = 0;
   for (unsigned int i = 0; i < cartItems.size(); i++){
      total = total + (cartItems.at(i).GetPrice()*cartItems.at(i).GetQuantity());
   }
   return total;
}
   
void ShoppingCart::PrintTotal(){
   int total = 0;
   cout << "OUTPUT SHOPPING CART" << endl;
   cout << customerName << "'s Shopping Cart - " << currentDate << endl;
   if (cartItems.size() == 0){
      cout << "Number of Items: 0" << endl << endl;
      cout << "SHOPPING CART IS EMPTY" << endl << endl;
      cout << "Total: $0" << endl << endl;
   }
   else{
      cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;
      for(unsigned int i = 0; i < cartItems.size(); i++){

         cout << cartItems.at(i).GetName() << " " << cartItems.at(i).GetQuantity() << " @ $" << cartItems.at(i).GetPrice()
         << " = $" << cartItems.at(i).GetPrice()*cartItems.at(i).GetQuantity() << endl;

         total = total +   (cartItems.at(i).GetPrice()*cartItems.at(i).GetQuantity());
      }
      cout << endl << "Total: " << total << endl;
   }
}
   
void ShoppingCart::PrintDescriptions(){
  cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
   cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
   cout << "Item Descriptions" << endl;
   for(unsigned int i = 0; i < cartItems.size(); i++){
      cout << cartItems.at(i).GetName() << ": "<< cartItems.at(i).GetDescription() << endl;
   }
}