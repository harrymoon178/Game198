#include <iostream>
#include <cstdlib>      // for calling srand(), rand()
#include <ctime>        // for calling time()
#include <vector>
#include "card.h"

#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

using namespace std;

vector<Card> cards;

Card::Card(int card_idx) {
  idx = card_idx;
  rank_idx = card_idx % 13;  // "A","2","3","4","5","6","7","8","9","10","J","Q","K"
  suit_idx = card_idx / 13;  // suit 1 = SPADE; 2 = HEART; 3 = CLUB; 4 = DIAMOND
  string ranks[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
  string suits[] = {SPADE, HEART, CLUB, DIAMOND};
  rank = ranks[rank_idx];
  suit = suits[suit_idx];
}

void Card::print_card() {
  cout << rank << suit << " ";
}

bool sameCard(int card_idx) {
  for (int i = 0; i < cards.size(); i++)
    if (cards[i].idx == card_idx)
      return 1;
  return 0;
}

void randomCard() {
  srand(time(NULL)); // seeding the pseudo-random generator
  int card_idx = rand()%52;   // generate random card

  while (sameCard(card_idx)) //loop until no same card is generated
    card_idx = rand()%52;

  Card c(card_idx);
  cards.push_back(c);   // add card to cards
}

void printCards() {
  for (int i = 0; i < cards.size(); i++) {
    cards[i].print_card();
  }
  cout << endl;
}
