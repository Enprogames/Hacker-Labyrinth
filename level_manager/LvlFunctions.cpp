#include "LvlManager.h"
#include <cctype>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <vector>
#include <unistd.h>
using namespace std;

// float Time;
// int GameOver = 0;
// int numLvl, currLvl;
// std::vector<int> Puzzle = {1, 2, 3, 4, 5};

// lvlMan::lvlMan(){}
// lvlMan::~lvlMan(){}

int lvlMan::pathChoice() {
  int lvlUp = system("cd level_manager/path_choice/; ./pathChoicex");
  return lvlUp;
}

void lvlMan::puzzleCall(int Lvl) {
  switch (Lvl) {
  case 1:
    system("clear");
    system("python3 level_manager/level1/rising_acid.py");
    break;
  case 2:
    system("clear");
    system(".level_manager/level2/puzzle2x");
    break;
  case 3:
    system("clear");
    cout << "The puzzle DECRYPT_KEEPER is not yet completed" << endl;
    sleep(3);
    // system("./level3/decryptx");
    break;
  case 4:
    system("clear");
    cout << "The puzzle CIPHER_ESCAPE is not yet completed" << endl;
    sleep(3);
    // system("./level4/cipherx");
    break;
  case 5:
    system("clear");
    cout << "The puzzle REGEX_CHALLENGE is not yet completed" << endl;
    sleep(3);
    // system("python3 level5/regex_challenge.py");
    break;
  default: // Optional
    cout << "No puzzle found";
  }

}

template <typename Iterator, typename Random>
Iterator lvlMan::select_randomly(Iterator start, Iterator end, Random &g) {
  std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
  std::advance(start, dis(g));
  return start;
}

template <typename Iterator>
Iterator lvlMan::select_randomly(Iterator start, Iterator end) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  return select_randomly(start, end, gen);
}
