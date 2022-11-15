#include <iostream>
#include <cstdlib>
#include <cctype>
#include "path_choice_header.h"

using namespace std;

int main ()
{
    char choice;

    bool valid;
    PowerUps PU;

    cout << "\nYou are faced with two doors, each leading to a unique path" << endl;
    system("clear");
    system("cat path_choice.txt");

    cout << endl;

    do
    {
        cout << "Enter L to go through the left door, or enter R to go though the right door" << endl;
        cin >> choice;
        choice = toupper(choice);

        switch (choice)
        {
        case 'L':
            cout << "\nThe left door has been chosen..." << endl;
            valid = true;
            break;
        case 'R':
            cout << "\nThe right door has been chosen..." << endl;
            valid =true;
            break;
        
        default:
            cout << "\nError: Invalid choice" << endl;
            cin.clear();
            cin.ignore(Num_to_ignore, '\n');
            valid = false;
            break;
        }
    } while (!valid);

    int powerUp = PU.getPowerUp();

    switch (powerUp)
    {
        case 0:
            cout << "Nothing is behind this door but a dark hallway leading to a dimly lit room..." << endl;
            break;
        case 1:
            cout << endl << PU.instantFinalLevel.prompt << endl;
            break;
        case 2:
            cout << endl << PU.skipNextLevel.prompt << endl;
            break;
        case 3:
            cout << endl << PU.plusOneMinutePermanent.prompt << endl;
            break;
        case 4:
            cout << endl << PU.minusOneMinutePermanent.prompt << endl;
            break;
        case 5:
            cout << endl << PU.plusOneMinuteNextGame.prompt << endl;
            break;
        case 6:
            cout << endl << PU.minusOneMinuteNextGame.prompt << endl;
            break;
    }
    return 0;
}