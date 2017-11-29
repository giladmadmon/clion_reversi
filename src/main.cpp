/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 3
**************/

#include  <iostream>
#include "../include/HumanPlayer.h"
#include "../include/AIPlayer.h"
#include "../include/ReversiGame.h"
#include "../include/ClassicLogic.h"
#include "../include/ConsolePrinter.h"

#include <limits>

void StartGame(const Player &white, Board &board, Logic &logic);

int main() {
  int option;
  bool valid;
  Board board;
  ClassicLogic logic;

  cout << "Hello! who would you like to play Reversi with?:)" << endl;
  cout << "(1) Your Friend. " << endl;
  cout << "(2) The computer. " << endl;

  do {
    cin >> option;

    if(option != 1 && option != 2){
      cout << "wrong input, try again" << endl;
    }

    if (cin.good()) {
      valid = true;
    } else {
      cin.clear();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  } while (!valid || (option != 1 && option != 2));

  switch (option) {
    case 1:StartGame(HumanPlayer(), board, logic);
      break;
    case 2:StartGame(AIPlayer(board, logic), board, logic);
      break;
    default:return 0;
  }
}

void StartGame(const Player &white, Board &board, Logic &logic) {
  ConsolePrinter printer;
  HumanPlayer black;
  AIPlayer whiteAI(board, logic);

  ReversiGame game(black, const_cast<Player &>(white), logic, board, printer);
  game.PlayGame();
}
