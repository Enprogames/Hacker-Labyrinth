// FIFTEEN TILES FUNCTIONS
// By Jasper Charlinski

// The 15 puzzle (also called Gem Puzzle, Boss Puzzle, Game of Fifteen, Mystic Square and many others) 
//  is a sliding puzzle having 15 square tiles numbered 1–15 in a frame that is 4 tiles high and 4 tiles wide, 
//  leaving one unoccupied tile position. Tiles in the same row or column of the open position can be moved by 
//  sliding them horizontally or vertically, respectively. The goal of the puzzle is to place the tiles in numerical order. 

#include <string>
#include <iostream>
#include <cctype>
#include <termios.h>
#include <unistd.h>
#include "fifteenTiles_header.h"

using namespace std;

FifteenTiles::FifteenTiles(int difficulty)
{
    disableBufferedInput();

    switch (difficulty) {
    case 1:
        randomizeValue = 1000;
        break;
    case 2:
        randomizeValue = 10000;
        break;
    case 3:
        randomizeValue = 100000;
        break;
    
    default:
        randomizeValue = 1000;
    }

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            fifteenTilesBoard[row][col] = initialBoard[row][col];
        }
    }

    findSpace(); // Locate row and col of the space character in fifteenTilesBoard


    randomizeBoard(); // Randomize the contents of fifteenTilesBoard


    while (!solvable()) // Calculate if the puzzle is solvable

    {
        randomizeBoard(); // If puzzle is not solvable, re-organize fifteenTilesBoard
    }
}

FifteenTiles::~FifteenTiles()
{
    enableBufferedInput();
}

// Private -----------------------------------------------------------------------------------------------------

void FifteenTiles::findSpace()
{
    for (int row = 0; row < size; ++row) {
		for (int col = 0; col < size; ++col) {

			if (fifteenTilesBoard[row][col] == ' ')
            {
				space_row = row;
				space_col = col;
			}
		}
	}
}

void FifteenTiles::randomizeBoard()
// This function randomizes the contents of the fifteenTileBoard 2d array.
    // It uses the randomizeValue set in the constructor to determine how scattered the board will be.
   // The randomize value is determined by the game difficulty.
{
    for (int i = 0; i < randomizeValue; ++i) 
    {
		const int nextMove = (rand() % 4); // Get a random value in the range of 0 - 4
		switch (nextMove) { // Use the random value to make a random move 
			case 0:
				{
					Move('w');
					break;
				}
			case 1:
				{
					Move('a');
					break;
				}
			case 2:
				{
					Move('s');
					break;
				}
			case 3:
				{
					Move('d');
					break;
				}
		}
	}
}

void FifteenTiles::Move(char movement)
// This function moves the characters in fifteenTileBoard
    // It takes in a character movement that decides what character will be moved in fifteenTileBoard. 
{
    int move_row = space_row; // Variable that stores the row the the to-be-moved character
    int move_col = space_col; // Variable that stores the col the the to-be-moved character

    movement = toupper(movement);
    switch (movement) { // Based on the given movement
		case 'W':
			{
				move_row++; // Move the tile on the above row of the space
				break;
			}
		case 'S':
			{
				move_row--; // Move the tile on the below row of the space
				break;
			}
		case 'A':
			{
				move_col++; // Move the tile on the right col of the space
				break;
			}
		case 'D':
			{
				move_col--; // Move the tile on the left col of the space
				break;
			}
		case 'M':
			{
                system("./level_manager/inGameMenu.sh");
				return;
			}
        default:
                break;
	}

	if (move_row >= 0 && move_row < size && move_col >= 0 && move_col < size) // Make sure that the tile is moved inside the bound of fifteenTilesBoard

    {
        
        swap(&fifteenTilesBoard[space_row][space_col], &fifteenTilesBoard[move_row][move_col]); // Swap the tile and the space
	}

    findSpace(); // Locate row and col of the space character in fifteenTilesBoard
}

void FifteenTiles::swap(char *a, char *b)
// Typical C++ swap function
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

bool FifteenTiles::checkIfComplete()
// This function compares the fifteenTileBoard to the initialBoard
    // Returns true if fifteenTileBoard are equal initialBoard
    // Returns false otherwise
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if (fifteenTilesBoard[row][col] != initialBoard[row][col])
            {
                return false;
            }
        }
    }

    return true;
}

bool FifteenTiles::solvable()
// This function checks if the randomized puzzle board is solvable
{
    
    char inversionArr[16]; // 1d Array that holds the contents of fifteenTilesBoard
    int i = 0; // Counter for inversionArr index

    int fromBottom; // Variable that holds the distance the space is from the bottom

    for (int row = 0; row < size; row++) // Put the contents of fifteenTilesBoard into inversionArr 
    {

        for (int col = 0; col < size; col++)
        {
            inversionArr[i] = fifteenTilesBoard[row][col];
            i++;
        }
    }

    for (int i = 0; i < size * size - 1; i++) // For each element in the inversionArr
    {
        for (int j = i + 1; j < size * size; j++)
        {
            if (int(inversionArr[i]) > int(inversionArr[j])) // check if each precising index is grater than the current index
            {
                inversionCount++; // If so, increment inversionCount
            }
        }
    }

    fromBottom = size - space_row - 1;

    if (inversionCount % 2 == 0 && (fromBottom == 1 || fromBottom == 3)) // If the inversion count is even and the distance the space is from the bottom is odd
    {
        return true; // Puzzle is solvable
    }
    else if (inversionCount % 2 != 0 && (fromBottom == 2 || fromBottom == 4)) // If the inversion count is odd and the distance the space is from the bottom is even
    {
        return true; // Puzzle is solvable

    }
    else // For all other cases
    {
        return false; // Puzzle is not solvable
    }

}

// Public -----------------------------------------------------------------------------------------------------

void FifteenTiles::move(char m)
// Public caller function for Move
{
    Move(m);
}

bool FifteenTiles::complete()
// Public caller function for checkIfComplete
{
    return checkIfComplete();
}

void FifteenTiles::printBoard()
// This function prints the contents of fifteenTilesBoard
{

    for (int row = 0; row < size; row++)
    {
        if (row == 0)
        {                   
            cout << endl << "----------------" << endl;
        }
        for (int col = 0; col < size; col++)
        {
            if (col == 0)
            {
                cout << "| ";
            }

            cout << " " << fifteenTilesBoard[row][col] << " ";

            if (col == 3)
            {
                cout << " |";
                cout << endl;
            }
        }
        if (row == 3)
        {
            cout << "----------------" << endl;
        }
    }
}

void FifteenTiles::printMenu()
// This function prints the control menu for the game
{
    cout << endl << "w = Up, s = Down, a = Left, d = Right" << endl;
}

// Idea from: https://cplusplus.com/forum/general/29137/

void disableBufferedInput() 
// disables buffered input allowing program to get input without user having to hit enter
{
    struct termios t;
    tcgetattr(STDIN_FILENO, &t); //get the current terminal I/O structure
    t.c_lflag &= ~ICANON; //Manipulate the flag bits to do what you want it to do
    tcsetattr(STDIN_FILENO, TCSANOW, &t); //Apply the new settings
}

void enableBufferedInput()
// enables buffered input so user can see what they are typing
{
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON; 
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}