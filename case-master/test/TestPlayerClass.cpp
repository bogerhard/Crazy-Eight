#include "playerClass.h"
#include "gtest/gtest.h"


TEST(TestPlayerClass, testConstructor) {
  Player p;
  EXPECT_EQ(p.getName(), "no name");
}

TEST(TestPlayerClass, testPlayer) {
  Player p("Jack");
  EXPECT_EQ(p.getName(), "Jack");
}

TEST(TestPlayerClass, testaddCardtoHand) {
  Player p;
  Deck* pDeck = new Deck();
  int current = p.getHandSize();
  pDeck->makeDeck();
  p.addCardtoHand(pDeck);
  p.checkHand();
  p.checkHand();
  pDeck->deckDisplayCards();

  EXPECT_EQ(current + 1, p.getHandSize());
}

TEST(TestPlayerClass, testremoveCardFromHand) {
  Player p;
  Deck* dealingDeck = new Deck();
  Deck* stackDeck = new Deck();
  dealingDeck->makeDeck();
  p.addCardtoHand(dealingDeck);
  p.addCardtoHand(dealingDeck);
  p.addCardtoHand(dealingDeck);
  p.addCardtoHand(dealingDeck);
  int current = p.getHandSize();
  p.removeCardFromHand(5, stackDeck);
  stackDeck->deckDisplayCards();

  EXPECT_EQ(current - 1, p.getHandSize());
}

TEST(TestPlayerClass, testpassorDraw) {
  Player p;
  Deck* d = new Deck();
  int current = p.getHandSize();

  // When there is no card in the dealing deck
  EXPECT_EQ(d->currentSize(), 0);
  p.passOrDraw(d);
  EXPECT_EQ(current, p.getHandSize()); // pass

  // When dealing deck is not empty
  d->addCard(d->currentSize(), 4, 'C');
  d->addCard(d->currentSize(), 8, 'D');
  EXPECT_EQ(d->currentSize(), 2);
  p.passOrDraw(d);
  EXPECT_EQ(current + 1, p.getHandSize()); // draw from deck
}

/**
* Testing cpu1Play function if it will place a card onto the stackDeck
* if they have a matching suit card at the top of their deck..
*/
TEST(TestPlayerClass, testCPU1SuitMatchTop) {
  Player* cpu1 = new Player();
  Deck* dealingDeck = new Deck();
  Deck* stackDeck = new Deck();

  stackDeck->addCard(stackDeck->currentSize(), 6, 'D');

  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'D');
  dealingDeck->addCard(dealingDeck->currentSize(), 7, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'C');

  //these cards will be added to cpu's deck
  dealingDeck->addCard(dealingDeck->currentSize(), 4, 'D');
  dealingDeck->addCard(dealingDeck->currentSize(), 3, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 2, 'H');

  cpu1->addCardtoHand(dealingDeck);
  cpu1->addCardtoHand(dealingDeck);
  cpu1->addCardtoHand(dealingDeck);

  cpu1->cpu1Play(stackDeck, dealingDeck);
  EXPECT_EQ(stackDeck->deckGetRank(stackDeck->currentSize()), 4);
  EXPECT_EQ(stackDeck->deckGetSuit(stackDeck->currentSize()), 'D');


  delete stackDeck;
  delete dealingDeck;
  delete cpu1;
}

/**
* Testing cpu1Play function if it will place a card onto the stackDeck
* if they have a matching suit card at the middle of their deck..
*/
TEST(TestPlayerClass, testCPU1SuitMatchMid) {
  Player* cpu1 = new Player();
  Deck* dealingDeck = new Deck();
  Deck* stackDeck = new Deck();

  stackDeck->addCard(stackDeck->currentSize(), 6, 'D');

  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'D');
  dealingDeck->addCard(dealingDeck->currentSize(), 7, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'C');

  //these cards will be added to cpu's deck
  dealingDeck->addCard(dealingDeck->currentSize(), 4, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 3, 'D');
  dealingDeck->addCard(dealingDeck->currentSize(), 2, 'H');

  cpu1->addCardtoHand(dealingDeck);
  cpu1->addCardtoHand(dealingDeck);
  cpu1->addCardtoHand(dealingDeck);

  cpu1->cpu1Play(stackDeck, dealingDeck);
  EXPECT_EQ(stackDeck->deckGetRank(stackDeck->currentSize()), 3);
  EXPECT_EQ(stackDeck->deckGetSuit(stackDeck->currentSize()), 'D');


  delete stackDeck;
  delete dealingDeck;
  delete cpu1;
}

