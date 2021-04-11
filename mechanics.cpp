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

bool gameOver(User usr) { //if not enough money -> directly skip 
  int option;
  int amount = pow(usr.level, 2)*100;
  cout << "GAME OVER." << endl;
  if (usr.money<amount)
  return 0;
  cout << "1. Pay $" << amount << " to resurrect." << endl;
  cout << "2. Start over." << endl;
  cin >> option;

  bool cont;
  if (option == 1) {
    usr.money -= amount;
    cont = true;
  }
  else if (option == 2) {
    usr.reset();
    cont = false;
  }
  return cont;
}

void printInventory(int * p_inv) {
  string items[] = {"x2 money", "x2 score", "card revealer"};
  cout << "Inventory: " << endl;
  for (int i = 0; i < sizeof(items)/sizeof(items[0]); i++)
    cout << items[i] << " - "<< p_inv[i] << ", ";
  cout << endl;
}

int * store(User usr) { //if not enough money -> cant buy
  int prices[] = {usr.level*100, usr.level*200, usr.level*300};
  string items[] = {"x2 money", "x2 score", "card revealer"};
  int usr_inventory[] = {0, 0, 0};
  int *p_inv = usr_inventory;
  cout << "Welcome to the store!" << endl;
  cout << "You may choose to purchase items for the next level: " << endl;

  for (int i = 0; i < sizeof(items)/sizeof(items[0]); i++)
    cout << i+1 << ". " << items[i] << " $" << prices[i] << endl;

  int item;
  cout << "Input item no. or input any key to leave the store: " << endl;
  cin >> item;
  while (item == 1 || item == 2 || item == 3){
    int quantity;
    cout << "How many " << items[item-1] << " do you want? ";
    cin >> quantity;
	if (user.money < price[item-1]*quantity){
		cout << "Sorry, you do not have enough money." << endl;
	}
	else{
    usr.money -= prices[item-1]*quantity;
    usr_inventory[item-1] += quantity;
    cout << "You bought " << quantity << " " << items[item-1] << "(s) for $" << prices[item-1]*quantity << endl;
	}
    cout << "Input item no. or input any key to leave the store: " << endl;
    cin >> item;
  }
  return p_inv;
