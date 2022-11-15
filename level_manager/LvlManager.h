#pragma once
//#include "LvlFunctions.cpp"
//#include "LvlManager.cpp"

#include <iostream>
#include <iterator>
#include <random>
#include <vector>
using namespace std;

class lvlMan {
private:
  template <typename Iterator, typename Random>
  Iterator random_r(Iterator start, Iterator end, Random &g);

public:
  float Time;
  int GameOver = 0;
  int numLvl, currLvl;
  int lvlUp;
  // might not need to inlcude this to the header
  std::vector<int> Puzzle = {1, 2, 3, 4, 5};

  lvlMan() {};
  ~lvlMan() {};

  template <typename Iterator> Iterator random_r(Iterator start, Iterator end);
  int pathChoice();
  void puzzleCall(int Lvl);
};