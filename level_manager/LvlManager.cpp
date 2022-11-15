#include "LvlManager.h"    
#include <iostream>
#include <vector>
#include  <random>
#include  <iterator>
#include <algorithm>
using namespace std;

int main(){
    lvlMan G;
    //std::vector<int> G.Puzzle = {1, 2, 3, 4, 5};
    int rando = *random_r(G.Puzzle.begin(), G.Puzzle.end());
    cout << "The random number is " << rando;
    
    //call to the random level
    G.puzzleCall(rando);

    
    std::vector<int>::iterator it = std::find(G.Puzzle.begin(), G.Puzzle.end(), rando);
    G.Puzzle.erase(it);



    //possibly a way to access local shell variables !!
    //ip rule add from $(InsertLocalVar) lookup ... 
    return 0;
}