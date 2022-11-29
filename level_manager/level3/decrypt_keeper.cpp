#include <cctype>
#include <iostream>
#include <stdio.h>
#include <string>
#include <termios.h>
#include <ctime>
#include <unistd.h>
//#include <ncurses>

#include "decrypt_keeper.h"
#include <fstream>
using namespace std;

// Time limit ------------------------------
long int getTime();
long int getTime()
{
    time_t t = std::time(0);
    return t; 
}
long int startTime = getTime();
const int gameDuration = 10;
// -----------------------------------------



// Bypassing including getch from a library, incase ncurses.h is not installed
int getch(void) {
  struct termios oldattr, newattr;
  int ch;
  tcgetattr(STDIN_FILENO, &oldattr);
  newattr = oldattr;
  newattr.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
  return ch;
}

int main() {
  decryptKeeper Game;

  int c = 0;
  int key;
  fstream fin, fout;
  Game.Text();
  cout << "(Press A or D to get started)" << endl;
  while (1) {
    c = 0;

    switch ((c = getch())) {
    case 'a':
      // Game.messagePrint();
      Game.messageMinus(); // key left
      Game.messagePrint();
      break;
    case 'd':
      // Game.messagePrint();
      Game.messagePlus(); // key right
      Game.messagePrint();
      break;

    case 'e':
      cout << "Enter the three digit code" << endl;
      cin >> key;
      if (key == Game.code) {
        cout << "Congratulations, That is the Correct Key!!" << endl;
        system("sleep 2s");
        return 1;
      } else {
        cout << "Wrong Key, You die!!" << endl;
        system("sleep 2s");
        return 0;
      }
      break;
    case 't':
      cout << "Transfer last line to textfile" << endl;
      Game.printToFile();
      Game.messagePrint();
      break;
    case 'v':
    //Is this nessecary or should we call to the vim script?
      cout << "View contents of notePad" << endl;
      system("cat ./level_manager/notePad.txt");
      break;
    case 'm':
      system("./level_manager/inGameMenu.sh ");
      system("clear");
      Game.messagePrint();
      break;
    default:
      // cout << endl << "null" << endl; // not arrow
      break;
    }

    if (getTime() >= startTime + gameDuration)
    {
        cout << "Time limit exceeded, You die!!" << endl;
        system("sleep 2s");
        return 0;
    }
  }

  return 0;
}