#include <cctype>
#include <iostream>
#include <stdio.h>
#include <string>
#include <termios.h>
#include <unistd.h>
//#include <ncurses>

#include "decrypt_keeper.h"
using namespace std;

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

  Game.Text();
  cout << "(Press A or D to get started)" << endl;
  while (1) {
    c = 0;

    switch ((c = getch())) {
    case 'a':
      Game.messagePrint();
      Game.messageMinus(); // key left
      break;
    case 'd':
      Game.messagePrint();
      Game.messagePlus(); // key right
      break;

    case 'e':
      cout << "Enter the three digit code" << endl;
      cin >> key;
      if (key == Game.code) {
        cout << "Congratulations, That is the Correct Key!!" << endl;
      } else {
        cout << "Wrong Key, You die!!" << endl;
      }
      break;
    case 't':
      cout << "Transfer last line to textfile" << endl;
      Game.printToFile();
      break;
    default:
      cout << endl << "null" << endl; // not arrow
      break;
    }
  }

  return 0;
}