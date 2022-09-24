#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "../include/cardClass.h"
#include "../include/deckClass.h"

Deck::Deck() {
}

void Deck::addCard(int cardNumber, int rank, char suit) {
  fullDeck[cardNumber].setRank(rank);
  fullDeck[cardNumber].setSuit(suit);
}

void Deck::removeCard(int cardNumber) {
  int size = currentSize();
  if (size > 0) {
    // Adds end card ontop of card being removed
    addCard(cardNumber - 1, fullDeck[size -1].getRank(),
      fullDeck[size -1].getSuit());
    // Adds empty card ontop of end card
    addCard(size - 1, 0, 'z');
  } else {
    std::cout << "deck is already empty" << std::endl;
  }
}

void Deck::transfer(int cardNumber, Deck *transferDeck) {
  int rankTransfer;
  char suittransfer;
  rankTransfer = deckGetRank(cardNumber);
  suittransfer = deckGetSuit(cardNumber);

  transferDeck->
  addCard(cardNumber, rankTransfer, suittransfer);

  removeCard(cardNumber);
}

int Deck::searchMatchedSuit(char suit)  {
  int index = 0;
  while ((suit != deckGetSuit(index)) && (index < 52))
    index++;
  if (index == 52)
    return 0;
  return index;
}

int Deck::searchMatchedRank(int rank) {
  int index = 0;
  while ((rank != deckGetRank(index)) && (index < 52))
    index++;
  if (index == 52)
    return 0;
  return index;
}

int Deck::currentSize() {
  int i = 0;
  while ((fullDeck[i].getRank() != 0))
    i++;
  return i;
}

int Deck::calculateScore() {
  int sum = 0;
  for (int i = 0; i < currentSize(); i++)
    sum += fullDeck[i].getValue();

  return sum;
}

void Deck::makeDeck() {
  int i = 0;

  for (i; i < 13; i++) {
      fullDeck[i].setRank(i + 1);
      fullDeck[i].setSuit('S');
    }

  for (i+1; i < 26; i++) {
    fullDeck[i].setRank(i-12);
    fullDeck[i].setSuit('H');
  }

  for (i+1; i < 39; i++) {
    fullDeck[i].setRank(i-25);
    fullDeck[i].setSuit('C');
  }

  for (i+1; i < 52; i++) {
    fullDeck[i].setRank(i-38);
    fullDeck[i].setSuit('D');
  }
  fullDeck[52].setRank(0);
  fullDeck[52].setSuit('z');
}

void Deck::shuffleDeck() {
  Deck* tempDeck = new Deck;
  tempDeck->makeDeck();

  std::vector<int> shuffleVector;

  for (int i = 1; i <= currentSize() ; i++) {
    shuffleVector.push_back(i);
  }

  random_shuffle(shuffleVector.begin(), shuffleVector.end());
  int counter = 0;
  while (!shuffleVector.empty()) {
    int location = shuffleVector.back();
    addCard(counter, tempDeck->deckGetRank(location),
      tempDeck->deckGetSuit(location));
    shuffleVector.pop_back();
    counter += 1;
  }
  delete tempDeck, shuffleVector;
}

void Deck::deckSetSuit8() {
  char input = 'Z';

  while (!(input == 'S' || input == 'C' || input == 'D' || input == 'H')) {
    std::cout << "Please set the suit: 'S', 'C', 'D', or 'H' ";
    std::cin >> input;
    std::cin.clear();
    std::cin.ignore(500, '\n');
    std::cout << std::endl;
  }

  addCard(currentSize() - 1, deckGetRank((currentSize())), input);
}

bool Deck::compareStackCard(int cardNumber, Deck* stackDeck) {
  bool comparison = false;
  int stackSize = stackDeck->currentSize();

  comparison =
    fullDeck[cardNumber - 1].compareCard(stackDeck->fullDeck[stackSize - 1]);

  return comparison;
}

void Deck::deckDisplayCards() {
  for (int i = 0; i < currentSize(); i++)
    std::cout << std::left << std::setw(5) << i + 1 << " ";
  std::cout << std::endl;

  for (int i = 1; i <= currentSize(); i++)
    std::cout << rankConverter(i) << deckGetSuit(i) << "    ";
  std::cout << std::endl;
}

bool Deck::check8(int cardNumber) {
  bool isAnEight = false;
  if (fullDeck[cardNumber - 1].getRank() == 8)
    isAnEight = true;

  return isAnEight;
}

int Deck::deckGetRank(int cardNum) {
  return fullDeck[cardNum - 1].getRank();
}

char Deck::deckGetSuit(int cardNum) {
  return fullDeck[cardNum - 1].getSuit();
}

char Deck::rankConverter(int cardNum) {
  switch (deckGetRank(cardNum)) {
    case 1:
      return 'A';
    case 2:
      return '2';
    case 3:
      return '3';
    case 4:
      return '4';
    case 5:
      return '5';
    case 6:
      return '6';
    case 7:
      return '7';
    case 8:
      return '8';
    case 9:
      return '9';
    case 10:
      return 'T';
    case 11:
      return 'J';
    case 12:
      return 'Q';
    case 13:
      return 'K';
    default:
      return '?';
  }
}