/**
* Testing cpu1Play function if it will place a card onto the stackDeck
* if they have a matching rank card at the bottom of their deck..
*/
TEST(TestPlayerClass, testCPU1SuitMatchBottom) {
  Player* cpu1 = new Player();
  Deck* dealingDeck = new Deck();
  Deck* stackDeck = new Deck();

  stackDeck->addCard(stackDeck->currentSize(), 6, 'D');

  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'D');
  dealingDeck->addCard(dealingDeck->currentSize(), 7, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'C');

  //these cards will be added to cpu's deck
  dealingDeck->addCard(dealingDeck->currentSize(), 4, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 3, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 2, 'D');

  cpu1->addCardtoHand(dealingDeck);
  cpu1->addCardtoHand(dealingDeck);
  cpu1->addCardtoHand(dealingDeck);

  cpu1->cpu1Play(stackDeck, dealingDeck);
  EXPECT_EQ(stackDeck->deckGetRank(stackDeck->currentSize()), 2);
  EXPECT_EQ(stackDeck->deckGetSuit(stackDeck->currentSize()), 'D');


  delete stackDeck;
  delete dealingDeck;
  delete cpu1;
}

/**
* Testing cpu1Play function if it will place a card onto the stackDeck
* if they have a matching rank card at the top of their deck..
*/
TEST(TestPlayerClass, testCPU1RankMatchTop) {
  Player* cpu1 = new Player();
  Deck* dealingDeck = new Deck();
  Deck* stackDeck = new Deck();

  stackDeck->addCard(stackDeck->currentSize(), 6, 'D');

  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'D');
  dealingDeck->addCard(dealingDeck->currentSize(), 7, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'C');

  //these cards will be added to cpu's deck
  dealingDeck->addCard(dealingDeck->currentSize(), 6, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 3, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 2, 'H');

  cpu1->addCardtoHand(dealingDeck);
  cpu1->addCardtoHand(dealingDeck);
  cpu1->addCardtoHand(dealingDeck);

  cpu1->cpu1Play(stackDeck, dealingDeck);
  EXPECT_EQ(stackDeck->deckGetRank(stackDeck->currentSize()), 6);
  EXPECT_EQ(stackDeck->deckGetSuit(stackDeck->currentSize()), 'S');


  delete stackDeck;
  delete dealingDeck;
  delete cpu1;
}

/**
* Testing cpu1Play function if it will place a card onto the stackDeck
* if they have a matching rank card at the middle of their deck..
*/
TEST(TestPlayerClass, testCPU1RankMatchMid) {
  Player* cpu1 = new Player();
  Deck* dealingDeck = new Deck();
  Deck* stackDeck = new Deck();

  stackDeck->addCard(stackDeck->currentSize(), 6, 'D');

  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'D');
  dealingDeck->addCard(dealingDeck->currentSize(), 7, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'C');

  //these cards will be added to cpu's deck
  dealingDeck->addCard(dealingDeck->currentSize(), 4, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 6, 'H');
  dealingDeck->addCard(dealingDeck->currentSize(), 2, 'H');

  cpu1->addCardtoHand(dealingDeck);
  cpu1->addCardtoHand(dealingDeck);
  cpu1->addCardtoHand(dealingDeck);

  cpu1->cpu1Play(stackDeck, dealingDeck);
  EXPECT_EQ(stackDeck->deckGetRank(stackDeck->currentSize()), 6);
  EXPECT_EQ(stackDeck->deckGetSuit(stackDeck->currentSize()), 'H');


  delete stackDeck;
  delete dealingDeck;
  delete cpu1;
}

/**
* Testing cpu1Play function if it will place a card onto the stackDeck
* if they have a matching rank card at the bottom of their deck.
*/
TEST(TestPlayerClass, testCPU1RankMatchBottom) {
  Player* cpu1 = new Player();
  Deck* dealingDeck = new Deck();
  Deck* stackDeck = new Deck();

  stackDeck->addCard(stackDeck->currentSize(), 6, 'D');

  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'D');
  dealingDeck->addCard(dealingDeck->currentSize(), 7, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'C');

  //these cards will be added to cpu's deck
  dealingDeck->addCard(dealingDeck->currentSize(), 4, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 3, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 6, 'C');

  cpu1->addCardtoHand(dealingDeck);
  cpu1->addCardtoHand(dealingDeck);
  cpu1->addCardtoHand(dealingDeck);

  cpu1->cpu1Play(stackDeck, dealingDeck);
  EXPECT_EQ(stackDeck->deckGetRank(stackDeck->currentSize()), 6);
  EXPECT_EQ(stackDeck->deckGetSuit(stackDeck->currentSize()), 'C');


  delete stackDeck;
  delete dealingDeck;
  delete cpu1;
}

