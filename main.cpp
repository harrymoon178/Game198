#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct User {
  string name;
  int money;
  int score;
  int level;

  User (string new_usr) {
    name = new_usr;
    money = 0;
    score = 0;
    level = 1;
  }

  User (string usr, int m, int s, int l) {
    name = usr;
    money = m;
    score = s;
    level = l;
  }

  void reset() {
    score = 0;
    level = 1;
  }

  void print_info() {
    cout << name << " $" << money << " " << score << " " << level << endl;
  }
};

bool operator<(const User & a, const User & b) {
  if (a.score == b.score)
    return (a.name < b.name);
  return (a.score > b.score);
}

vector<User> users;

void selectMode(User usr) {
  cout << "Choose a game mode: " << endl;
  cout << "1 - Single Player" << endl;
  cout << "2 - vsComputer" << endl;

  int mode;
  cin >> mode;
  //if (mode == 1)
    //single(usr);
  //else if (mode == 2)
    //vsComputer(usr);
}

bool sameName(string name) {
  for (int i = 0; i < users.size(); i++) {
    if (name == users[i].name)
      return 1;
  }
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
    cout << "No player record." << endl;
  else {
    for (int i = 0; i < users.size(); i++) {
      cout << i+1 << ". ";
      users[i].print_info();
    }
    int u;
    cin >> u;

    selectMode(users[u-1]);
  }
}

void printLeaderboard() {
  if (users.size() == 0)
    cout << "No player record." << endl;
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
    cout << "File access error" << endl;
  else {
    string usr;
    while (fin >> usr) {
      int money, score, level;
      fin >> money >> score >> level;
      User u(usr, money, score, level);
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
    cout << "File access error" << endl;
  else {
    for (int i = 0; i < users.size(); i++)
      fout << users[i].name << ' ' << users[i].money << ' ' << users[i].score << ' ' << users[i].level << endl;
    fout.close();
  }
}

int main() {
  while (1) {
    cout << "-----------------" << endl;
    cout << "BEAT THE DEALER" << endl;
    cout << "1 - New Game" << endl;
    cout << "2 - Continue" << endl;
    cout << "3 - Leaderboard" << endl;
    cout << "4 - Load Game" << endl;
    cout << "5 - Save Game" << endl;
    cout << "6 - Quit" << endl;
    cout << "-----------------" << endl;

    int option;
    cin >> option;

    if (option == 1)
      newUser();
    else if (option == 2)
      selectUser();
    else if (option == 3)
      printLeaderboard();
    else if (option == 4)
      loadGame();
    else if (option == 5)
      saveGame();
    else if (option == 6)
      break;
  }
}
