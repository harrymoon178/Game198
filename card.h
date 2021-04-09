#ifdef CARD_H
#define CARD_H

struct Card {
  int idx;
  int rank_idx;
  int suit_idx;
  string rank;
  string suit;

  Card(int card_idx);

  void print_card();
};

bool sameCard(int card_idx);

void randomCard();

void printCards();

#endif
