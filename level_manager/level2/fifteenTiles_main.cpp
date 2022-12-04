// FIFTEEN TILES MAIN
// By Jasper Charlinski

// The 15 puzzle (also called Gem Puzzle, Boss Puzzle, Game of Fifteen, Mystic Square and many others) 
//  is a sliding puzzle having 15 square tiles numbered 1–15 in a frame that is 4 tiles high and 4 tiles wide, 
//  leaving one unoccupied tile position. Tiles in the same row or column of the open position can be moved by 
//  sliding them horizontally or vertically, respectively. The goal of the puzzle is to place the tiles in numerical order. 

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <ctime>
#include "fifteenTiles_header.h"

  using namespace std;


// Get current system time in seconds
long int getTime();
long int getTime()
{
    time_t t = std::time(0);
    return t; 
}

int main()
{
  const long int startTime = getTime(); // get time of when level is started
  const int gameDuration = 300; // length of time limit in seconds
  bool timeout; // true is timeout occurs
  
  int difficulty = 1; // Variable for difficulty of level
  bool gameFinished = false;
  char movement;

  FifteenTiles Game(difficulty);

  do
  {
    cout << "\nHello " << getlogin() << "!" << endl;
    cout << "\nYou find yourself in a room with a large 4-by-4 grid containing 15 tiles labeled 1-15 in hexadecimal notation, the tiles are scattered in random order..." << endl;
    cout << "\n“You have 5 minutes to arrange the 15 tiles from low to high, begin”" << endl;

    cout << "\nEnter 'm' to open menu" << endl;

    Game.printMenu();
    Game.printBoard();

    movement = getch();

    Game.move(movement);

    gameFinished = Game.complete();

    if (getTime() >= startTime + gameDuration)
    {
      gameFinished = true;
      timeout = true;
    }

    system("clear");

  } while(!gameFinished);

  if (timeout)
  {
    cout << "Time limit exceeded, You die!!" << endl;
    system("sleep 2s");
    return 0;
  }

  system("clear");
  Game.printBoard();
  cout << "Congratulation Player! you have completed this challenge." << endl;
  
  char anyChar;
  cout << endl<<endl << "Enter any key to continue..." << endl;
  cin >> anyChar;

  return 1;
}