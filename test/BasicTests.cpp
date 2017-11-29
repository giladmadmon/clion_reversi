/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 3
**************/

#include "gtest/gtest.h"
#include "../include/Position.h"
//tests if the position class functions GetRow and GetColumn are working
TEST(Position,Getters) {
  Position position;
  EXPECT_EQ(position.GetRow(), 0);
  EXPECT_EQ(position.GetColumn(), 0);

  position = Position(1,5);
  EXPECT_EQ(position.GetRow(), 1);
  EXPECT_EQ(position.GetColumn(), 5);

  position = Position(159,7985);
  EXPECT_EQ(position.GetRow(), 159);
  EXPECT_EQ(position.GetColumn(), 7985);

  position = Position(-159,-7985);
  EXPECT_EQ(position.GetRow(), -159);
  EXPECT_EQ(position.GetColumn(), -7985);
}