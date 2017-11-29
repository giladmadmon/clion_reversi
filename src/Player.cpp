/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 3
**************/

#include "../include/Player.h"
Player::Player(string &name) {
  this->name_ = name;
}
string Player::GetName() {
  return this->name_;
}
