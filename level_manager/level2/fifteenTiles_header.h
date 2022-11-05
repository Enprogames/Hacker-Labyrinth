#pragma once
#include <iostream>

class FifteenTiles {

    private:

        const int size = 4; 
        long int randomizeValue;

        int inversionNum = 0;

        const char initialBoard[4][4] =
        {
            {'1', '2', '3', '4'},
            {'5', '6', '7', '8'},
            {'9', 'A', 'B', 'C'},
            {'D', 'E', 'F', ' '}
        };

        char fifteenTilesBoard[4][4];

        int space_row;
        int space_col;

        void randomizeBoard();
        void findSpace();
        bool checkIfComplete();
        void swap(char *a, char *b);
        void Move(char movement);
        bool solvable();


    public:

    FifteenTiles(int difficulty);
    ~FifteenTiles();
    void printBoard();
    void printMenu();
    void move(char m);
    bool complete();
};
