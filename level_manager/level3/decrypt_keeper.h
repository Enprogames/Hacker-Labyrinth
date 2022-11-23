#pragma once
#include <bits/stdc++.h>
#include <cctype>
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

  void Text() {
    std::string Username = getlogin();
    cout << "Hello " << Username << endl;
    cout << "You will need to decrypt a message that will give you an "
            "equation, ";
    cout << "the result of this is the code you need to make it out of here."
         << endl;
    cout << "Each word in the message has a different cypher key." << endl;
    cout << "Use the keys 'A' to decrease the Cypher key and 'D' to increase "
            "it.";
    cout << "To enter the 3 digit code press 'E' then Enter" << endl;
    cout << "Here is the encrypted message: " << endl;
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

  void printToFile(){
    //NOT WORKING YET
    
    strcat(Word1, Word2);
    //strcat(Word1, Word3);
    //strcat(Word1, Word4);
    //strcat(Word1, Word5);
    cout<<Word1;
  }
};