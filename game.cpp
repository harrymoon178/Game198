#include <iostream>
#include <vector>
#include "game.h"
#include "mechanics.h"

vector<Card> cards;

void single(User &usr) {
    int count;
    bool play = true;

    while (play) {
      cards.clear();
      usr.print_info();

      int *p_inv = store(usr);

      randomCard();   // initial card
      count = 0;
      while (count < 7) {
        printCards();

        if (cards.size() == 52) {   // player wins if all cards are drawn
          play = levelUp(usr, p_inv);
          break;
        }

        randomCard();

        Card currentcard = cards[cards.size()-2];
        Card nextcard = cards[cards.size()-1];

        // use card revealer?
        bool reveal = cardRevealer(p_inv);

        if (reveal) {
          cout << "You used the Card revealer." << endl;
          count++;
        }
        else {
          int result;
      		if (currentcard.rank_idx > 1) {
            while (1) {
            result = GuessSize(currentcard, nextcard);
            if (result != -1)
              break;
            }
          }
      		else {
            while (1) {
            result = GuessColour(nextcard);
            if (result != -1)
              break;
            }
          }

          bool gameover = result != 0;
      		if (gameover) {
            printCards();
            bool resurrect = gameOver(usr, result);
            if (!resurrect) {
              play = false;
              break;
            }
          }
          else
            count++;
        }

        cout << "Streak: " << count << endl;
      }

    if (count == 7) {
      printCards();
      play = levelUp(usr, p_inv);
      delete p_inv;
    }

  }
}

bool sameCard(int card_idx) {
  for (int i = 0; i < cards.size(); i++)
    if (cards[i].idx == card_idx)
      return 1;
  return 0;
}

void randomCard() {
  srand(time(NULL)); // seeding the pseudo-random generator
  int card_idx = rand() % 52;   // generate random card

  while (sameCard(card_idx)) //loop until no same card is generated
    card_idx = rand() % 52;

  Card c(card_idx);
  cards.push_back(c);   // add card to cards
}

void printCards() {
  for (int i = 0; i < cards.size(); i++) {
    cards[i].print_card();
    cout << " ";
  }
  cout << endl;
}
