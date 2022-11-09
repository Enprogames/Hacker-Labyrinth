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
    skipNextLevel.prompt = "You've recived skip next level";
    skipNextLevel.key = 2;

    plusMinusOneMinutePermanent.rarity = 3;
    plusMinusOneMinutePermanent.prompt = " ";
    plusMinusOneMinutePermanent.key = 3; 

    plusMinusOneMinuteNextGame.rarity = 5;
    plusMinusOneMinuteNextGame.prompt = " ";
    plusMinusOneMinuteNextGame.key = 6;
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

    cout << powerUpChance << endl;

    if (powerUpChance <= skipNextLevel.rarity)
    {
        return skipNextLevel.key;
    }
    else if (powerUpChance <= plusMinusOneMinutePermanent.rarity)
    {
        return plusMinusOneMinutePermanent.key;
    }
    else if ( powerUpChance <= plusMinusOneMinuteNextGame.rarity)
    {
        return plusMinusOneMinuteNextGame.key;
    }
    else
    {
        if (rand () % 100 < 5)
        {
            return instantFinalLevel.key;
        }
    }

}