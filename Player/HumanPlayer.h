/**************
* Student name: Gilad Madmon
* Student ID: 305132599
* Exercise name: Exercise 2
**************/

#ifndef TASK_02_HUMANPLAYER_H
#define TASK_02_HUMANPLAYER_H

#include <vector>
#include "Player.h"
#include "../Board/Position.h"
#include "../Printer/Printer.h"
using namespace std;

class HumanPlayer : public Player{
 public:
  /**
   * Constructor.
   *
   * @param name the name of the player.
   */
  HumanPlayer(string &name);

   /**
   * Asks the player to make a move.
   *
   * @param possible_moves the player possible moves.
   * @param printer the printer in order to communicate with the player.
   * @return the chosen position of the player.
   */
  virtual Position MakeAMove(vector<Position> &possible_moves, Printer &printer, PlayerColor color);
};

#endif //TASK_02_HUMANPLAYER_H
