#pragma once

#include <string>

const int Num_to_ignore = 265;

class PowerUps
{
    private:

    struct powerUp
    {
        double rarity;
        std::string prompt;
        int key;
    };

    powerUp instantFinalLevel; // Power up 1
    powerUp skipNextLevel; // Power up 2
    powerUp plusMinusOneMinutePermanent; // Power up 3
    powerUp plusMinusOneMinuteNextGame; // Power up 4

    int givePowerUp();

    public:

    PowerUps();
    ~PowerUps();

    int getPowerUp();    
};
