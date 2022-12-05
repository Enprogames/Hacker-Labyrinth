#include "LvlManager.h"
#include <iostream>
  using namespace std;

int main() {

  int numLvls = 6;
  lvlMan G(numLvls);

  bool gameOver = false;
  while (!gameOver) 
  {
    // debug print, not necessary
    cout << G.getPuzzleSize() << " Puzzles Left!" << endl;

    if(G.getPuzzleSize() == 0)
    {
      cout << "\nCongratulations " << getlogin() << ", you have reached the final level!!" << endl;
      G.finalLvl();
      return 1;
    }

    // call to the random level
    if (!G.startLvl(G.getLvl()))
    {
      // Call Game Over
      cout << "Game Over! \n";
      return 0;
    }

    G.getExitCode();
  }
  
  return 1;
}