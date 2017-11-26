/**************
* Student name: Gilad Madmon
* Student ID: 305132599
* 
* Student name: Dafna Magid
* Student ID: 315635870
**************/

#include "gtest/gtest.h"
#include "../include/Position.h"

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