#include "LvlManager.h"    
#include <iostream>
#include <vector>
#include  <random>
#include  <iterator>
#include <algorithm>
using namespace std;

int main(){
    lvlMan Game;
    std::vector<int> Puzzle = {1, 2, 3, 4, 5};
    int rando = *randomize(Puzzle.begin(), Puzzle.end());
    cout << "The random number is " << rando;
    
    //call to the random level
    Game.puzzleCall(rando);

    
    std::vector<int>::iterator it = std::find(Puzzle.begin(), Puzzle.end(), rando);
    Puzzle.erase(it);



    //possibly a way to access local shell variables !!
    //ip rule add from $(InsertLocalVar) lookup ... 
    return 0;
}