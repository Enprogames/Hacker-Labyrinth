#include "LvlManager.h"
#include <iostream>
  using namespace std;

int main() {

  lvlMan G(6);

  bool gameOver = false;
  
  while (!gameOver) 
  {

    // debug print, not necessary
    cout << G.getPuzzleSize() << " Puzzles Left!" << endl;

    if(G.getPuzzleSize() == 0)
    {
      break;
    }

    // call to the random level
    G.startLvl(G.getLvl());
  }

  cout << "Game Over! \n";
  return 0;
}