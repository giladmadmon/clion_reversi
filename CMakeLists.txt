cmake_minimum_required(VERSION 3.8)
project(Task_03)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Player/Player.h Board/Position.cpp Board/Position.h Player/Player.cpp Player/Player.h Player/HumanPlayer.cpp Player/HumanPlayer.h Board/Board.cpp Board/Board.h Logic/Logic.cpp Logic/Logic.h Logic/ClassicLogic.cpp Logic/ClassicLogic.h Game/ReversiGame.cpp Game/ReversiGame.h Printer/Printer.h Printer/ConsolePrinter.cpp Printer/ConsolePrinter.h Player/PlayerColor.h)
add_executable(Task_03 ${SOURCE_FILES})