/**************
* Student name: Gilad Madmon
* Student ID: 305132599
* Exercise name: Exercise 2
**************/

#include "Logic.h"
PlayerColor Logic::CurrentTurn() {
  return current_turn_;
}
Logic::Logic() {
  current_turn_ = NoColor;
}
