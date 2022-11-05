#include <iostream>
#include <stdlib.h>
#include "header_15Tiles.h"

using namespace std;

int main()

{
    char movement;
    int difficulty = 1;
    int inversionNum = 0;
    bool gameFinished = false;

    FifteenTiles Game(difficulty);

    do
    {
        system("clear");
        Game.printMenu();
        Game.printBoard();

        cin >> movement;
        Game.move(movement);

        gameFinished = Game.complete();

    } while(!gameFinished);

    system("clear");
    Game.printBoard();
    cout << "Congratulation Player! you have completed this challenge." << endl;

    return 0;
}