/**
* Testing cpu1Play function if it will draw if a card
* was not found from their deck.
*/
TEST(TestPlayerClass, testCPU1DrawAndPlay) {
  Player* cpu1 = new Player();
  Deck* dealingDeck = new Deck();
  Deck* stackDeck = new Deck();

  stackDeck->addCard(stackDeck->currentSize(), 5, 'H');

  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'D');
  dealingDeck->addCard(dealingDeck->currentSize(), 7, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 5, 'C');

  //these cards will be added to cpu's deck
  dealingDeck->addCard(dealingDeck->currentSize(), 4, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 3, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 6, 'C');

  cpu1->addCardtoHand(dealingDeck);
  cpu1->addCardtoHand(dealingDeck);
  cpu1->addCardtoHand(dealingDeck);

  cpu1->cpu1Play(stackDeck, dealingDeck);
  EXPECT_EQ(stackDeck->deckGetRank(stackDeck->currentSize()), 5);
  EXPECT_EQ(stackDeck->deckGetSuit(stackDeck->currentSize()), 'H');


  delete stackDeck;
  delete dealingDeck;
  delete cpu1;
}

/**
* Testing cpu2Play function if it will place a card onto the stackDeck
* if they have a matching rank card at the top of their deck..
*/
TEST(TestPlayerClass, testCPU2RankMatchTop) {
  Player* cpu2 = new Player();
  Deck* dealingDeck = new Deck();
  Deck* stackDeck = new Deck();

  stackDeck->addCard(stackDeck->currentSize(), 6, 'D');

  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'D');
  dealingDeck->addCard(dealingDeck->currentSize(), 7, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'C');

  //these cards will be added to cpu's deck
  dealingDeck->addCard(dealingDeck->currentSize(), 6, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 3, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 2, 'H');

  cpu2->addCardtoHand(dealingDeck);
  cpu2->addCardtoHand(dealingDeck);
  cpu2->addCardtoHand(dealingDeck);

  cpu2->cpu2Play(stackDeck, dealingDeck);
  EXPECT_EQ(stackDeck->deckGetRank(stackDeck->currentSize()), 6);
  EXPECT_EQ(stackDeck->deckGetSuit(stackDeck->currentSize()), 'S');


  delete stackDeck;
  delete dealingDeck;
  delete cpu2;
}

/**
* Testing cpu2Play function if it will place a card onto the stackDeck
* if they have a matching rank card at the middle of their deck..
*/
TEST(TestPlayerClass, testCPU2RankMatchMid) {
  Player* cpu2 = new Player();
  Deck* dealingDeck = new Deck();
  Deck* stackDeck = new Deck();

  stackDeck->addCard(stackDeck->currentSize(), 6, 'D');

  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'D');
  dealingDeck->addCard(dealingDeck->currentSize(), 7, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'C');

  //these cards will be added to cpu's deck
  dealingDeck->addCard(dealingDeck->currentSize(), 4, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 6, 'H');
  dealingDeck->addCard(dealingDeck->currentSize(), 2, 'H');

  cpu2->addCardtoHand(dealingDeck);
  cpu2->addCardtoHand(dealingDeck);
  cpu2->addCardtoHand(dealingDeck);

  cpu2->cpu2Play(stackDeck, dealingDeck);
  EXPECT_EQ(stackDeck->deckGetRank(stackDeck->currentSize()), 6);
  EXPECT_EQ(stackDeck->deckGetSuit(stackDeck->currentSize()), 'H');


  delete stackDeck;
  delete dealingDeck;
  delete cpu2;
}

/**
* Testing cpu2Play function if it will place a card onto the stackDeck
* if they have a matching rank card at the bottom of their deck.
*/
TEST(TestPlayerClass, testCPU2RankMatchBottom) {
  Player* cpu2 = new Player();
  Deck* dealingDeck = new Deck();
  Deck* stackDeck = new Deck();

  stackDeck->addCard(stackDeck->currentSize(), 6, 'D');

  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'D');
  dealingDeck->addCard(dealingDeck->currentSize(), 7, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'C');

  //these cards will be added to cpu's deck
  dealingDeck->addCard(dealingDeck->currentSize(), 4, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 3, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 6, 'C');

  cpu2->addCardtoHand(dealingDeck);
  cpu2->addCardtoHand(dealingDeck);
  cpu2->addCardtoHand(dealingDeck);

  cpu2->cpu2Play(stackDeck, dealingDeck);
  EXPECT_EQ(stackDeck->deckGetRank(stackDeck->currentSize()), 6);
  EXPECT_EQ(stackDeck->deckGetSuit(stackDeck->currentSize()), 'C');


  delete stackDeck;
  delete dealingDeck;
  delete cpu2;
}

