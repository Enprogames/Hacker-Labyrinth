#! /bin/bash

clear

case $1 in
# should get bool retrun value from each level to say weather passed or failed
    #premissions need to be set during the init so the levels can be called

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
    sleep 3
    # call game over
fi

./level_manager/path_choice/pathChoicex




