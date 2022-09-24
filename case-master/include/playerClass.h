#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include "cardClass.h"
#include "deckClass.h"

/**
* Inimplements a "Player"
*/
class Player {
 public:
   /**
   * Constuctor that created a player
   * As default "unknown" is given.
   */
  Player();

  /**
  * sets the name of the player
  */
  Player(std::string n);

  /**
  * returns the name of the player
  */
  std::string getName() const;

  /**
  * Displays a players hand
  */
  void checkHand();

  /**
  * If deck cards are empty card, pass a player's turn
  * If not, then add a card to hand
  */
  void passOrDraw(Deck* dealingDeck);

  /**
  * Return the number of cards in hand
  */
  int getHandSize();

  /**
  * Add a card to player's hand from a deck - d
  */
  void addCardtoHand(Deck* d);

  /**
  * Removes card from hand and puts on stack deck
  */
  void removeCardFromHand(int index, Deck* d);

  /**
  * Removes card from hand and puts on stack deck
  * Includes additional logic so people follow rules
  */
  bool removeCardFromHuman(Deck* stackDeck);

  /**
  * Provide the player options to choose :
  * Option 1: Explains the rules of game
  * Option 2: Shows a suggestion of a card to play
  */
  void help(Deck* stackDeck);

  /**
  * CPU1 Behaviour
  * Will search through the deck to find a suit match. If not,
  * then a rank match. Otherwise, draw.
  */
  void cpu1Play(Deck* stackDeck, Deck* dealingDeck);

  /**
  * CPU2 Behaviour
  * Will search through the deck to find a rank match.
  * If not, then a suit match. Otherwise, draw.
  */
  void cpu2Play(Deck* stackDeck, Deck* dealingDeck);

  /**
  * returns a players name
  */
  std::string returnName();

  /**
  * returns the current score a player has
  * based on the cards in their deck.
  */
  int returnScore();

  /**
  * returns the rank of the <cardnumber>
  * card in the players hand
  */
  int playerGetcardRank(int cardNumber);

  /**
  * returns the suit of the <cardnumber>
  * card in the players hand
  */
  char playerGetcardSuit(int cardNumber);

  /**
  * checks if a player has any cards that match
  * the top card of the stackDeck; 
  */
  bool hasMatchingCard(Deck * stackDeck);


 private:
  Deck pPlayerDeck;
  std::string playerName;
};

#endif //PLAYER_H_INCLUDED
