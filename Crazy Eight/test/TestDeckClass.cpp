#include "deckClass.h"
#include "cardClass.h"
#include "gtest/gtest.h"

/*
* On construction, check if deck is empty.
*/
TEST(TestDeckClass, constuctorTest) {
  Deck* d = new Deck();
  EXPECT_EQ(d->currentSize(), 0);
}

/*
* Adding a card into an empty deck and checking the deck's
* size and confirming the card's existence in the deck.
*/
TEST(TestDeckClass, addCardEmptyDeckTest) {
  Deck* d = new Deck();
  d->addCard(d->currentSize(), 5, 'H');

  EXPECT_EQ(d->currentSize(), 1);
  EXPECT_EQ(d->deckGetRank(1), 5);
  EXPECT_EQ(d->deckGetSuit(1), 'H');

  delete d;
}

/*
* Adding a card into a filled deck and checking the deck's
* size and confirming the card positions in the deck.
*/
TEST(TestDeckClass, addCardFilledDeckTest) {
  Deck* d = new Deck();
  d->addCard(d->currentSize(), 5, 'H');
  d->addCard(d->currentSize(), 10, 'S');
  d->addCard(d->currentSize(), 4, 'C');
  d->addCard(d->currentSize(), 8, 'D');

  EXPECT_EQ(d->currentSize(), 4);

  EXPECT_EQ(d->deckGetRank(1), 5);
  EXPECT_EQ(d->deckGetRank(2), 10);
  EXPECT_EQ(d->deckGetRank(3), 4);
  EXPECT_EQ(d->deckGetRank(4), 8);

  EXPECT_EQ(d->deckGetSuit(1), 'H');
  EXPECT_EQ(d->deckGetSuit(2), 'S');
  EXPECT_EQ(d->deckGetSuit(3), 'C');
  EXPECT_EQ(d->deckGetSuit(4), 'D');

  delete d;
}

/*
* Removing a card from the middle of a deck and
* confirming that it does not exist in the deck anymore.
*/
TEST(TestDeckClass, removeCardMiddleDeckTest) {
  Deck* d = new Deck();
  d->addCard(d->currentSize(), 5, 'H');
  d->addCard(d->currentSize(), 10, 'S');
  d->addCard(d->currentSize(), 4, 'C');
  d->addCard(d->currentSize(), 8, 'D');

  d->deckDisplayCards();

  d->removeCard(3);

  d->deckDisplayCards();

  EXPECT_EQ(d->currentSize(), 3);
  EXPECT_EQ(d->deckGetRank(3), 8);
  EXPECT_EQ(d->deckGetSuit(3), 'D');

  delete d;
}

/*
* Removing a card from the top of a deck and
* confirming that it does not exist in the deck anymore.
*/
TEST(TestDeckClass, removeCardTopDeckTest) {
  Deck* d = new Deck();
  d->addCard(d->currentSize(), 5, 'H');
  d->addCard(d->currentSize(), 10, 'S');
  d->addCard(d->currentSize(), 4, 'C');
  d->addCard(d->currentSize(), 8, 'D');

  d->removeCard(d->currentSize());

  EXPECT_EQ(d->currentSize(), 3);
  EXPECT_EQ(d->deckGetRank(d->currentSize()), 4);
  EXPECT_EQ(d->deckGetSuit(d->currentSize()), 'C');

  delete d;
}

/*
* Removing a card from the bottom of a deck and
* confirming that it does not exist in the deck anymore.
*/
TEST(TestDeckClass, removeCardBottomDeckTest) {
  Deck* d = new Deck();
  d->addCard(d->currentSize(), 5, 'H');
  d->addCard(d->currentSize(), 10, 'S');
  d->addCard(d->currentSize(), 4, 'C');
  d->addCard(d->currentSize(), 8, 'D');

  d->deckDisplayCards();

  d->removeCard(1);

  d->deckDisplayCards();

  EXPECT_EQ(d->currentSize(), 3);
  EXPECT_EQ(d->deckGetRank(1), 8);
  EXPECT_EQ(d->deckGetSuit(1), 'D');

  delete d;
}

