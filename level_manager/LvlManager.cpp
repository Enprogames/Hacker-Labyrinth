#include "LvlManager.h"
#include <iostream>
  using namespace std;

// LEVEL MANAGER MAIN

//  Sebastien Van Den Bremt
//  Jasper Charlinski

// This program keeps track of the current level number, and the number of levels remaining in the game.
// A random level number is generated base on how many levels remain in the game,
// startEndLvl.sh is then called and passed the random level number.


int main() {

  int numLvls = 6; // Number of levels in the game + 1 
  lvlMan G(numLvls);

  bool gameOver = false;
  while (!gameOver) 
  {
    // debug print, not necessary
    cout << G.getPuzzleSize() << " Puzzles Left!" << endl;

    if(G.getPuzzleSize() == 0)
    {
      cout << "\n\nCongratulations " << getlogin() << ", you have reached the final level!!" << endl;
      G.finalLvl();
      return 1;
    }

    if (!G.startLvl(G.getLvl())) // call to the random level
    {
      cout << "Game Over! \n"; // if level failed
      return 0;
    }

    G.getExitCode(); // add random digit to final_code.txt
  }
  
  return 0;
}