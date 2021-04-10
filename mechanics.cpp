#include <iostream>
#include <cmath>
#include "mechanics.h"
#include "user.h"

using namespace std;

void levelUp(User usr) {
  usr.money += pow(2, usr.level);
  usr.score += usr.level*100;
  usr.level++;
}

bool gameOver(User usr) {
  int option;
  int amount = pow(usr.level, 2)*100;
  
  cout << "GAME OVER." << endl;
  cout << "1. Pay $" << amount << " to resurrect." << endl;
  cout << "2. Start over." << endl;
  cin >> option;

  bool resurrect = true;
  while ((usr.money < amount) && cont)
    if (option == 1 )
      if (usr.money < amount)
        cout << "You don't have enough money." << endl;
      else {
        usr.money -= amount;
        cout << "-$" << amount << endl;
      }
    else if (option == 2) {
      usr.reset();
      resurrect = false;
    }
  
  return resurrect;
}

void printInventory(bool * p_inv) {
  string items[] = {"x2 money", "x2 score", "card revealer"};
  const int size = sizeof(items) / sizeof(items[0]);
  
  cout << "Inventory: " << endl;
  for (int i = 0; i < size; i++)
    if (p_inv[i] == 1)
      cout << i+1 << ". " << items[i] << endl;;
}

void printStore(int items[], int prices[], const int size, bool inv[]) {
  for (int i = 0; i < size; i++)
    if (inv[i] != 1)
      cout << i+1 << ". " << items[i] << " $" << prices[i] << endl;
    else
      cout << i+1 << ". " << items[i] << " is sold out." << endl;
}

bool * store(User usr) {
  string items[] = {"x2 money", "x2 score", "card revealer"};
  int prices[] = {usr.level*100, usr.level*100, usr.level*200};
  const int size = sizeof(items) / sizeof(items[0]);
  bool inventory[size] = {}
  
  cout << "Welcome to the store!" << endl;
  cout << "You may choose to purchase items for the next level: " << endl;
  
  while (1) {
    printStore(items, prices, size, inventory);
    cout << "Input item no. or input any key to leave the store: " << endl;
    
    int item;
    cin >> item;
    
    if (item == 1 || item == 2 || item == 3)
      if (inventory[item-1] == 1)
        cout << "Item is sold" << endl;
      else {
        if (usr.money < prices)
          cout << "You don't have enough money." << endl;
        else {
          usr.money -= prices[item-1];
          usr_inventory[item-1] = 1;
          cout << "You bought a " << items[item-1] << " for $" << prices[item-1] << endl;
        }
      }
    else
      break;
  }
  
  bool *p_inv = inventory;
  return p_inv;
}
