#include <iostream>
#include <cstdlib>      // for calling srand(), rand()
#include <ctime>        // for calling time()
#include <iomanip>      // for setw()
#include "card.h"

Card::Card(int card_idx) {
  idx = card_idx;
  rank_idx = card_idx % 13;  // "A","2","3","4","5","6","7","8","9","10","J","Q","K"
  suit_idx = card_idx / 13;  // suit 1 = SPADE; 2 = HEART; 3 = CLUB; 4 = DIAMOND
  string ranks[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
  string suits[] = {SPADE, HEART, CLUB, DIAMOND};
  rank = ranks[rank_idx];
  suit = suits[suit_idx];
}

void Card::print_card() { // print the outline of a card
  for (int i = 0; i < 12; i++)
    cout << '*';
  cout << endl;
  cout << '*' << right << setw(2) << rank << suit << setw(8) << '*' << endl;
  for (int i = 0; i < 5; i++)
    cout << '*' << setw(11) << '*' << endl;
  cout << '*' << setw(9) << suit << ' ' << setw(2) << left << rank << '*' << endl;
  for (int i = 0; i < 12; i++)
    cout << '*';
  cout << endl;
}
