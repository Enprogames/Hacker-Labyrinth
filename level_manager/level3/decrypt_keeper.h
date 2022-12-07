#pragma once
#include <bits/stdc++.h>
#include <cctype>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <termios.h>
#include <unistd.h>
using namespace std;

class decryptKeeper {
private:
  // int code = 666;

public:

  decryptKeeper(){disableBufferedInput();}
  ~decryptKeeper(){enableBufferedInput();}

  int code = 666;

  //The words are declared here
  char Word1[8] = {'P', 'X', 'O', 'W', 'L', 'S', 'O', 'B'};
  char Word2[6] = {'M', 'A', 'B', 'K', 'M', 'R'};
  char Word3[5] = {'L', 'X', 'O', 'X', 'G'};
  char Word4[4] = {'G', 'S', 'D', 'R'};
  char Word5[8] = {'Q', 'U', 'S', 'T', 'F', 'Q', 'Q', 'Z'};

  char Filler1 = ' ';
  char Filler2 = '-';

  void Text() {
    //command to print the username, and make the game text more personal
    std::string Username = getlogin();
    cout << "                   Hello " << Username << endl;
    cout
        << "You will need to decrypt a scrambled message that will give you an "
           "equation, ";
    cout << "the result is the code you need exit this room. Fail to give the "
            "proper code and you die!"
         << endl;
    cout << endl;
    cout << endl;
    cout << "Each word in the message has a different cypher key." << endl;
    cout << "You are given a set of tools, Use these keys to access them: "
         << endl;
    cout << endl;

    cout << "To Decrease the Cypher key                     'A'  " << endl;
    cout << "To Increase the Cypher key                     'D'  " << endl;
    cout << "To Enter the final 3 digit code                'E'  " << endl;
    cout << "To Transfer a decrypted word to the notePad    'T'  " << endl;
    cout << "To View the content of the notePad             'V'  " << endl;
    cout << endl;
    cout << "Here is the encrypted message: " << endl;
    cout << endl;
    cout << endl;
  }

  void messagePrint() {
    //will clear screen and print every leter as they stand
    system("clear");
    Text();
    for (int i = 0; i < 8; i++) {
      cout << Word1[i];
    }
    cout << Filler1;
    for (int i = 0; i < 6; i++) {
      cout << Word2[i];
    }
    cout << Filler2;
    for (int i = 0; i < 5; i++) {
      cout << Word3[i];
    }
    cout << Filler1;
    for (int i = 0; i < 4; i++) {
      cout << Word4[i];
    }
    cout << Filler1;
    for (int i = 0; i < 8; i++) {
      cout << Word5[i];
    }
    cout << endl;
  }

  void messagePlus() {
    //Will add a point to the cypher code, until past Z, then resets to A
    //Needs to do every word sepereately, as they are seperated by a space or a '-' 
    for (int i = 0; i < 8; i++) {
      Word1[i] += 1;
      if (Word1[i] > 90) {
        Word1[i] -= 26;
      }
    }
    for (int i = 0; i < 6; i++) {
      Word2[i] += 1;
      if (Word2[i] > 90) {
        Word2[i] -= 26;
      }
    }
    for (int i = 0; i < 5; i++) {
      Word3[i] += 1;
      if (Word3[i] > 90) {
        Word3[i] -= 26;
      }
    }
    for (int i = 0; i < 4; i++) {
      Word4[i] += 1;
      if (Word4[i] > 90) {
        Word4[i] -= 26;
      }
    }
    for (int i = 0; i < 8; i++) {
      Word5[i] += 1;
      if (Word5[i] > 90) {
        Word5[i] -= 26;
      }
    }
  }
  void messageMinus() {
    //Will Substract a point to the cypher code, until past A, then resets to Z
    //Needs to do every word sepereately, as they are seperated by a space or a '-'
    for (int i = 0; i < 8; i++) {
      Word1[i] -= 1;
      if (Word1[i] < 65) {
        Word1[i] += 26;
      }
    }
    for (int i = 0; i < 6; i++) {
      Word2[i] -= 1;
      if (Word2[i] < 65) {
        Word2[i] += 26;
      }
    }
    for (int i = 0; i < 5; i++) {
      Word3[i] -= 1;
      if (Word3[i] < 65) {
        Word3[i] += 26;
      }
    }
    for (int i = 0; i < 4; i++) {
      Word4[i] -= 1;
      if (Word4[i] < 65) {
        Word4[i] += 26;
      }
    }
    for (int i = 0; i < 8; i++) {
      Word5[i] -= 1;
      if (Word5[i] < 65) {
        Word5[i] += 26;
      }
    }
  }

  void printToFile() {
    //A function used to print a desired word to the Notepad
    int wordNum;
    int c = 0;
    string mess1 = "Word1 is: ";
    string mess2 = "Word2 is: ";
    string mess3 = "Word3 is: ";
    string mess4 = "Word4 is: ";
    while (c == 0) {
      cout << "Which word do you want stored to the notePad? (1, 2, 3, 4)"
           << endl;
      cin >> wordNum;
      while (std::cin.fail()) {
        cout << "Error, not an integer" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> wordNum;
      }
      ofstream fout("level_manager/notePad.txt", ios::app);

      switch (wordNum) {
      case 1:
        fout << "\r\n";
        cout << "The word1: ";
        fout << mess1;

        for (int i = 0; i < 8; ++i) {
          fout << Word1[i];
          cout << Word1[i];
        }
        cout << " has been added to the notepad." << endl;
        fout.close();
        c = 1;
        break;
      case 2:
        fout << "\r\n";
        cout << "The word2: ";
        fout << mess2;
        for (int i = 0; i < 6; ++i) {
          fout << Word2[i];
          cout << Word2[i];
        }

        fout << "-";
        cout << "-";
        for (int i = 0; i < 5; ++i) {
          fout << Word3[i];
          cout << Word3[i];
        }
        cout << " has been added to the notepad." << endl;
        fout.close();
        c = 1;
        break;
      case 3:
        fout << "\r\n";
        cout << "The word3: ";
        fout << mess3;
        for (int i = 0; i < 4; ++i) {
          fout << Word4[i];
          cout << Word4[i];
        }
        cout << " has been added to the notepad." << endl;
        fout.close();
        c = 1;
        break;
      case 4:
        fout << "\r\n";
        cout << "The word4: ";
        fout << mess4;
        for (int i = 0; i < 8; ++i) {
          fout << Word5[i];
          cout << Word5[i];
        }
        cout << " has been added to the notepad." << endl;
        c = 1;
        fout.close();
        break;
      default:
        cout << "You must enter a Number from 1 to 4" << endl;
        break;
      }
    }
    cout << "Press arrow 'A' or 'D' to continue, or 'E' to solve the puzzle"
         << endl;
  }


  // Idea from: https://cplusplus.com/forum/general/29137/

  void disableBufferedInput() 
  // disables buffered input allowing program to get input without user having to hit enter
  {
      struct termios t;
      tcgetattr(STDIN_FILENO, &t);
      t.c_lflag &= ~ICANON; 
      tcsetattr(STDIN_FILENO, TCSANOW, &t);
  }

  void enableBufferedInput()
  // enables buffered input so user can see what they are typing
  {
      struct termios t;
      tcgetattr(STDIN_FILENO, &t);
      t.c_lflag |= ICANON; 
      tcsetattr(STDIN_FILENO, TCSANOW, &t);
  }
};

