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
#include "BoardStates.h"

using namespace std;

class ClassicLogicTest : public testing::Test {
 public:
  virtual void SetUp() {
    ClassicLogicTest::logic_ = ClassicLogic();
    board_states_ = BoardStates();
  }

  virtual void TearDown() {
  }

 protected:
  BoardStates board_states_;
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

// tests the possible moves of the Black player and the White player in the start of the game
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

// tests the possible moves of the Black player and the White player when both have no moves
TEST_F(ClassicLogicTest, PossibleMovesNoMoves) {
  Board board;
  board_states_.EmptyBoard(board);
  vector<Position> wanted_moves;

  EXPECT_TRUE(CheckMoves(wanted_moves, Black, board));
  EXPECT_TRUE(CheckMoves(wanted_moves, White, board));
}

// tests the possible moves of the Black player and the White player in a certain situation of the game
TEST_F(ClassicLogicTest, PossibleMovesMidGame) {
  Board board;
  board_states_.MidGameBoard(board);
  vector<Position> wanted_moves = board_states_.BlackMidGamePossibleMoves();

  EXPECT_TRUE(CheckMoves(wanted_moves, Black, board));

  wanted_moves = board_states_.WhiteMidGamePossibleMoves();

  EXPECT_TRUE(CheckMoves(wanted_moves, White, board));
}

// tests the GetWInner function
TEST_F(ClassicLogicTest, GetWinnerNoTie) {
  Board board;

  board_states_.EmptyBoard(board);
  EXPECT_EQ(NoColor, logic_.GetWinner(board));

  board_states_.WhiteLeadsBoard(board);
  EXPECT_EQ(White, logic_.GetWinner(board));

  board_states_.BlackLeadsBoard(board);
  EXPECT_EQ((int) Black, logic_.GetWinner(board));
}


// tests the StartingPlayer function at the start of the game
TEST_F(ClassicLogicTest, StartingPlayer) {
  EXPECT_EQ((int) Black, logic_.StartingPlayer());
}



// tests the GameOver function at the middle of the game
TEST_F(ClassicLogicTest, GameOverMidGame) {
  Board board;

  // game should not end
  board.Reset();
  EXPECT_FALSE(logic_.GameOver(board));

  board_states_.MidGameBoard(board);
  EXPECT_FALSE(logic_.GameOver(board));

  board_states_.BlackNoMovesBoard(board);
  EXPECT_FALSE(logic_.GameOver(board));

  board_states_.WhiteNoMovesBoard(board);
  EXPECT_FALSE(logic_.GameOver(board));

  // game should end
  board_states_.EmptyBoard(board);
  EXPECT_TRUE(logic_.GameOver(board));

  board_states_.NoMoreMoves(board);
  EXPECT_TRUE(logic_.GameOver(board));

}

// tests the GameOver function at the end of the game
TEST_F(ClassicLogicTest, GameOverEndGAme) {

}

// tests the PlaceAToken function
TEST_F(ClassicLogicTest, PlaceAToken) {

}
