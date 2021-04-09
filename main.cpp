#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "user.h"
#include "menu.h"

using namespace std;

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
