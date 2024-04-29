#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void PrintMenu() {
   cout <<"MENU" << endl;
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout <<"q - Quit" << endl << endl;  
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
      
      if (option == 'a' || option == 'A'){
         string name,desc;
         int price, quan;
         cout << "ADD ITEM TO CART" << endl;
         cout << "Enter the item name:" << endl;
         getline(cin, name);
         //cin.ignore();
         cout << "Enter the item description:" << endl;
         getline(cin,desc);
         //cin.ignore();
         cout << "Enter the item price:" << endl;
         cin >> price;
         
         cout << "Enter the item quantity:" ;
         cin >> quan;
         ItemToPurchase newitem(name,desc,price,quan);
         theCart.AddItem(newitem);
         cout << endl;
         
      }
      if (option == 'd' || option == 'D'){
         cout << "REMOVE ITEM FROM CART" << endl;
         cout << "Enter name of item to remove:" << endl;
         string item;
         getline(cin,item);
         theCart.RemoveItem(item);
         
      }
      if (option == 'c' || option == 'C'){
         string name;
         int quan;
         cout << "CHANGE ITEM QUANTITY" << endl;
         cout << "Enter the item name:" << endl;
         getline(cin, name);
         cout << "Enter the new quantity:" << endl;
         cin >> quan;
         ItemToPurchase item;
         item.SetName(name);
         item.SetQuantity(quan);
         theCart.ModifyItem(item);
         
      }
      if (option == 'i' || option == 'I'){
         theCart.PrintDescriptions();
         
      }
      if (option == 'o' || option == 'O'){
         theCart.PrintTotal();
         
      }
      if (option == 'q' || option == 'Q'){
         exit(0);
      }
}

int main() {
   string name, date;
   cout << "Enter customer's name:" << endl;
   getline(cin,name);
   cout << "Enter today's date:" << endl;
   getline(cin,date);
   cout<< endl;
   cout << "Customer name: " << name << endl;
   cout << "Today's date: " << date << endl << endl;
   
   ShoppingCart theCart(name,date);
   char opt;
   
 
  PrintMenu();
 
   cout << "Choose an option:" << endl;
  
  while (true){
      cin >> opt;
      if (opt == 'q'|| opt == 'Q'){
         break;
      }
      if (opt != 'a' && opt != 'A' && opt != 'd' && opt != 'D' && opt != 'c' && opt != 'C' && opt != 'i' && opt != 'I' && opt != 'o' && opt != 'O'){
         cin.ignore();
         cout << "Choose an option:" << endl;
         continue;
      }
      cin.ignore();
      ExecuteMenu(opt,theCart);
    cout << endl;
    PrintMenu();
      cout << "Choose an option:" << endl;
    
   }
   
   return 0;
}