// PATH CHOICE FUNCTIONS
// Jasper Charlinski

// Path Choice provides player with two options, left door and right door.
// Behind each door is the chance for the player to receive a power up that will
// help them in preceding level(s), or the chance to receive a draw back that will make
// the preceding level(s) more difficult.

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include "path_choice_header.h"

using namespace std;

PowerUps::PowerUps()
{
    instantFinalLevel.rarity = 1;
    instantFinalLevel.prompt = "You hear a voice on the overhead speaker...\n\n 'Congratulations player! You have happen to stumble upon the rarest item in the game,\n you have the option of exiting the game right now and I will spare your life.";
    instantFinalLevel.key = 1;

    skipNextLevel.rarity = 10;
    skipNextLevel.prompt = "The door you selected has a small coupon shaped paper on the ground behind it. A voice begins to play on the loudspeaker...\n'Congratulations player! You have found one of the rarest items I have hidden,\n you may skip the next level and still receive the clue. Your life is spared... for now.'";
    skipNextLevel.key = 2;

    plusOneMinutePermanent.rarity = 20;
    plusOneMinutePermanent.prompt = "You hear a voice on the overhead speaker...\n\n 'Congratulations on making it past that puzzle player. No other victim finished that puzzle in quite the same way as you.\n Guess what else? By selecting the correct door, you have been rewarded with an extra minute to complete each preceding level. You’ll need it!'";
    plusOneMinutePermanent.key = 3; 

    minusOneMinutePermanent.rarity = 20;
    minusOneMinutePermanent.prompt = "You hear a voice on the overhead speaker...\n\n 'Congratulations on making it past that puzzle player. Unfortunately I have some bad news for you, you have selected the wrong door.\n 1 minute will be taken off your time to complete each preceding level";
    minusOneMinutePermanent.key = 4; 

    plusOneMinuteNextGame.rarity = 35;
    plusOneMinuteNextGame.prompt = "The door you selected has a small note on the ground behind it. The note reads\n\n'Greetings player. Through sheer dumb luck, you have been given a time increase of 1 minute for the next puzzle'";
    plusOneMinuteNextGame.key = 5;

    minusOneMinuteNextGame.rarity = 35;
    minusOneMinuteNextGame.prompt = "The door you selected has a small note on the ground behind it. The note reads\n\n'Greetings player. Unfortunately you have selected the wrong door, 1 minute will be taken of your time to complete the next level'";
    minusOneMinuteNextGame.key = 6;
}

PowerUps::~PowerUps()
{
}

int PowerUps::getPowerUp()
{
   return givePowerUp();
}

int PowerUps::givePowerUp()
// This function generates a randomized number that is used to determine what, if any, power the user will receive.
    // The function returns the integer key value of the power up, or 0 if no power up.
{
    int powerUpChance; // Variable to hold random number
    int choice;

    time_t t; // Get current time from system
    srand((unsigned) time(&t)); // Generate seed of random from current system time 

    powerUpChance = rand() % 100; // Generate random number from 1 - 100

    if (powerUpChance <= skipNextLevel.rarity)
    {
        return skipNextLevel.key;
    }
    else if (powerUpChance <= plusOneMinutePermanent.rarity) // Plus and minus one minute permanent have the same rarity
    {
        srand((unsigned) time(&t));
        if (rand () % 10 <= 5) // Generate random number between 1 - 10, 50% chance of either power up
        {
            return plusOneMinutePermanent.key;
        }

        return minusOneMinutePermanent.key;
    }
    else if (powerUpChance <= plusOneMinuteNextGame.rarity) // Plus and minus one minute next game have the same rarity
    {
        srand((unsigned) time(&t));
        if (rand () % 10 <= 5) // Generate random number between 1 - 10, 50% chance of either power up
        {
            return plusOneMinuteNextGame.key;
        }

        return minusOneMinuteNextGame.key;
    }
    else if (powerUpChance <= rand() % 10)
    {
        if (rand () % 100 < 5)
        {
            cout << endl << endl << "Enter 1 to exit or enter 2 to stay" << endl;
            cin >> choice;
            if (choice > 2 || choice < 1)
            {
                cout << "'Excuse me... That wan't an option. I am revoking my offer you get no power ups" << endl;
                return 0;
            }
            else if (choice == 1)
            {
                return instantFinalLevel.key;
            }
        }
    }

    return 0;
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