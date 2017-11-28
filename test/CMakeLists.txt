cmake_minimum_required(VERSION 3.8)
project(Task_03_Test)

set(CMAKE_CXX_STANDARD 98)

add_subdirectory(gtest_src/googletest-release-1.8.0)
include_directories(gtest_src/googletest-release-1.8.0/googletest/include)
include_directories(gtest_src/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES main.cpp include/Player.h src/Position.cpp include/Position.h src/Player.cpp include/Player.h src/HumanPlayer.cpp include/HumanPlayer.h src/Board.cpp include/Board.h src/Logic.cpp include/Logic.h src/ClassicLogic.cpp include/ClassicLogic.h src/ReversiGame.cpp include/ReversiGame.h include/Printer.h src/ConsolePrinter.cpp include/ConsolePrinter.h include/PlayerColor.h src/AIPlayer.cpp include/AIPlayer.h test/BoardTest.cpp test/BoardTest.cpp test/HumanPlayerTest.cpp test/BasicTests.cpp test/ClassicLogicTest.cpp test/main.cpp PresetConfigs.h)


add_executable(Task_03_Test ${SOURCE_FILES})
target_link_libraries(Task_03_Test gtest gtest_main gmock)
add_test(Task_03_Test Task_03_Test)