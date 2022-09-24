#include <fstream>
#include <sstream>
#include <string>
#include "../include/cardClass.h"
#include "../include/deckClass.h"
#include "../include/playerClass.h"


Player::Player() {
  playerName = "no name";
}

Player::Player(std::string n) {
  playerName = n;
}

std::string Player::getName() const {
  return playerName;
}

void Player::addCardtoHand(Deck* dealingDeck) {
  int cardNum = dealingDeck->currentSize();
  pPlayerDeck.addCard(pPlayerDeck.currentSize(),
    dealingDeck->deckGetRank(cardNum),
    dealingDeck->deckGetSuit(cardNum));

  dealingDeck->removeCard(cardNum);
}

void Player::removeCardFromHand(int cardNum, Deck* stackDeck) {
  if (cardNum > 0) {
    stackDeck->addCard(stackDeck->currentSize(),
      pPlayerDeck.deckGetRank(cardNum),
      pPlayerDeck.deckGetSuit(cardNum));

    pPlayerDeck.removeCard(cardNum);
  }
}

bool Player::removeCardFromHuman(Deck* stackDeck) {
  int input = 0;
  bool validMatch = false;

  while (!(input > 0 && input <= pPlayerDeck.currentSize())) {
    std::cout << "Stack Card: " <<
    stackDeck->rankConverter(stackDeck->currentSize()) <<
    stackDeck->deckGetSuit(stackDeck->currentSize()) <<
    std::endl;

    checkHand();
    std::cout << "Please pick a card: ";
    std::cin >> input;
    std::cin.clear();
    std::cin.ignore(500, '\n');
    std::cout << std::endl;
    if ((input > 0 && input <= pPlayerDeck.currentSize())
      && (pPlayerDeck.compareStackCard(input, stackDeck)
      ||pPlayerDeck.check8(input))) {
        validMatch = true;
    } else {
      std::cout <<
      "Please pick a card in your hand that matches " <<
      "the suit or rank of the one on the stack" <<
      std::endl;
    }
  }
  if (validMatch == true) {
    if (pPlayerDeck.check8(input) == true) {
      std::cout << "You are placing an Eight." << std::endl;
      pPlayerDeck.deckSetSuit8();
    }
    removeCardFromHand(input, stackDeck);
    return true;
  } else {
    return false;
  }
}

void Player::checkHand() {
  pPlayerDeck.deckDisplayCards();
}

void Player::passOrDraw(Deck* dealingDeck) {
  if (dealingDeck->currentSize() != 0) {
    std::cout << "Draw from Deck" << std::endl;
    addCardtoHand(dealingDeck);
    return;
  } else {
    std::cout << "Pass" << std::endl;
    return;
  }
}

void Player::help(Deck* stackDeck) {
  int answer;
  std::cout << "To check the rules of game: Enter 1" << std::endl
            << "To check suggestion of a card to play: Enter 2" << std::endl;
  std::cin >> answer;
  std::cin.clear();
  std::cin.ignore(500, '\n');

  if (answer == 1) {
      std::ifstream in;
      std::stringstream ss;
      in.open("help.txt");
      if (in.is_open()) {
        ss << in.rdbuf();
        std::cout << ss.str();
      } else {
        std::cout << "Unable to open file";
    }
  } else if (answer == 2) {
      char topCardSuit;
      int topCardRank;
      int index;

      topCardSuit = stackDeck->deckGetSuit(stackDeck->currentSize());
      topCardRank = stackDeck->deckGetRank(stackDeck->currentSize());

      index = pPlayerDeck.searchMatchedSuit(topCardSuit);
      if (index > 0) {
        pPlayerDeck.deckDisplayCards();
        std::cout << "You can play with card number " << index
                   << " (Suit matched)" << std::endl;
      } else {
          index = pPlayerDeck.searchMatchedRank(topCardRank);
          if (index > 0) {
            pPlayerDeck.deckDisplayCards();
            std::cout << "You can play with card number " << index
                      << " (Rank matched)" << std::endl;
          } else {
            std::cout << "You have no valid cards " <<
            "please draw or pass." << std::endl;
          }
        }

      } else {
    std::cout << "Please input 1 or 2." << std::endl;
  }
}

int Player::getHandSize() {
  return pPlayerDeck.currentSize();
}

void Player::cpu1Play(Deck* stackDeck, Deck* dealingDeck) {
  char topCardSuit;
  int topCardRank;
  int index;

  topCardSuit = stackDeck->deckGetSuit(stackDeck->currentSize());
  topCardRank = stackDeck->deckGetRank(stackDeck->currentSize());

  index = pPlayerDeck.searchMatchedSuit(topCardSuit);
  if (index == 0) {
    index = pPlayerDeck.searchMatchedRank(topCardRank);
    if (index == 0) {
      passOrDraw(dealingDeck);
      std::cout << "CPU1 Draws" << std::endl;
    }
  }
  if (index > 0) {
    std::cout << "CPU1 PLACES DOWN " <<
    playerGetcardRank(index) <<
    playerGetcardSuit(index) <<  std::endl;
    removeCardFromHand(index, stackDeck);
  }
}

void Player::cpu2Play(Deck* stackDeck, Deck* dealingDeck) {
  char topCardSuit;
  int topCardRank;
  int index;

  topCardSuit = stackDeck->deckGetSuit(stackDeck->currentSize());
  topCardRank = stackDeck->deckGetRank(stackDeck->currentSize());

  index = pPlayerDeck.searchMatchedRank(topCardRank);
  if (index == 0) {
    index = pPlayerDeck.searchMatchedSuit(topCardSuit);
    if (index == 0) {
      this->passOrDraw(dealingDeck);
      std::cout << "CPU2 Draws" << std::endl;
    }
  }
  if (index > 0) {
    std::cout << "CPU2 PLACES DOWN " <<
    playerGetcardRank(index) <<
    playerGetcardSuit(index) <<  std::endl;
    removeCardFromHand(index, stackDeck);
  }
}

std::string Player::returnName() {
  return playerName;
}

int Player::returnScore() {
  return pPlayerDeck.calculateScore();
}

int Player::playerGetcardRank(int cardNumber) {
  return pPlayerDeck.deckGetRank(cardNumber);
}


char Player::playerGetcardSuit(int cardNumber) {
  return pPlayerDeck.deckGetSuit(cardNumber);
}

bool Player::hasMatchingCard(Deck * stackDeck) {
  bool cardMatch = false;

  if (pPlayerDeck.searchMatchedRank(
    stackDeck->deckGetRank(stackDeck->currentSize()-1)) > 0) {
    return true;
  }

  if (pPlayerDeck.searchMatchedSuit(
    stackDeck->deckGetSuit(stackDeck->currentSize()-1)) > 0) {
    return true;
  }
}
