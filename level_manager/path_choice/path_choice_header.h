// PATH CHOICE HEADER
// Jasper Charlinski

#pragma once

#include <string>

const int Num_To_Ignore = 265;

class PowerUps
{
    private:

    struct powerUp
    {
        double rarity;
        std::string prompt;
        int key;
    };

    int givePowerUp();

    public:

    PowerUps();
    ~PowerUps();

    int getPowerUp();   

    powerUp instantFinalLevel; // Power up 1
    powerUp skipNextLevel; // Power up 2
    powerUp minusOneMinutePermanent; // Power up 3
    powerUp plusOneMinutePermanent; // Power up 4
    powerUp minusOneMinuteNextGame; // Power up 5
    powerUp plusOneMinuteNextGame; // Power up 6 
};

void disableBufferedInput();
void enableBufferedInput();