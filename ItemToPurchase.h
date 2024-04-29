#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase{
   public:
      ItemToPurchase();
      ItemToPurchase(string itemname, string itemdescription, int price,int quan);
      
      void SetName(string n);
      string GetName();
      
      void SetPrice(int p);
      int GetPrice();
      
      void SetQuantity(int quan);
      int GetQuantity();
      
      void SetDescription(string desc);
      string GetDescription();
      
      void PrintItemCost();
      void PrintItemDescription();
         
   private:
      string itemname;
      int itemprice;
      int q;
      string itemdesc;
};

#endif