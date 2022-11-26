#include <cctype>
#include <iostream>
#include <stdio.h>
#include <string>
#include <termios.h>
#include <unistd.h>
//#include <ncurses>

#include "decrypt_keeper.h"
#include <fstream>
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
      break;
    case 'v':
    //Is this nessecary or should we call to the vim script?
      cout << "View contents of notePad" << endl;
      system("cat notePad.txt");
      cout<< endl <<"Press arrow 'A' or 'D' to continue"<<endl;
      break;
    default:
      // cout << endl << "null" << endl; // not arrow
      break;
    }
  }

  return 0;
}