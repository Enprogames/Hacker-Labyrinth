#include "LvlManager.h"
#include <algorithm>
#include <experimental/algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>
#include <unistd.h>
using namespace std;

int main() {
  lvlMan G;
  std::vector<int> Puzzle{1, 2, 3, 4, 5};

while(G.GameOver==0){

  std::vector<int> out;
  size_t nelems = 1;
  std::experimental::sample(Puzzle.begin(), Puzzle.end(), std::back_inserter(out), nelems,
              std::mt19937{std::random_device{}()});
  int rando = out.front();
  

  // call to the random level
   if (!Puzzle.empty()){
   G.puzzleCall(rando);
   }else{
    cout<<"no more puzzles left!" << endl;
   }
  //deletes the level from the array after use
  Puzzle.erase(std::remove(Puzzle.begin(), Puzzle.end(), rando), Puzzle.end());

  // int x =G.pathChoice(); 
  
}
  // possibly a way to access local shell variables !!
  // ip rule add from $(InsertLocalVar) lookup ...
  return 0;
}