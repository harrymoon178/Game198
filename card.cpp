#include <iostream>
#include <cstdlib>      // for calling srand(), rand()
#include <ctime>        // for calling time()
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

void Card::print_card() { //print the outline of a card
for (int i = 1; i <= 6; i++)
  {
      for (int j = 1; j <= 10; j++)
      {
          if (j==10)
              cout << "* ";
          else if (i == 1 || i == 6 ||
              j == 1)        
              cout << "*";            
          else if((i==2&&j==2)||(i==5&&j==9))
              cout << rank;
          else if ((i==2&&j==3)||(i==5&&j==8))
              cout << suit;
          else
              cout << " ";
      }
      cout << endl;
  }
 
}
