/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 3
**************/

#ifndef ASS2_CONSOLE_PRINTER_H
#define ASS2_CONSOLE_PRINTER_H

#include <vector>
using namespace std;

#include "Printer.h"


class ConsolePrinter : public Printer {
 public:

  /**
   * Constructor.
   */
  ConsolePrinter();

  /**
   * Prints a board.
   *
   * @param board the board to be printed.
   */
  virtual void PrintBoard(Board &board);

  /**
   * Print the possible moves.
   *
   * @param possible_moves the possible moves.
   */
  virtual void PrintPossibleMoves(vector<Position> &possible_moves);

  /**
   * Print that there are no moves.
   *
   * @param color the color of the player whom has bo moves.
   */
  virtual void PrintNoMoves(PlayerColor color);

  /**
   * Print the current turn.
   *
   * @param color the color of the player whom is his turn.
   */
  virtual void PrintCurrentTurn(PlayerColor color);

  /**
   * Ask from a player to enter a row.
   */
  virtual void PrintEnterRow();

  /**
   * Ask from a player to enter a column.
   */
  virtual void PrintEnterCol();

  /**
   * Tell the player he chose a wrong move.
   */
  virtual void PrintWrongMove();

  /**
   * Announce the winner.
   *
   * @param color the color of the winner.
   */
  virtual void PrintWinner(PlayerColor color);

  /**
   * Prints the scores of both players.
   *
   * @param black_score the black score.
   * @param white_score the white score.
   */
  virtual void PrintScore(int black_score, int white_score);

  /**
   * Tell the player he did not enter a number.
   */
  virtual void PrintNotANumber();

  /**
   * Prints the move the given player did.
   * @param position the move the was played
   * @param color the player who did the move.
   */
  virtual void PrintMove(Position &position, PlayerColor color);

  /**
  * Prints the move the AIPlayer did.
  * @param position the move the was played
  * @param color the player who did the move
  */
  virtual void PrintAINoMove(PlayerColor color);
};


#endif //ASS2_CONSOLE_PRINTER_H