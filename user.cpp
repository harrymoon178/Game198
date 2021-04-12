#include <iostream>
#include "user.h"

User::User(string name, int score, int level, int money) {
  this->name = name;
  this->score = score;
  this->level = level;
  this->money = money;
}

void User::reset() {
  score = 0;
  level = 1;
}

void User::print_info() {
  cout << name << ": " << score << ", lv." << level << ", $" << money << endl;
}

bool operator<(const User & a, const User & b) {
  if (a.score == b.score)
    return (a.name < b.name);
  return (a.score > b.score);
}
