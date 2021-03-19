# Beat the Dealer
Text-based game for engg1340/comp2113 project

## Team members:
- Kwok Shi Ming Jasmine
- Wong Hei Ching Kira

## Game description:
- **Beat the Dealer** is a classic drinking game

## Game rules:
- 52 poker cards
- the player has to choose 'single player' mode OR 'vs Computer' mode (simple AI)
- the player guess the card's:
  - for card 3 - K, the player has to guess whether the next card is larger or smaller than the previous one
  - for card A and 2, the player has to guess whether the next card is red or black
 
1. 'Single player' mode
- if guessed right, proceed to the next card
- until the player guessed wrong OR the player guessed correct for 7 consecutive times
  1. If the player guessed wrong:
   - Gameover (reset score) OR pay money to resurrect
  2. If the player guessed correct for 7 consecutive times:
   - Proceed to next level AND ++money

2. 'vs Computer' mode
- if guessed right, AI's turn
- until the player or the AI guessed wrong 
  1. If the player guessed wrong:
   - Gameover (reset score) OR pay money to resurrect
  2. If the AI guessed wrong:
   - ++moeny 
                                                                                                                                                                        
## List of features: (with code requirements 1-5)

1. Generation of random game sets or events
2. Data structures for storing game status
3. Dynamic memory management
4. File input/output (e.g., for loading/saving game status)
5. Program codes in multiple files

- random card generation **(1)**
- account system: **(2,3,4)**
  - unique id name
  - supports multiple single players
  - leaderboard system
    - only suitable in 'single player' mode
- money system: **(2,3,4)**
  - before each level, the player can buy items in the store
    - card revealer
    - x2 money
    - x2 score
  - each winning rounds ++money
  - each resurrections --money
  - each gameovers --money
- score system: **(2,3,4)**
  - each winning rounds ++score
  - each winning levels ++score 
  - each gameovers -> reset to 0
- 'single player' mode AND 'vs Computer' mode (simple AI) 
- level system 
  - higher level gains more score
    - i.e. level 1 ++score, level 2 x2 score, level 3 x3 score ... 

**(5)**: Makefile, header file, function files and the main file

