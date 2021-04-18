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
          cout << "    cout <<"\033[0;36m You used the Card Revealer. \033[0m "<< endl;" << endl;
          count++; // money and score can be added after using card revealer
        }
        else {
          int result;
      		if (currentcard.rank_idx > 1) {
            while (1) {
            result = GuessSize(currentcard, nextcard);
            if (result != -1) // if guessed wrong then end
              break;
            }
          }
      		else {
            while (1) {
            result = GuessColour(nextcard);
            if (result != -1) // if guessed wrong then end
              break;
            }
          }

          bool gameover = result != 0;
      		if (gameover) {
            printCards();
            bool resurrect = gameOver(usr, result); // resurrect?
            if (!resurrect) { 
              play = false;
              break; // if do not resurrect, game end
            }
          }
          else
            count++;
        }

        cout << "Streak: " << count << endl;
      }

    if (count == 7) { // level up when guessed correctly for 7 consecutive times
      printCards();
      play = levelUp(usr, p_inv); 
      delete p_inv;
    }

  }
}

bool sameCard(int card_idx) { //if the card size of the current card and the next card is the same, the player loses
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
