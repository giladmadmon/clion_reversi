/**************
* Student name: Gilad Madmon
* Student ID: 305132599
* 
* Student name: Dafna Magid
* Student ID: 315635870
**************/
#include "gtest/gtest.h"
#include "../include/Board.h"
using namespace std;

class BoardTest : public testing::Test {

  virtual void SetUp() {
    BoardTest::board_ = new Board(8);
  }

  virtual void TearDown() {

  }

 protected:
  Board *board_;
};
//what to write?
TEST_F(BoardTest, Bounds) {
  int size = board_->GetSize();

  for (int row = 1; row <= size; row++) {
    for (int col = 1; col <= size; col++) {
      EXPECT_NO_THROW(board_->SetColorAtPosition(row, col, NoColor));
      EXPECT_NO_THROW(board_->GetColorAtPosition(row, col));
    }
  }

  /*
  // lower bound
  EXPECT_THROW(board_.SetColorAtPosition(0, 0, NoColor), std::range_error);
  EXPECT_THROW(board_.SetColorAtPosition(0, 1, NoColor), std::range_error);
  EXPECT_THROW(board_.SetColorAtPosition(1, 0, NoColor), std::range_error);

  // upper bound
  EXPECT_THROW(board_.SetColorAtPosition(9, 9, NoColor), std::range_error);
  EXPECT_THROW(board_.SetColorAtPosition(8, 9, NoColor), std::range_error);
  EXPECT_THROW(board_.SetColorAtPosition(9, 8, NoColor), std::range_error);

  // 10 random out bound positive indexes.
  srand(static_cast<unsigned int>(time(NULL)));
  for (int i = 0; i < 10; i++) {
    int rand_row = rand() % (1000 - board_.GetSize()) + board_.GetSize();
    int rand_col = rand() % (1000 - board_.GetSize()) + board_.GetSize();

    EXPECT_THROW(board_.SetColorAtPosition(rand_row, rand_col, NoColor), std::out_of_range);

  }

  // 10 random out bound negative indexes.
  srand(static_cast<unsigned int>(time(NULL)));
  for (int i = 0; i < 10; i++) {
    int rand_row = -1 * rand();
    int rand_col = -1 * rand();

    EXPECT_THROW(board_.SetColorAtPosition(rand_row, rand_col, NoColor), std::out_of_range);

  }*/
}


// tests the getter on aboard with a certain placement of tokens that was placed be the setter
TEST_F(BoardTest, GettersSetters) {
  for (int row = 1; row <= board_->GetSize(); ++row) {
    for (int col = 1; col <= board_->GetSize(); ++col) {
      board_->SetColorAtPosition(row, col, Black);
      EXPECT_EQ(board_->GetColorAtPosition(row, col), Black);
      EXPECT_NE(board_->GetColorAtPosition(row, col), White);
      EXPECT_NE(board_->GetColorAtPosition(row, col), NoColor);

      board_->SetColorAtPosition(row, col, White);
      EXPECT_EQ(board_->GetColorAtPosition(row, col), White);
      EXPECT_NE(board_->GetColorAtPosition(row, col), Black);
      EXPECT_NE(board_->GetColorAtPosition(row, col), NoColor);

      board_->SetColorAtPosition(row, col, NoColor);
      EXPECT_EQ(board_->GetColorAtPosition(row, col), NoColor);
      EXPECT_NE(board_->GetColorAtPosition(row, col), White);
      EXPECT_NE(board_->GetColorAtPosition(row, col), Black);
    }
  }
}

//tests if the default size is 8
TEST_F(BoardTest, Size) {
  EXPECT_EQ(board_->GetSize(), 8);
  EXPECT_NE(board_->GetSize(), 6);

}

//tests the get CountColor function, at the statring position of the board, and after placing tokens in a certain order.
TEST_F(BoardTest, Count) {
  PlayerColor color = NoColor;

  EXPECT_EQ(board_->CountColor(Black), 2);
  EXPECT_EQ(board_->CountColor(White), 2);
  EXPECT_EQ(board_->CountColor(NoColor), 60);

  for (int row = 1; row <= board_->GetSize(); ++row) {
    for (int col = 1; col <= board_->GetSize(); ++col) {
      board_->SetColorAtPosition(row, col, color);

      switch (color) {
        case Black: color = White;
          break;
        case White: color = NoColor;
          break;
        case NoColor: color = Black;
          break;
      }
    }
  }

  EXPECT_EQ(board_->CountColor(NoColor), 22);
  EXPECT_EQ(board_->CountColor(White), 21);
  EXPECT_EQ(board_->CountColor(Black), 21);
}

//tests the Reset function, after changing the board.
TEST_F(BoardTest, Reset) {
  PlayerColor color = NoColor;

  for (int row = 1; row <= board_->GetSize(); ++row) {
    for (int col = 1; col <= board_->GetSize(); ++col) {
      board_->SetColorAtPosition(row, col, color);

      switch (color) {
        case Black: color = White;
          break;
        case White: color = NoColor;
          break;
        case NoColor: color = Black;
          break;
      }
    }
  }

  board_->Reset();

  EXPECT_EQ(board_->CountColor(Black), 2);
  EXPECT_EQ(board_->CountColor(White), 2);
  EXPECT_EQ(board_->CountColor(NoColor), 60);
}