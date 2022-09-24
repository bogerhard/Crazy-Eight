#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include "../../include/cardClass.h"
#include "../../include/deckClass.h"
#include "../../include/playerClass.h"

void startGame() {
  std::cout << "Starting game!" << std::endl;

  //Game setup
  Deck* pDealingDeck = new Deck();
  Deck* pStackDeck = new Deck();
  Player cpu1("Computer 1"), cpu2("Computer 2");
  Player player1("Player1");
  pDealingDeck->makeDeck();
  pDealingDeck->shuffleDeck();

  //Dealing cards at the start of the game deals 5 cards to each player.
  for (int i = 0; i < 5; i++) {
    player1.addCardtoHand(pDealingDeck);
    cpu1.addCardtoHand(pDealingDeck);
    cpu2.addCardtoHand(pDealingDeck);
  }

  //Place a card on the stack deck
  // finds first non-8 card.
  int topCardIndex = 0;
  while (pDealingDeck->check8(pDealingDeck->currentSize()- topCardIndex))
    topCardIndex += 1;

  //transfer card from dealing to stackDeck
  int rankCopy = pDealingDeck->deckGetRank(pDealingDeck->currentSize());
  char suitCopy = pDealingDeck->deckGetSuit(pDealingDeck->currentSize());
  pStackDeck->addCard(pStackDeck->currentSize(), rankCopy, suitCopy);
  pDealingDeck->removeCard(pDealingDeck->currentSize() - topCardIndex);

  //Gameplay
  while (!(cpu1.getHandSize() == 0 || cpu2.getHandSize() == 0
  || player1.getHandSize() == 0)) {
     int playerChoice;
     bool loopMenu = true;

     std::cout << std::endl << "----YOUR TURN!----" << std::endl;
     std::cout << "Stack Card: " <<
     pStackDeck->rankConverter(pStackDeck->currentSize()) <<
     pStackDeck->deckGetSuit(pStackDeck->currentSize()) << std::endl;
     std::cout << "CPU1 Card Count: " << cpu1.getHandSize() << std::endl;
     std::cout << "CPU2 Card Count: " << cpu2.getHandSize() << std::endl;
     std::cout << "Your Hand: " << std::endl;
     player1.checkHand();

     while (loopMenu == true) {
       std::cout << std::endl << "Choose an option:" << std::endl;
       std::cout << "1)Play a card" << std::endl;
       std::cout << "2)Draw/Pass" << std::endl;
       std::cout << "3)Help " << std::endl;
       std::cin >> playerChoice;
       std::cin.clear();
       std::cin.ignore(500, '\n');

       if (playerChoice == 1) {
         std::cout << "Choose a card!" << std::endl;
         loopMenu = !(player1.removeCardFromHuman(pStackDeck));
       } else if (playerChoice == 2) {
           std::cout << "Draw/Pass " << std::endl;
           player1.passOrDraw(pDealingDeck);
           loopMenu = false;
       } else if (playerChoice == 3) {
           std::cout << "Help" << std::endl;
           player1.help(pStackDeck);
           loopMenu = true;
       } else {
         std::cout << "Please only pick 1, 2, or 3" << std::endl;
       }
     }

    //CPU's play their turns
    if (player1.getHandSize() == 0)
      break;

    cpu1.cpu1Play(pStackDeck, pDealingDeck);
    if (cpu1.getHandSize() == 0)  {
      break;
    }

    cpu2.cpu2Play(pStackDeck, pDealingDeck);
    if (cpu2.getHandSize() == 0) {
      break;
    }

    // No more cards to play Break While loop.
    if (pStackDeck->currentSize() == 0
       && !(player1.hasMatchingCard(pStackDeck)
       || cpu1.hasMatchingCard(pStackDeck)
       || cpu2.hasMatchingCard(pStackDeck))) {
         break;
       }
  }

  //End Game information
    std::cout << std::endl << "The Final Scores are:" << std::endl;
    std::cout << player1.returnName() << " "
    << player1.returnScore() << std::endl;
    std::cout << cpu1.returnName() << " "
    << cpu1.returnScore() << std::endl;
    std::cout << cpu2.returnName() << " "
    << cpu2.returnScore() << std::endl;

// to allow winning based on score and draws on the same outcome.
  if (player1.returnScore() <= cpu1.returnScore() &&
  player1.returnScore() <= cpu2.returnScore()) {
    std::cout << std::endl << player1.returnName() <<
    " Wins!!!!" << std::endl << std::endl;
  }
  if (cpu1.returnScore() <= player1.returnScore() &&
  cpu1.returnScore() <= cpu2.returnScore()) {
    std::cout << std::endl << cpu1.returnName() <<
    " Wins!!!!" << std::endl << std::endl;
  }
  if (cpu2.returnScore() <= cpu1.returnScore() &&
  cpu1.returnScore() <= player1.returnScore()) {
    std::cout << std::endl << cpu2.returnName() <<
    " Wins!!!!" << std::endl << std::endl;
  }
}

int main() {
  bool runApp = true;
  int playerChoice;

  std::cout << "Welcome to Crazy Eights!" << std::endl;

  while (runApp == true) {
    std::cout << "Select 1 to start a new game." << std::endl;
    std::cout << "Select 2 to quit application" << std::endl;
    std::cin >> playerChoice;
    std::cin.clear();
    std::cin.ignore(500, '\n');

    if (playerChoice == 1) {
      startGame();
    } else if (playerChoice == 2) {
      runApp = false;
    } else {
      std::cout << "Please only pick 1 or 2" << std::endl;
    }
  }
  return 0;
}
