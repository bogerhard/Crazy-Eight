#ifndef DECKCLASS_H_INCLUDED
#define DECKCLASS_H_INCLUDED

#include <algorithm>
#include <iostream>
#include <iomanip>
#include "cardClass.h"

/**
* Implements a deck
*/
class Deck {
 public:
   /**
   * Constuctor for a deck
   * initializes an empty deck
   */
  Deck();

  /**
  * Adds a card at a <location> in the deck of
  * rank <rank> and suit <suit>.
  */
  void addCard(int location, int rank, char suit);

  /**
  * Removes a card at location <location>
  * from the deck
  */
  void removeCard(int location);

  /**
  * Transfers a card from one deck to another.
  */
  void transfer(int index, Deck*transferDeck);

  /**
  * Searches a deck to see if it has a card
  * that matches the suit <suit>
  */
  int searchMatchedSuit(char suit);

  /**
  * Searches a deck to see if it has a card
  * that matches the rank <rank>
  */
  int searchMatchedRank(int rank);

  /**
  * returns the current size of a players deck
  */
  int currentSize();

  /**
  * Calculates the score of a players
  * deck and returns that score
  */
  int calculateScore();

  /**
  * Fills a deck with the standard 52 playing
  * cards.
  */
  void makeDeck();

  /**
  * Randomly moves cards in a deck to
  * different locations
  */
  void shuffleDeck();

  /**
  * Changes the suit of an 8 card.
  */
  void deckSetSuit8();

  /**
  * return is the player deck card at <index>
  * matches suit or rank with the card on top
  * of the stack deck.
  */
  bool compareStackCard(int index, Deck* stackDeck);

  /**
  * Displays a players deck
  */
  void deckDisplayCards();

  /**
  * returns if the card at <index> in
  * a players deck is an 8.
  */
  bool check8(int index);

  /**
  * returns the rank of the card at <index>
  * of a players deck.
  */
  int deckGetRank(int index);

  /**
  * returns the suit of the card at <index>
  * of a players deck.
  */
  char deckGetSuit(int index);

  /**
  * converts the raw rank of a card to
  * a character to allow simple display. 
  */
  char rankConverter(int index);


 private:
  Card fullDeck[53]; //52 cards + 1 sentinel value
};

#endif
