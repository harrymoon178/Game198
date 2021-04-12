#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "menu.h"
#include "mechanics.h"
#include "game.h"

vector<User> users;

void selectMode(User &usr) {
  cout << "Choose a game mode: " << endl;
  cout << "1 - Single Player" << endl;
  cout << "2 - vsComputer" << endl;
  cout << ">> ";
  int mode;
  cin >> mode;
  if (mode == 1)
    single(usr);
  //else if (mode == 2)
  //  vsComputer(usr);
}

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
    cout << "Name taken, try another: ";
    cin >> name;
  }
  User u(name);
  users.push_back(u);

  selectMode(u);
}

void selectUser() {
  if (users.size() == 0)
    cout << "--Error: No player record" << endl;
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
    cout << "--Error: No player record" << endl;
  else {
    vector<User> ranking = users;
    sort(ranking.begin(), ranking.end());

    for (int i = 0; i < users.size(); i++)
      cout << "No." << i+1 << " " << ranking[i].name << " " << ranking[i].score << endl;
  }
}

void loadGame() {
  string load_file;
  cout << "Load from (file name): ";
  cin >> load_file;

  ifstream fin(load_file.c_str());

  if (fin.fail())
    cout << "--File access error" << endl;
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
  cout << "Save as (file name): ";
  cin >> save_file;

  ofstream fout(save_file.c_str());

  if (fout.fail())
    cout << "--File access error" << endl;
  else {
    for (int i = 0; i < users.size(); i++)
      fout << users[i].name << ' ' << users[i].score << ' ' << users[i].level << ' ' << users[i].money << endl;
    fout.close();
  }
}
