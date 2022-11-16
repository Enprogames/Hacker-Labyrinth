#include "LvlManager.h"
#include <algorithm>
#include <experimental/algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <unistd.h>
#include <vector>
using namespace std;

int main() {
  lvlMan G;
  std::vector<int> Puzzle{1, 2, 3, 4, 5};

  while (G.GameOver == 0) {
    G.numLvl++;
    if(G.numLvl>=3){
        G.GameOver = 1;
    }
    std::vector<int> out;
    size_t nelems = 1;
    std::experimental::sample(Puzzle.begin(), Puzzle.end(), std::back_inserter(out), nelems,
                std::mt19937{std::random_device{}()});
    int rando = out.front();

    // for testing the randomizer
    // std::cout << "The random number is " << rando << std::endl;

    // call to the random level
    if (!Puzzle.empty()) {
      G.puzzleCall(rando);
    } else {
      cout << "no more puzzles left!" << endl;
    }
    // deletes the level from the array after use
    Puzzle.erase(std::remove(Puzzle.begin(), Puzzle.end(), rando),
                 Puzzle.end());

    int x = G.pathChoice();

    // for testing the path choice
    cout << "the return value for level up is :" << x << endl;

    // to test the content of puzzle
    // for (int i : Puzzle)
    //   std::cout << i << ' ';
  }
  // possibly a way to access local shell variables !!
  // ip rule add from $(InsertLocalVar) lookup ...
  return 0;
}