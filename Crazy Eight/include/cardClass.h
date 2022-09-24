#ifndef CARDCLASS_H_INCLUDED
#define CARDCLASS_H_INCLUDED

#include <iostream>

/**
*Implements a Card
*/
class Card {
 public:
   /**
   * Default constuctor
   */

    Card();
    /**
    * constuctor, creates the card using the passed rank and suit
    * rank - rank of this card
    * suit - suit of this card
    */
    Card(int rank, char suit);

    /**
    * returns the rank of the card
    */
    int getRank();

    /**
    * returns the suit of the card
    */
    char getSuit();

    /**
    * Calculates the value of the card.
    * Cards rank 1-9 (except 8) will be worth their rank
    * Cards rank 10-13 (11, 12, 13 = Jack, Queen, King) are worth 10 points
    * Cards ranked 8 will be worth 50 points.
    */
    int getValue();

    /**
    * changes the suit of the cardClass
    * suit - suit to be given for the card
    */
    void setSuit(char character);

    /**
    * changes the rank of the cardClass
    * rank - rank to be given for the card
    */
    void setRank(int ranking);

    /**
    * compares this card to another card
    * otherCard the card being compared to
    * returns true if this card has the same suit or rank. False otherwise.
    */
    bool compareCard(Card otherCard);

 private:
    int rank = 0;
    char suit = 'z';
};

#endif // CARDCLASS_H_INCLUDED
