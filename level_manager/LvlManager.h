#pragma once
#include "LvlFunctions.cpp"
#include "LvlManager.cpp"

#include <iostream>
#include <iterator>
#include <random>
#include <vector>
using namespace std;

class lvlMan {
public:
  float Time;
  int GameOver = 0;
  int numLvl, currLvl;
  int lvlUp;
  // might not need to inlcude this to the header
  //std::vector<int> Puzzle = {1, 2, 3, 4, 5};

  lvlMan() {}
  ~lvlMan() {}

  template <typename Iterator, typename Random>
  Iterator randomize(Iterator start, Iterator end, Random &g);
  template <typename Iterator> Iterator randomize(Iterator start, Iterator end);
  int pathChoice();
  void puzzleCall(int Lvl);
};