/*
* Removing a card from an empty deck.

TEST(TestDeckClass, removeCardEmptyDeckTest) {
  Deck* d = new Deck();
  d->removeCard(1);

  EXPECT_EQ(d->currentSize(), 0);

  delete d;
}
*/
/*
* Transfering a card from one deck to the top of another deck.
*/
TEST(TestDeckClass, transferTest) {
  Deck* d1 = new Deck();
  Deck* d2 = new Deck();

  d1->addCard(d1->currentSize(), 5, 'H');
  d1->addCard(d1->currentSize(), 10, 'S');
  d2->addCard(d2->currentSize(), 4, 'C');
  d2->addCard(d2->currentSize(), 8, 'D');

  d1->transfer(2, d2);

  EXPECT_EQ(d1->currentSize(), 1);
  EXPECT_EQ(d2->currentSize(), 3);
  EXPECT_EQ(d2->deckGetRank(3), 10);
  EXPECT_EQ(d2->deckGetSuit(3), 'S');

  delete d2;
  delete d1;
}

/*
* Transfering a card from an empty deck to another deck.

TEST(TestDeckClass, transferFromEmptyDeckTest) {
  Deck* d1 = new Deck();
  Deck* d2 = new Deck();

  d2->addCard(d2->currentSize(), 4, 'C');
  d2->addCard(d2->currentSize(), 8, 'D');

  d1->transfer(2, d2);

  EXPECT_EQ(d1->currentSize(), 0);
  EXPECT_EQ(d2->currentSize(), 2);

  delete d2;
  delete d1;
}

/*
* Testing if this function can actually find a suit in a deck.

TEST(TestDeckClass, searchMatchedSuitFoundTest) {
  Deck* d = new Deck();
  d->addCard(d->currentSize(), 4, 'C');
  d->addCard(d->currentSize(), 8, 'D');

  EXPECT_EQ(d->searchMatchedSuit('D'), 2);

  delete d;
}

/*
* Testing if this function returns 0 if match not found.
*/
TEST(TestDeckClass, searchMatchedSuitNotFoundTest) {
  Deck* d = new Deck();
  d->addCard(d->currentSize(), 4, 'C');
  d->addCard(d->currentSize(), 8, 'D');

  EXPECT_EQ(d->searchMatchedSuit('S'), 0);

  delete d;
}

/*
* Testing if this function can actually find a suit in a deck.

TEST(TestDeckClass, searchMatchedRankFoundTest) {
  Deck* d = new Deck();
  d->addCard(d->currentSize(), 4, 'C');
  d->addCard(d->currentSize(), 8, 'D');

  EXPECT_EQ(d->searchMatchedRank(8), 2);

  delete d;
}

/*
* Testing if this function returns 0 if match not found.

TEST(TestDeckClass, searchMatchedRankNotFoundTest) {
  Deck* d = new Deck();
  d->addCard(d->currentSize(), 4, 'C');
  d->addCard(d->currentSize(), 8, 'D');

  EXPECT_EQ(d->searchMatchedRank(5), 0);

  delete d;
}

/*
* Checking for empty size

TEST(TestDeckClass, currentSizeEmptyTest) {
  Deck* d = new Deck();
  EXPECT_EQ(d->currentSize(), 0);
  delete d;
}

/*
* Checking for deck size

TEST(TestDeckClass, currentSizeFilledTest) {
  Deck* d = new Deck();
  d->addCard(d->currentSize(), 4, 'C');
  d->addCard(d->currentSize(), 8, 'D');

  EXPECT_EQ(d->currentSize(), 2);
  delete d;
}

/*
* Checking if score is calculated correctly. Refer to getValue()
* documentation in cardClass for card values.

TEST(TestDeckClass, calculateScoreTest) {
  Deck* d = new Deck();

  d->addCard(d->currentSize(), 1, 'C');
  d->addCard(d->currentSize(), 8, 'D');
  d->addCard(d->currentSize(), 12, 'D');

  EXPECT_EQ(d->calculateScore(), 61);
  delete d;
}

/*
* Checking if score gets calculated to 0

TEST(TestDeckClass, calculateScoreEmptyTest) {
  Deck* d = new Deck();
  EXPECT_EQ(d->calculateScore(), 0);
  delete d;
}

/*
* Check if some cards aren't in the same spot.
* disabled cause not implemented yet
*/
TEST(TestDeckClass, DISABLED_shuffleTest) {
  Deck* d = new Deck();
  //NOTHING YET

  delete d;
}

