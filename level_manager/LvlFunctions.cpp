#include "LvlManager.h"
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include  <random>
#include  <iterator>
using namespace std;



//float Time;
//int GameOver = 0;
//int numLvl, currLvl;
//std::vector<int> Puzzle = {1, 2, 3, 4, 5};



//lvlMan::lvlMan(){}
//lvlMan::~lvlMan(){}

int lvlMan::pathChoice(){
    int lvlUp = system(". path_choice/pathChoicex");
    return lvlUp;
}

void lvlMan::puzzleCall(int Lvl){
    //system(". Lvl");
}

template<typename Iterator, typename Random>
Iterator lvlMan::select_randomly(Iterator start, Iterator end, Random& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iterator>
Iterator lvlMan::select_randomly(Iterator start, Iterator end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}




