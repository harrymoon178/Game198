# Beat the Dealer
Text-based game for engg1340/comp2113 project

## Team members:
- Kwok Shi Ming Jasmine
- Wong Hei Ching Kira

## Game description:
- **Beat the Dealer** is a classic drinking game by sheer luck

## Game rules:
- 52 poker cards
- the player guesses the card's:
  - for card 3 - K, the player has to guess whether the next card is larger or smaller than the previous one
  - for card A and 2, the player has to guess whether the next card is red or black
  - if guessed right:
    - proceed to the next card
    - ++money and ++score 
- until the player guessed wrong OR the player guessed correct for 7 consecutive times
  1. If the player guessed wrong:
   - Gameover (reset score) OR pay money to resurrect
  2. If the player guessed correct for 7 consecutive times:
   - Proceed to next level AND ++money

- the player can earn money to purchase items/resurrect 
                                                                                                                                                 
## List of features: (with code requirements 1-5)

1. Generation of random game sets or events
2. Data structures for storing game status
3. Dynamic memory management
4. File input/output (e.g., for loading/saving game status)
5. Program codes in multiple files

- random card generation and status storage **(1,2)**
- account system: **(2,3,4)**
  - unique id name
  - supports multiple single players
  - leaderboard system

- money system: **(2,3,4)**
  - before each level, the player can buy items in the store
    - card revealer: the next card can be revealed by the host while ++score
    - x2 money: money won in that round can be doubled
    - x2 score: score won in that round can be doubled
  - each winning rounds ++money
  - each resurrections --money
  
- score system: **(2,3,4)**
  - each winning rounds ++score
  - each winning levels ++score 
  - each gameovers -> reset to 0
  
- level system 
  - higher level gains more score and money
    - i.e. level 1 ++score ++money, level 2 x2 score x2 money, level 3 x3 score ... 

**(5)**: Makefile, header file, function files and the main file

