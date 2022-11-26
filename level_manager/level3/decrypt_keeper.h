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
  // int decryptKeeper::code(){
  //     //int k = code;
  //     return code;
  // }
  int code = 666;

  char Word1[8] = {'P', 'X', 'O', 'W', 'L', 'S', 'O', 'B'};
  char Word2[6] = {'M', 'A', 'B', 'K', 'M', 'R'};
  char Word3[5] = {'L', 'X', 'O', 'X', 'G'};
  char Word4[4] = {'G', 'S', 'D', 'R'};
  char Word5[8] = {'Q', 'U', 'S', 'T', 'F', 'Q', 'Q', 'Z'};

  char Filler1 = ' ';
  char Filler2 = '-';
  //ofstream fin, fout;

  void Text() {
    std::string Username = getlogin();
    cout << "Hello " << Username << endl;
    cout << "You will need to decrypt a message that will give you an "
            "equation, ";
    cout << "the result of this is the code you need to make it out of here."
         << endl;
    cout << "Each word in the message has a different cypher key." << endl;
    cout << "Use the keys 'A' to decrease the Cypher key and 'D' to increase "
            "it."<<endl;
    cout << "To finish the level by entering the 3 digit code press 'E' then Enter" << endl;
    cout << "To transfer your decrypted word to the notePad press 'T' then enter the wordNumber you wish to log" << endl;
    cout << "To view the notePad, press 'V'" << endl;
    cout << "Here is the encrypted message: " << endl;
    cout << endl;
    cout << endl;
  }

  void messagePrint() {
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
    int wordNum;
    int c = 0;
    string mess1 = "Word1 is: ";
    string mess2 = "Word2 is: ";
    string mess3 = "Word3 is: ";
    string mess4 = "Word4 is: ";
    while(c == 0) {
      cout << "Which word do you want stored to the notePad? (1, 2, 3, 4)" << endl;
      cin >> wordNum;
      while(std::cin.fail()) {
        cout << "Error, not an integer" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> wordNum;
      }
      ofstream fout("notePad.txt", ios::app);

      switch (wordNum) {
      case 1:
      fout << "\r\n";
      cout<<"The word1: ";
        fout << mess1;

        for (int i = 0; i < 8; ++i) {
          fout << Word1[i];
          cout << Word1[i];
        }
        cout<<" has been added to the notepad."<<endl;
        fout.close();
        c = 1;
        break;
      case 2:
      fout << "\r\n";
      cout<<"The word2: ";
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
        cout<<" has been added to the notepad."<<endl;
        fout.close();
        c = 1;
        break;
      case 3:
      fout << "\r\n";
      cout<<"The word3: ";
      fout << mess3;
        for (int i = 0; i < 4; ++i) {
          fout << Word4[i];
          cout << Word4[i];
        }
        cout<<" has been added to the notepad."<<endl;
        fout.close();
        c = 1;
        break;
      case 4:
      fout << "\r\n";
      cout<<"The word4: ";
      fout << mess4;
        for (int i = 0; i < 8; ++i) {
          fout << Word5[i];
          cout << Word5[i];
        }
        cout<<" has been added to the notepad."<<endl;
        c = 1;
        fout.close();
        break;
      default:
        cout << "You must enter a Number from 1 to 4" << endl;
        break;
      }
  }
  cout<<"Press arrow 'A' or 'D' to continue, or 'E' to solve the puzzle"<<endl;
  }
};