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
  int selectRandomExitCodeNum();
  bool puzzleCall(int lvl);
  void finalLevelCall();

public:

  lvlMan(int numLvls);
  lvlMan();
  ~lvlMan();

  void pathChoice();
  bool startLvl(int lvl){return puzzleCall(lvl);};
  void finalLvl(){finalLevelCall();};
  int getLvl(){return selectRandomLvl();};
  void getExitCode();
  int getPuzzleSize(){return Puzzle.size();};
  int getGamesize(){return gameSize;};
};