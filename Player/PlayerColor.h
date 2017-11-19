/**************
* Student name: Gilad Madmon
* Student ID: 305132599
* Exercise name: Exercise 2
**************/

#ifndef TASK_02_PLAYERCOLOR_H
#define TASK_02_PLAYERCOLOR_H

#define OTHER_COLOR(color) ((color) == NoColor ? NoColor : (color) == Black ? White : Black)
enum PlayerColor { Black = 'X', White = 'O', NoColor = ' ' };

#endif //TASK_02_PLAYERCOLOR_H
