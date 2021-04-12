#include <iostream>
#include <cmath>
#include "mechanics.h"

bool levelUp(User &usr, int *p_inv) {
  cout << "You Win!" << endl;
  int inc_money = pow(2, usr.level);
  int inc_score = usr.level * 100;

  cout << "Level--> " << usr.level << " + 1" << endl;
  if (p_inv[0]) {
    cout << "Money--> " << usr.money << " + " << inc_money << " x 2" << endl;
    inc_money *= 2;
  }
  if (!p_inv[0])
    cout << "Money--> " << usr.money << " + " << inc_money << endl;

  if (p_inv[1]) {
    cout << "Score--> " << usr.score << " + " << inc_score << " x 2" << endl;
    inc_score *= 2;
  }
  if (!p_inv[1])
    cout << "Score--> " << usr.score << " + " << inc_score << endl;

  usr.money += inc_money;
  usr.level++;
  usr.score += inc_score;

  usr.print_info();

  char choice;
  cout << "Continue to play? [y/n]" << endl;
  cout << ">> ";
  cin >> choice;
  bool play;
  while (1) {
    if (choice == 'y') {
      play = true;
      break;
    }
    else if (choice == 'n')
      play = false;
      break;
  }
  return play;
}

bool gameOver(User &usr, int result) {
  int amount = pow(usr.level, 2) * 100 * result;
  bool resurrect;

  cout << "GAME OVER." << endl;
  usr.print_info();
  while (1) {
    char option;
    cout << "Pay $ " << amount << " to resurrect? [y/n]" << endl;
    cout << ">> ";
    cin >> option;

    if (option == 'y')
      if (usr.money < amount)
        cout << "--Error: You don't have enough money." << endl;
      else {
        usr.money -= amount;
        cout << "-$ " << amount << endl;
        usr.print_info();
        resurrect = true;
        break;
      }
    else if (option == 'n') {
      usr.reset();
      resurrect = false;
      break;
    }
  }

  return resurrect;
}

int GuessSize(Card currentcard, Card nextcard) {
  char choice;
  cout << "Press 'L' if you think the next card will be larger" << endl;
  cout << "Press 'S' if you think the next card will be smaller" << endl;
  cout << ">> ";
  cin >> choice;

  int result = 1;
  if (nextcard.rank_idx == currentcard.rank_idx)
      result = 2;
  else if (choice == 'S' && (nextcard.rank_idx < currentcard.rank_idx))
      result = 0;
  else if (choice == 'L' && (nextcard.rank_idx > currentcard.rank_idx))
      result = 0;
  else if (choice != 'S' && choice != 'L')
      result = -1;

  return result;
}

int GuessColour(Card nextcard) {
  char choice;
  cout << "Press 'R' if you think the next card will be red" << endl;
  cout << "Press 'B' if you think the next card will be black" << endl;
  cout << ">> ";
  cin >> choice;

  int result = 1;
  if (choice == 'R' && (nextcard.suit == HEART || nextcard.suit == DIAMOND))
      result = 0;
  else if (choice == 'B' && (nextcard.suit == SPADE || nextcard.suit == CLUB))
      result = 0;
  else if (choice != 'R' && choice != 'B')
      result = -1;

	return result;
}

void printStore(string items[], int prices[], int inv[]) {
  for (int i = 0; i < 3; i++)
    if (i == 0 || i == 1)
      if (inv[i] != 1)
        cout << i+1 << ". " << items[i] << " $ " << prices[i] << endl;
      else
        cout << i+1 << ". " << items[i] << " is sold out." << endl;
    else
      cout << i+1 << ". " << items[i] << " $ " << prices[i] << endl;
}

int * store(User &usr) {
  string items[] = {"x2 money", "x2 score", "card revealer"};
  int prices[] = {usr.level*100, usr.level*100, usr.level*200};
  int *inventory = new int[3];

  for (int i = 0; i < 3; i++)
    inventory[i] = 0;

  cout << "Welcome to the store!" << endl;
  cout << "You may choose to purchase items for the next level: " << endl;

  while (1) {
    printStore(items, prices, inventory);
    cout << "Input item no. or input '0' to leave the store: " << endl;
    cout << ">> ";

    int option;
    cin >> option;

    if (option == 1 || option == 2)
      if (inventory[option-1] == 1)
        cout << "--Error: Item is sold" << endl;
      else {
        if (usr.money < prices[option-1])
          cout << "--Error: You don't have enough money." << endl;
        else {
          usr.money -= prices[option-1];
          inventory[option-1] = 1;
          cout << "You bought a " << items[option-1] << " for $ " << prices[option-1] << endl;
        }
      }
    else if (option == 3) {
      if (usr.money < prices[option-1])
        cout << "--Error: You don't have enough money." << endl;
      else {
        usr.money -= prices[option-1];
        inventory[option-1]++;
        cout << "You bought a " << items[option-1] << " for $ " << prices[option-1] << endl;
      }
    }
    else if (option == 0)
      break;
  }

  return inventory;
}

bool cardRevealer(int *p_inv) {
  if (p_inv[2] > 0) {
    while (1) {
      cout << "You have " << p_inv[2] << " Card Revealer(s)" << endl;
      cout << "Use Card Revealer? [y/n]" << endl;
      cout << ">> ";
      char choice;
      cin >> choice;
      if (choice == 'y') {
        p_inv[2]--;
        return true;
      }
      else if (choice == 'n')
        return false;
    }
  }
  return false;
}
