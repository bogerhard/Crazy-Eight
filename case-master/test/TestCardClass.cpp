#include "cardClass.h"
#include "gtest/gtest.h"

TEST(TestcardClass, defaulConstructorTest) {
  Card c;
  EXPECT_EQ(c.getRank(), 0);
  EXPECT_EQ(c.getSuit(), 'z');
  EXPECT_NO_THROW(c);
}

TEST(TestcardClass, constructorTest) {
  Card c(3, 'D');
  EXPECT_EQ(c.getRank(), 3);
  EXPECT_EQ(c.getSuit(), 'D');
}

TEST(TestcardClass, setSuitTest) {
  Card c(7, 'S');
  c.setSuit('H');
  EXPECT_EQ(c.getSuit(), 'H');
}

TEST(TestcardClass, setRankTest) {
  Card c(7, 'S');
  c.setRank(3);
  EXPECT_EQ(c.getRank(), 3);
}

TEST(TestcardClass, compareCardTest) {
  // Both Rank and Suit are the same
  Card c1(7, 'S');
  Card c2(7, 'S');
  EXPECT_TRUE(c1.compareCard(c2));

  // the same Suit
  Card c3(4, 'D');
  Card c4(7, 'D');
  EXPECT_TRUE(c3.compareCard(c4));

  // the same Rank
  Card c5(2, 'S');
  Card c6(2, 'H');
  EXPECT_TRUE(c5.compareCard(c6));

  // Rank and Suit are not the same
  // should return false
  Card c7(6, 'D');
  Card c8(8, 'H');
  EXPECT_FALSE(c7.compareCard(c8));
}

TEST(TestcardClass, getValueTest) {
  Card c1(4, 'S');
  int rank = c1.getRank(); // 4
  EXPECT_EQ(c1.getValue(), 4);

  Card c2(13, 'S');
  rank = c2.getRank(); // 13
  EXPECT_EQ(c2.getValue(), 10);

  Card c3(8, 'S');
  rank = c3.getRank(); // 8
  EXPECT_EQ(c3.getValue(), 50);
}
