#include <iostream>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <ctime>
#include "fifteenTiles_header.h"

using namespace std;

// Capture characters from standard input without waiting for enter to be pressed
char getch(void) 
{
  struct termios oldattr, newattr;
  char ch;
  tcgetattr(STDIN_FILENO, &oldattr);
  newattr = oldattr;
  newattr.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
  return ch;
}

// Time limit ------------------------------
long int getTime();
long int getTime()
{
    time_t t = std::time(0);
    return t; 
}
long int startTime = getTime();
const int gameDuration = 300;
bool timeout;
// -----------------------------------------

int main()
{
    int difficulty = 1; // Variable for difficulty of game, assigned by level_manager BASH
    bool gameFinished = false;
    char movement;
    FifteenTiles Game(difficulty);

    cout << "\nHello " << getlogin() << endl;
    cout << "\nYou find yourself in a room with a large 4-by-4 grid containing 15 tiles labeled 1-15 in hexadecimal notation, the tiles are scattered in random order..." << endl;
    cout << "\n“You have 5 minutes to arrange the 15 tiles from low to high, begin”" << endl;

    do
    {
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
    
    int anyChar;
    cout << endl<<endl << "Enter any key to continue..." << endl;
    cin >> anyChar;
    cin.clear();

    return 1;
}