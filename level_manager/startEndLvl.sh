#! /bin/bash

# Jasper Charlinski

# This program calls a level executable based on the integer it is passed
#   the level to be called is determined by the LvlManager

clear

case $1 in

    1)
        ./level_manager/level1/rising_acid.py;;
    2)
        ./level_manager/level2/puzzle2x;;
    3) 
        ./level_manager/level3/puzzle3x;;
    4)
        ./level_manager/level4/puzzle4x;;
    5)
        ./level_manager/level5/regex_challenge.py;;
esac

if [ $? -eq 0 ]; then
    echo "Level Failed! Game Over"
    sleep 2
    ./level_manager/game_over/game_over.sh
elif [ $? -eq 2 ]; then
    echo "Level Failed! Game Over"
    sleep 2
    ./level_manager/game_over/game_over.sh
else
    ./level_manager/path_choice/pathChoicex
fi




