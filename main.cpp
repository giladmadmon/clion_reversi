#include <iostream>
#include "Player/HumanPlayer.h"
#include "Game/ReversiGame.h"
#include "Logic/ClassicLogic.h"
#include "Printer/ConsolePrinter.h"

int main() {
//
  string s = "";

  HumanPlayer black = HumanPlayer(s);
  HumanPlayer white = HumanPlayer(s);
  Board board = Board(8);
  ClassicLogic logic = ClassicLogic();
  ConsolePrinter printer = ConsolePrinter();

  ReversiGame game = ReversiGame(black, white, logic, board, printer);

  game.PlayGame();
}
