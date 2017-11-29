/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 3
**************/

#include "gtest/gtest.h"
#include "../include/AIPlayer.h"
#include "../include/ClassicLogic.h"
#include "../include/ConsolePrinter.h"
#include "BoardStates.h"

class AIPlayerTest : public testing::Test {

  virtual void SetUp() {
    string name = " ";

    AIPlayerTest::board_ = new Board();
    AIPlayerTest::logic_ = new ClassicLogic();
    AIPlayerTest::player_ = new AIPlayer(*board_, *logic_, name);
    AIPlayerTest::board_states_ = BoardStates();
    AIPlayerTest::printer_ = new ConsolePrinter();
  }

  virtual void TearDown() {
    delete logic_;
    delete player_;
    delete printer_;
    delete board_;
  }

 protected:
  AIPlayer *player_;
  Board *board_;
  ClassicLogic *logic_;
  BoardStates board_states_;
  ConsolePrinter *printer_;
};
TEST_F(AIPlayerTest, MiniMaxLogic) {
  vector<Position> moves;
  vector<Position> ai_moves;
  Position chosen_position;

  board_states_.MidGameBoard(*board_);

  ai_moves.push_back(Position(1, 6));
  ai_moves.push_back(Position(5, 8));
  moves = logic_->PossibleMoves(Black, *board_);

  chosen_position = player_->MakeAMove(moves, *printer_, Black);
  EXPECT_TRUE(std::find(ai_moves.begin(), ai_moves.end(), chosen_position) != ai_moves.end());

  ai_moves.clear();
  ai_moves.push_back(Position(1, 3));
  moves = logic_->PossibleMoves(White, *board_);

  chosen_position = player_->MakeAMove(moves,*printer_, White);
  EXPECT_TRUE(std::find(ai_moves.begin(), ai_moves.end(), chosen_position) != ai_moves.end());
}