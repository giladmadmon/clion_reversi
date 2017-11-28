/**************
* Student name: Gilad Madmon
* Student ID: 305132599
* 
* Student name: Dafna Magid
* Student ID: 315635870
**************/

#include <gtest/gtest.h>

using namespace testing;
using namespace std;

int main(int argc, char *argv[]) {
  cout.rdbuf(NULL);
  InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
  return 0;
}