#pragma once

#include <iostream>
#include <vector>
#include <unistd.h>
  using namespace std;

// LEVEL MANAGER FUNCTIONS

//  Sebastien Van Den Bremt
//  Jasper Charlinski

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