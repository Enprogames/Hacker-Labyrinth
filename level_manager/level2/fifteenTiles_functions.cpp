#include <string>
#include <iostream>
#include "fifteenTiles_header.h"

using namespace std;

FifteenTiles::FifteenTiles(int difficulty)
{
    
    switch (difficulty)
    {
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
        break;
    }

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            fifteenTilesBoard[row][col] = initialBoard[row][col];
        }
    }

    findSpace();

    randomizeBoard();

    while (!solvable())
    {
        randomizeBoard();
    }
}

FifteenTiles::~FifteenTiles()
{

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
{
    for (int i = 0; i < randomizeValue; ++i) {
        
		const int nextMove = (rand() % size);
		switch (nextMove) {
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
{
    int move_row = space_row;
    int move_col = space_col;

    switch (movement) {
		case 'w':
			{
				move_row = space_row + 1;
				break;
			}
		case 's':
			{
				move_row = space_row - 1;
				break;
			}
		case 'a':
			{
				move_col = space_col + 1;
				break;
			}
		case 'd':
			{
				move_col = space_col - 1;
				break;
			}
	}

	if (move_row >= 0 && move_row < size && move_col >= 0 && move_col < size) // Make sure that the square to be moved is in bounds

    {
        
        swap(&fifteenTilesBoard[space_row][space_col], &fifteenTilesBoard[move_row][move_col]);
	}

    findSpace();
}

void FifteenTiles::swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

bool FifteenTiles::checkIfComplete()
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
{
    
    char inversionArr[16];
    int i = 0;
    int fromBottom;

    for (int row = 0; row < size; row++)
    {

        for (int col = 0; col < size; col++)
        {
            inversionArr[i] = fifteenTilesBoard[row][col];
            i++;
        }
    }

    for (int i = 0; i < size * size - 1; i++)
    {
        for (int j = i + 1; j < size * size; j++)
        {
            if (int(inversionArr[i]) > int(inversionArr[j]))
            {
                inversionNum++;
            }
        }
    }


    fromBottom = size - space_row - 1;

    if (inversionNum % 2 == 0 && (fromBottom == 1 || fromBottom == 3))
    {
    }
    else if (inversionNum % 2 != 0 && (fromBottom == 2 || fromBottom == 4))
    {
    }
    else 
    {
        return false;
    }

    return true;

}

// Public -----------------------------------------------------------------------------------------------------

void FifteenTiles::move(char m)
{
    Move(m);
}

bool FifteenTiles::complete()
{
    return checkIfComplete();
}

void FifteenTiles::printBoard()
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
{
    cout << endl << "w = Up, s = Down, a = Left, d = Right" << endl;
}