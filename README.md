# Beat the Dealer
Text-based game for engg1340/comp2113 project

## Team members:
- Kwok Shi Ming Jasmine
- Wong Hei Ching Kira

## Game description:
- **Beat the Dealer** is a classic drinking game

## Game rules:
- 52 poker cards
- the player guess the card's:
  - color / value
- if guessed right, proceed to the next card
- until the player guessed wrong OR the player guessed correct for 7 consecutive times
1. If the player guessed wrong:
  - Gameover (reset score) OR pay money to resurrect
2. If the player guessed correct for 7 consecutive times:
  - Proceed to next level AND ++money
                                                                                                                                                                        
## List of features:
- account system
  - supports multiple single players
  - leaderboard system
- money system:
  - before each level, the player can buy items in the store
    - card revealer
    - x2 money
    - x2 score
  - each winning rounds ++money
  - each resurrections --money
  - each gameovers --money
- score system
  - each winning rounds ++score
  - each winning levels ++score
  - each gameovers -> reset to 0
- random card
- 'single player' mode AND 'vs Computer' mode (simple AI)
