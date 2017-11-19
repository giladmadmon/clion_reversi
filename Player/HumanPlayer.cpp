/**************
* Student name: Gilad Madmon
* Student ID: 305132599
* Exercise name: Exercise 2
**************/

#include <limits>
#include <algorithm>
#include <iostream>
#include "HumanPlayer.h"

using namespace std;
HumanPlayer::HumanPlayer(string &name) : Player(name) {}

int GetIntFromUser(Printer &printer) {
  int input = -1;
  bool valid = false;
  do {
    cin >> input;
    if (cin.good()) {
      valid = true;
    } else {
      // reset the buffer's state
      cin.clear();
      // empty the buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      // print a message to the player
      printer.PrintNotANumber();
    }
  } while (!valid);

  return input;
}

Position HumanPlayer::MakeAMove(vector<Position> &possible_moves, Printer &printer) {
  int chosen_row, chosen_column;
  bool valid = false;

  do {
    Position position;

    printer.PrintPossibleMoves(possible_moves);

    printer.PrintEnterRow();
    chosen_row = GetIntFromUser(printer);

    printer.PrintEnterCol();
    chosen_column = GetIntFromUser(printer);

    position = Position(chosen_row, chosen_column);
    if (std::find(possible_moves.begin(), possible_moves.end(), position) != possible_moves.end()) {
      valid = true;
    } else {
      printer.PrintWrongMove();
    }
  } while (!valid);

  cin.ignore(1);
  return Position(chosen_row, chosen_column);
}

