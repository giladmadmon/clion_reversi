/**************
* Student name: Gilad Madmon
* Student ID: 305132599
* Exercise name: Exercise 2
**************/

#include <cstdio>
#include "../include/ReversiGame.h"

using namespace std;
void ReversiGame::PlayGame() {
  while (!logic_.GameOver(board_)) {
    PlayOneTurn();
  }
  printer_.PrintBoard(board_);

  printer_.PrintScore(board_.CountColor(Black), board_.CountColor(White));
  printer_.PrintWinner(logic_.GetWinner(board_));
}

void ReversiGame::PlayOneTurn() {
  PlayerColor current_turn = logic_.NextTurn(new_game_, board_);
  vector<Position> possible_moves = logic_.PossibleMoves(current_turn, board_);
  Player *current_player = NULL;

  if (current_turn == Black) {
    current_player = &black_player_;
  } else {
    current_player = &white_player_;
  }

  printer_.PrintBoard(board_);

  if (possible_moves.empty()) {
    current_player->MakeAMove(possible_moves, printer_, current_turn);
  } else {
    Position chosen_position(0, 0);

    printer_.PrintCurrentTurn(current_turn);
    chosen_position = current_player->MakeAMove(possible_moves, printer_, current_turn);
    printer_.PrintMove(chosen_position, current_turn);

    logic_.PlaceAToken(current_turn, chosen_position.GetRow(), chosen_position.GetColumn(), board_);
  }

  new_game_ = false;
}
ReversiGame::ReversiGame(Player &black_player,
                         Player &white_player,
                         Logic &logic,
                         Board &board,
                         Printer &printer)
    : black_player_(black_player), white_player_(white_player), logic_(logic), board_(board), printer_(printer) {
  this->NewGame();
}
void ReversiGame::NewGame() {
  this->board_.Reset();
  new_game_ = true;
}
