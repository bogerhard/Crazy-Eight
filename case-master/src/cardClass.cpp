#include <iostream>
#include "../include/cardClass.h"

Card::Card() {
}

Card::Card(int rank, char suit) : rank(rank), suit(suit) {
}

int Card::getRank() {
  return rank;
}

char Card::getSuit() {
  return suit;
}

void Card::setSuit(char s) {
  suit = s;
  return;
}

void Card::setRank(int r) {
  rank = r;
  return;
}

bool Card::compareCard(Card otherCard) {
  if (getRank() == otherCard.getRank() ||
      getSuit() == otherCard.getSuit()) {
    return true;
  }
  return false;
}

int Card::getValue() {
  int rank = this->getRank();
  if (1 <= rank && rank <= 10 && rank != 8) {
    return rank;
  } else if (10 < rank && rank < 14) {
    return 10;
  } else if (rank == 8) {
    return 50;
  } else {
    return 0;
  }
}
