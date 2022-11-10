#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include "path_choice_header.h"

using namespace std;

PowerUps::PowerUps()
{
    instantFinalLevel.rarity = 1;
    instantFinalLevel.prompt = "Blank";
    instantFinalLevel.key = 1;

    skipNextLevel.rarity = 2;
    skipNextLevel.prompt = "The door you selected has a small coupon shaped paper on the food behind it. A voice begins to play on the loudspeaker...\n'Congratulations player! You have found 1 of the rarest items I have hidden, you may skip the next level and still receive the clue. Your life is spared... for now.'";
    skipNextLevel.key = 2;

    plusOneMinutePermanent.rarity = 3;
    plusOneMinutePermanent.prompt = "You hear a voice on the overhead speaker...\n\n 'Congratulations on making it past that puzzle player. No other victim finished that puzzle in quite the same way as you. Guess what else? By selecting the correct door, you have been rewarded with an extra minute to complete each preceding level. You’ll need it!'";
    plusOneMinutePermanent.key = 3; 

    minusOneMinutePermanent.rarity = 3;
    minusOneMinutePermanent.prompt = "You hear a voice on the overhead speaker...\n\n 'Congratulations on making it past that puzzle player. Unfortunately I have some bad news for you, you have selected the wrong door. 1 minute will be taken off your time to complete each preceding level";
    minusOneMinutePermanent.key = 4; 

    plusOneMinuteNextGame.rarity = 5;
    plusOneMinuteNextGame.prompt = "The door you selected has a small note on the ground behind it. The note reads\n\n'Greetings player. Through sheer dumb luck, you have been given a time increase of 1 minute for the next puzzle'";
    plusOneMinuteNextGame.key = 5;

    minusOneMinuteNextGame.rarity = 5;
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
{
    int powerUpChance;

    time_t t; // Get current time from system
    srand((unsigned) time(&t)); // Generate seed of random from current system time 

    powerUpChance = rand () % 10;

    if (powerUpChance <= skipNextLevel.rarity)
    {
        return skipNextLevel.key;
    }
    else if (powerUpChance <= plusOneMinutePermanent.rarity)
    {
        srand((unsigned) time(&t));

        if (rand () % 10 <= 5)
        {
            return plusOneMinutePermanent.key;
        }

        return minusOneMinutePermanent.key;
    }
    else if (powerUpChance <= plusOneMinuteNextGame.rarity)
    {
        srand((unsigned) time(&t));
        if (rand () % 10 <= 5)
        {
            return plusOneMinuteNextGame.key;
        }

        return minusOneMinuteNextGame.key;
    }
    else
    {
        if (rand () % 100 < 5)
        {
            return instantFinalLevel.key;
        }
        return 0;
    }

}