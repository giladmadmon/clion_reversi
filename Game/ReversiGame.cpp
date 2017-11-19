/**************
* Student name: Gilad Madmon
* Student ID: 305132599
* Exercise name: Exercise 2
**************/

#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include <termio.h>
#include "ReversiGame.h"

using namespace std;
void ReversiGame::PlayGame() {
  while (!logic_.GameOver(board_)) {
    PlayOneTurn();
  }
  printer_.PrintBoard(board_);

  printer_.PrintScore(board_.CountColor(Black), board_.CountColor(White));
  printer_.PrintWinner(logic_.GetWinner(board_));
}

int KeyboardHit(void) {
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if (ch != EOF) {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}

void ReversiGame::PlayOneTurn() {
  PlayerColor current_turn = logic_.NextTurn(new_game_, board_);
  vector<Position> possible_moves = logic_.PossibleMoves(current_turn, board_);

  printer_.PrintBoard(board_);

  if (possible_moves.empty()) {
    printer_.PrintNoMoves(current_turn);
    while (!KeyboardHit());
    cin.ignore(1);
  } else {
    Position chosen_position;

    printer_.PrintCurrentTurn(current_turn);
    if (current_turn == Black) {
      chosen_position = black_player_.MakeAMove(possible_moves, printer_);
    } else {
      chosen_position = white_player_.MakeAMove(possible_moves, printer_);
    }

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
