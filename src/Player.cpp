/**************
* Student name: Gilad Madmon
* Student ID: 305132599
* Exercise name: Exercise 2
**************/

#include "../include/Player.h"
Player::Player(string &name) {
  this->name_ = name;
}
string Player::GetName() {
  return this->name_;
}
