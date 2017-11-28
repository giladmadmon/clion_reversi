/**************
* Student name: Gilad Madmon
* Exercise name: Exercise 2
**************/

#include "../include/Logic.h"
PlayerColor Logic::CurrentTurn() {
  return current_turn_;
}
Logic::Logic() {
  current_turn_ = NoColor;
}
