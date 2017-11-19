#include  <iostream>
#include "Player/HumanPlayer.h"
#include "Player/AIPlayer.h"
#include "Game/ReversiGame.h"
#include "Logic/ClassicLogic.h"
#include "Printer/ConsolePrinter.h"

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