/*
* Check if card suit has been changed
* disabled because i dont know if it's possible without user input.
*/
TEST(TestDeckClass, DISABLED_deckSetSuitTest) {
  Deck* d = new Deck();
  d->addCard(d->currentSize(), 5, 'H');
  d->addCard(d->currentSize(), 10, 'S');
  d->addCard(d->currentSize(), 4, 'C');
  d->addCard(d->currentSize(), 8, 'D');

  d->deckSetSuit8();

  delete d;
}

/*
* Check if comparison returns true when suit matches
* Disabled because deck parameter is not a pointer
*/
TEST(TestDeckClass, compareStackCardSuitTest) {
  Deck* d = new Deck();
  Deck* stack = new Deck();
  d->addCard(d->currentSize(), 5, 'H');
  d->addCard(d->currentSize(), 10, 'D');
  stack->addCard(stack->currentSize(), 6, 'C');
  stack->addCard(stack->currentSize(), 4, 'H');

  EXPECT_TRUE(d->compareStackCard(1, stack));
  EXPECT_FALSE(d->compareStackCard(2, stack));


  delete d, stack;
}

/*
* Check if comparison returns true when rank matches
* Disabled because deck parameter is not a pointer
*/
TEST(TestDeckClass, compareStackCardRankTest) {
  Deck* d = new Deck();
  Deck* stack = new Deck();
  d->addCard(d->currentSize(), 5, 'H');
  d->addCard(d->currentSize(), 10, 'D');
  stack->addCard(stack->currentSize(), 6, 'C');
  stack->addCard(stack->currentSize(), 10, 'D');

  EXPECT_TRUE(d->compareStackCard(2, stack));
  EXPECT_FALSE(d->compareStackCard(1, stack));

  delete stack;
  delete d;
}

/*
* Check if comparison returns false when no match is found
* Disabled because deck parameter is not a pointer
*/
TEST(TestDeckClass, DISABLED_compareStackCardNoMatchTest) {
  Deck* d = new Deck();
  Deck* stack = new Deck();
  d->addCard(d->currentSize(), 5, 'H');
  d->addCard(d->currentSize(), 4, 'D');
  stack->addCard(d->currentSize(), 6, 'C');
  stack->addCard(d->currentSize(), 4, 'C');

  //EXPECT_FALSE(d->compareStackCard(1, stack));

  delete stack;
  delete d;
}

/*
* Checks if function will return true when card is an 8
*/
TEST(TestDeckClass, check8TrueTest) {
  Deck* d = new Deck();
  d->addCard(d->currentSize(), 8, 'D');
  d->addCard(d->currentSize(), 5, 'D');

  EXPECT_TRUE(d->check8(1));

  delete d;
}

/*
* Checks if function will return false when card is not an 8
*/
TEST(TestDeckClass, check8FalseTest) {
  Deck* d = new Deck();
  d->addCard(d->currentSize(), 8, 'D');
  d->addCard(d->currentSize(), 5, 'D');

  EXPECT_FALSE(d->check8(2));

  delete d;
}

/*
* Checks if deck gets the correct rank
*/
TEST(TestDeckClass, deckGetRankTest) {
  Deck* d = new Deck();
  d->addCard(d->currentSize(), 8, 'D');
  d->addCard(d->currentSize(), 5, 'C');

  EXPECT_EQ(d->deckGetRank(2), 5);
  EXPECT_EQ(d->deckGetRank(1), 8);

  delete d;
}

/*
* Checks if deck gets the correct suit
*/
TEST(TestDeckClass, deckGetSuitTest) {
  Deck* d = new Deck();
  d->addCard(d->currentSize(), 8, 'D');
  d->addCard(d->currentSize(), 5, 'C');

  EXPECT_EQ(d->deckGetSuit(2), 'C');
  EXPECT_EQ(d->deckGetSuit(1), 'D');

  delete d;
}

/*
* Checks if rankConverter() converts correctly
*/
TEST(TestDeckClass, rankConverterTest) {
  Deck* d = new Deck();
  d->addCard(d->currentSize(), 3, 'H');
  d->addCard(d->currentSize(), 5, 'C');
  d->addCard(d->currentSize(), 10, 'D');
  d->addCard(d->currentSize(), 13, 'C');
  EXPECT_EQ(d->rankConverter(1), '3');
  EXPECT_EQ(d->rankConverter(2), '5');
  EXPECT_EQ(d->rankConverter(3), 'T');
  EXPECT_EQ(d->rankConverter(4), 'K');

  delete d;
}
