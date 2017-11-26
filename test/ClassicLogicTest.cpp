/**************
* Student name: Gilad Madmon
* Student ID: 305132599
* 
* Student name: Dafna Magid
* Student ID: 315635870
**************/
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "../include/ClassicLogic.h"

using namespace std;

class ClassicLogicTest : public testing::Test {
 public:
  virtual void SetUp() {
    ClassicLogicTest::logic_ = ClassicLogic();
  }

  virtual void TearDown() {
  }

 protected:
  ClassicLogic logic_;
  virtual bool CheckMoves(vector<Position> &wanted_moves, PlayerColor player_color, Board &board);
};

bool ClassicLogicTest::CheckMoves(vector<Position> &wanted_moves, PlayerColor player_color, Board &board) {
  vector<Position> possible_moves = logic_.PossibleMoves(player_color, board);
  bool is_good = wanted_moves.size() == possible_moves.size();

  for (vector<Position>::iterator it = wanted_moves.begin(); it != wanted_moves.end(); ++it) {
    is_good = is_good && (std::find(possible_moves.begin(), possible_moves.end(), *it) != possible_moves.end());
  }

  return is_good;
}

TEST_F(ClassicLogicTest, PossibleMovesStart) {
  Board board;
  vector<Position> wanted_moves;

  wanted_moves.push_back(Position(4, 3));
  wanted_moves.push_back(Position(3, 4));
  wanted_moves.push_back(Position(5, 6));
  wanted_moves.push_back(Position(6, 5));

  EXPECT_TRUE(CheckMoves(wanted_moves, Black, board));

  wanted_moves.clear();
  wanted_moves.push_back(Position(3, 5));
  wanted_moves.push_back(Position(4, 6));
  wanted_moves.push_back(Position(5, 3));
  wanted_moves.push_back(Position(6, 4));

  EXPECT_TRUE(CheckMoves(wanted_moves, White, board));
}

TEST_F(ClassicLogicTest, PossibleMovesNoMoves) {
  Board board;
  vector<Position> wanted_moves;

  board.SetColorAtPosition(4, 4, Black);
  board.SetColorAtPosition(5, 5, Black);

  EXPECT_TRUE(CheckMoves(wanted_moves, Black, board));
  EXPECT_TRUE(CheckMoves(wanted_moves, White, board));
}

Board MidGameBoard() {
  Board board;

  board.SetColorAtPosition(1, 4, Black);
  board.SetColorAtPosition(2, 4, Black);
  board.SetColorAtPosition(3, 4, Black);
  board.SetColorAtPosition(4, 4, Black);
  board.SetColorAtPosition(5, 4, Black);
  board.SetColorAtPosition(3, 6, Black);
  board.SetColorAtPosition(1, 5, White);
  board.SetColorAtPosition(2, 5, White);
  board.SetColorAtPosition(3, 5, White);
  board.SetColorAtPosition(4, 5, White);
  board.SetColorAtPosition(5, 5, White);
  board.SetColorAtPosition(3, 3, White);
  board.SetColorAtPosition(5, 3, White);
  board.SetColorAtPosition(5, 6, White);
  board.SetColorAtPosition(5, 7, White);
  board.SetColorAtPosition(6, 3, White);
  board.SetColorAtPosition(6, 4, White);
  board.SetColorAtPosition(7, 3, White);

  return board;
}

vector<Position> WhiteMidGamePossibleMoves() {
  vector<Position> possible_moves;

  possible_moves.push_back(Position(1, 3));
  possible_moves.push_back(Position(2, 3));
  possible_moves.push_back(Position(2, 7));
  possible_moves.push_back(Position(3, 7));
  possible_moves.push_back(Position(4, 3));
  possible_moves.push_back(Position(4, 7));

  return possible_moves;
}

vector<Position> BlackMidGamePossibleMoves() {
  vector<Position> possible_moves;

  possible_moves.push_back(Position(1, 6));
  possible_moves.push_back(Position(2, 2));
  possible_moves.push_back(Position(2, 6));
  possible_moves.push_back(Position(3, 2));
  possible_moves.push_back(Position(4, 2));
  possible_moves.push_back(Position(4, 6));
  possible_moves.push_back(Position(5, 2));
  possible_moves.push_back(Position(5, 8));
  possible_moves.push_back(Position(6, 2));
  possible_moves.push_back(Position(6, 6));
  possible_moves.push_back(Position(6, 7));
  possible_moves.push_back(Position(7, 2));
  possible_moves.push_back(Position(7, 4));

  return possible_moves;
}

TEST_F(ClassicLogicTest, PossibleMovesMidGame) {
  Board board = MidGameBoard();
  vector<Position> wanted_moves = BlackMidGamePossibleMoves();

  EXPECT_TRUE(CheckMoves(wanted_moves, Black, board));

  wanted_moves = WhiteMidGamePossibleMoves();

  EXPECT_TRUE(CheckMoves(wanted_moves, White, board));
}
