#pragma once
//#include "LvlFunctions.cpp"
//#include "LvlManager.cpp"

#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

class lvlMan {
private:

  int gameSize; 
  std::vector<int> Puzzle;

  int selectRandomLvl();
  void puzzleCall(int lvl);

public:

  lvlMan(int numLvls);
  lvlMan();
  ~lvlMan();

  void pathChoice();
  void startLvl(int lvl){puzzleCall(lvl);};
  int getLvl(){return selectRandomLvl();};
  int getPuzzleSize(){return Puzzle.size();}
  int getGamesize(){return gameSize;};
};