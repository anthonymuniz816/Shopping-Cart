#include <iostream>
#include <iomanip>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase(){
   itemname = "none";
   itemprice = 0;
   q = 0;
}

ItemToPurchase::ItemToPurchase(std::string itemname,std::string desc, int price,int quan){
   this->itemname = itemname;
   itemprice = price;
   q = quan;
   itemdesc = desc;
}

void ItemToPurchase::SetName(std::string n){
   itemname = n;
}

string ItemToPurchase::GetName(){
   return itemname;
}

void ItemToPurchase::SetPrice(int p){
   itemprice = p;
}

int ItemToPurchase::GetPrice(){
   return itemprice;
}

void ItemToPurchase::SetQuantity(int quan){
   q = quan;
}

int ItemToPurchase::GetQuantity(){
   return q;
}

void ItemToPurchase::SetDescription(std::string desc){
   itemdesc = desc;
}
   
string ItemToPurchase::GetDescription(){
   return itemdesc;
}
      
void ItemToPurchase::PrintItemCost(){
   cout << fixed << setprecision(2);
   cout << itemname << " " << q << " @ $" << itemprice << " = $" << q * itemprice << endl;
}
   
void ItemToPurchase::PrintItemDescription(){
   cout << itemname << ": " << itemdesc << endl;
}