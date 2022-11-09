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

    cout << "\nYou are faced with two doors, each leeding to a uniqe path" << endl;

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

    cout << "You recived power up number " << PU.getPowerUp() << endl;
    
    return 0;
}