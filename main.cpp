#include  <iostream>
#include "include/HumanPlayer.h"
#include "include/AIPlayer.h"
#include "include/ReversiGame.h"
#include "include/ClassicLogic.h"
#include "include/ConsolePrinter.h"

int main() {
//
  string s = "";

  ClassicLogic logic = ClassicLogic();
  Board board = Board(8);
  ConsolePrinter printer = ConsolePrinter();
  HumanPlayer black = HumanPlayer(s);
  AIPlayer white = AIPlayer(s, board, logic);
  //AIPlayer black = AIPlayer(s, board, logic);

  ReversiGame game = ReversiGame(black, white, logic, board, printer);

  game.PlayGame();
}
