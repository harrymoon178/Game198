#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "menu.h"
#include "mechanics.h"
#include "game.h"

vector<User> users;


bool sameName(string name) {
  for (int i = 0; i < users.size(); i++)
    if (name == users[i].name)
      return 1;
  return 0;
}

void newUser() {
  string name;
  cout << "New Player: ";
  cin >> name;

  while (sameName(name)) {
    cout <<"\033[1;31mName taken, try another: \033[0m "<< endl;
    cin >> name;
  }
  User u(name);
  users.push_back(u);

  //selectMode(u);
}

void selectUser() {
  if (users.size() == 0)
    cout <<"\033[1;31m--Error: No player record \033[0m "<< endl;
  else {
    for (int i = 0; i < users.size(); i++) {
      cout << i+1 << ". ";
      users[i].print_info();
    }
    cout << ">> ";
    int u;
    cin >> u;
    selectMode(users[u-1]);
  }
}

void printLeaderboard() {
  if (users.size() == 0)
    cout <<"\033[1;31m--Error: No player record \033[0m "<< endl;
  else {
    vector<User> ranking = users;
    sort(ranking.begin(), ranking.end());

    for (int i = 0; i < users.size(); i++)
      cout << "No." << i+1 << " " << ranking[i].name << " " << ranking[i].score << endl;
  }
}

void loadGame() {
  string load_file;
  cout <<"\033[1;32mLoad from (file name): \033[0m "<< endl;
  cin >> load_file;

  ifstream fin(load_file.c_str());

  if (fin.fail())
    cout <<"\033[1;31m--File access error \033[0m "<< endl;
  else {
    users.clear();
    string name;
    while (fin >> name) {
      int score, level, money;
      fin >> score >> level >> money;
      User u(name, score, level, money);
      users.push_back(u);
    }
    fin.close();
  }
}

void saveGame() {
  string save_file;
  cout <<"\033[1;32mSave as (file name): \033[0m "<< endl;
  cin >> save_file;

  ofstream fout(save_file.c_str());

  if (fout.fail())
    cout <<"\033[1;31m--File access error \033[0m "<< endl;
  else {
    for (int i = 0; i < users.size(); i++)
      fout << users[i].name << ' ' << users[i].score << ' ' << users[i].level << ' ' << users[i].money << endl;
    fout.close();
  }
}
