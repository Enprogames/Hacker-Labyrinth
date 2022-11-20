#include "LvlManager.h"
#include <iostream>
#include <experimental/algorithm>
#include <unistd.h>

  using namespace std;

lvlMan::lvlMan(int numLvls) // Custom game constructor 
{
  for (int i = 1; i < numLvls; i++) // Create the list of levels from given variable
  {
    Puzzle.push_back(i);
  }

  gameSize = Puzzle.size();
}

lvlMan::lvlMan() // Default game constructor
{
  Puzzle = {1, 2, 3, 4, 5};

  gameSize = Puzzle.size();
}

lvlMan::~lvlMan(){}

int lvlMan::selectRandomLvl()
{
  std::vector<int> out;
  size_t nelems = 1;
  std::experimental::sample(Puzzle.begin(), Puzzle.end(), std::back_inserter(out), nelems, std::mt19937{std::random_device{}()});

  int rando = out.front();

  // deletes the level from the array after use
  Puzzle.erase(std::remove(Puzzle.begin(), Puzzle.end(), rando), Puzzle.end());

  return rando;
}

void lvlMan::puzzleCall(int lvl)
{
  string lvlCall = "./startEndLvl.sh " + to_string(lvl);
  sleep(2);
  system(lvlCall.c_str());
}
