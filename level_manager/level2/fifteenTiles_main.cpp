#include <iostream>
#include <stdlib.h>
#include "fifteenTiles_header.h"

using namespace std;

int main()

{
    char movement;
    int difficulty = 1;
    bool gameFinished = false;

    FifteenTiles Game(difficulty);

    cout << "\nYou find yourself in a room with a large 4-by-4 grid containing 15 tiles labeled 1-15 in random order and one empty space mounted to a wall. On the opposite facing wall are mounted spikes. You hear a voice on the loudspeaker…" << endl;
    cout << "\n “You have 5 minutes to arrange the 15 tiles from low to high, begin”" << endl;

    do
    {
        Game.printMenu();
        Game.printBoard();

        cin >> movement;
        Game.move(movement);

        gameFinished = Game.complete();

        system("clear");

    } while(!gameFinished);

    system("clear");
    Game.printBoard();
    cout << "Congratulation Player! you have completed this challenge." << endl;

    return 0;
}