/**
* Testing cpu2Play function if it will place a card onto the stackDeck
* if they have a matching suit card at the top of their deck..
*/
TEST(TestPlayerClass, testCPU2SuitMatchTop) {
  Player* cpu2 = new Player();
  Deck* dealingDeck = new Deck();
  Deck* stackDeck = new Deck();

  stackDeck->addCard(stackDeck->currentSize(), 6, 'D');

  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'D');
  dealingDeck->addCard(dealingDeck->currentSize(), 7, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'C');

  //these cards will be added to cpu's deck
  dealingDeck->addCard(dealingDeck->currentSize(), 4, 'D');
  dealingDeck->addCard(dealingDeck->currentSize(), 3, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 2, 'H');

  cpu2->addCardtoHand(dealingDeck);
  cpu2->addCardtoHand(dealingDeck);
  cpu2->addCardtoHand(dealingDeck);

  cpu2->cpu2Play(stackDeck, dealingDeck);
  EXPECT_EQ(stackDeck->deckGetRank(stackDeck->currentSize()), 4);
  EXPECT_EQ(stackDeck->deckGetSuit(stackDeck->currentSize()), 'D');


  delete stackDeck;
  delete dealingDeck;
  delete cpu2;
}

/**
* Testing cpu2Play function if it will place a card onto the stackDeck
* if they have a matching suit card at the middle of their deck..
*/
TEST(TestPlayerClass, testCPU2SuitMatchMid) {
  Player* cpu2 = new Player();
  Deck* dealingDeck = new Deck();
  Deck* stackDeck = new Deck();

  stackDeck->addCard(stackDeck->currentSize(), 6, 'D');

  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'D');
  dealingDeck->addCard(dealingDeck->currentSize(), 7, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'C');

  //these cards will be added to cpu's deck
  dealingDeck->addCard(dealingDeck->currentSize(), 4, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 3, 'D');
  dealingDeck->addCard(dealingDeck->currentSize(), 2, 'H');

  cpu2->addCardtoHand(dealingDeck);
  cpu2->addCardtoHand(dealingDeck);
  cpu2->addCardtoHand(dealingDeck);

  cpu2->cpu2Play(stackDeck, dealingDeck);
  EXPECT_EQ(stackDeck->deckGetRank(stackDeck->currentSize()), 3);
  EXPECT_EQ(stackDeck->deckGetSuit(stackDeck->currentSize()), 'D');


  delete stackDeck;
  delete dealingDeck;
  delete cpu2;
}

/**
* Testing cpu2Play function if it will place a card onto the stackDeck
* if they have a matching rank card at the bottom of their deck..
*/
TEST(TestPlayerClass, testCPU2SuitMatchBottom) {
  Player* cpu2 = new Player();
  Deck* dealingDeck = new Deck();
  Deck* stackDeck = new Deck();

  stackDeck->addCard(stackDeck->currentSize(), 6, 'D');

  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'D');
  dealingDeck->addCard(dealingDeck->currentSize(), 7, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'C');

  //these cards will be added to cpu's deck
  dealingDeck->addCard(dealingDeck->currentSize(), 4, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 3, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 2, 'D');

  cpu2->addCardtoHand(dealingDeck);
  cpu2->addCardtoHand(dealingDeck);
  cpu2->addCardtoHand(dealingDeck);

  cpu2->cpu2Play(stackDeck, dealingDeck);
  EXPECT_EQ(stackDeck->deckGetRank(stackDeck->currentSize()), 2);
  EXPECT_EQ(stackDeck->deckGetSuit(stackDeck->currentSize()), 'D');


  delete stackDeck;
  delete dealingDeck;
  delete cpu2;
}

/**
* Testing cpu2Play function if it will draw if a card
* was not found from their deck.
*/
TEST(TestPlayerClass, testCPU2DrawAndPlay) {
  Player* cpu2 = new Player();
  Deck* dealingDeck = new Deck();
  Deck* stackDeck = new Deck();

  stackDeck->addCard(stackDeck->currentSize(), 5, 'H');

  dealingDeck->addCard(dealingDeck->currentSize(), 10, 'D');
  dealingDeck->addCard(dealingDeck->currentSize(), 7, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 5, 'C');

  //these cards will be added to cpu's deck
  dealingDeck->addCard(dealingDeck->currentSize(), 4, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 3, 'S');
  dealingDeck->addCard(dealingDeck->currentSize(), 6, 'C');

  cpu2->addCardtoHand(dealingDeck);
  cpu2->addCardtoHand(dealingDeck);
  cpu2->addCardtoHand(dealingDeck);

  cpu2->cpu2Play(stackDeck, dealingDeck);
  EXPECT_EQ(stackDeck->deckGetRank(stackDeck->currentSize()), 5);
  EXPECT_EQ(stackDeck->deckGetSuit(stackDeck->currentSize()), 'H');


  delete stackDeck;
  delete dealingDeck;
  delete cpu2;
}
