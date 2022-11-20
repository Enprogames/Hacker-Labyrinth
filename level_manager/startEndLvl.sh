#! /bin/bash

# clear

echo "calling puzzle " $1

case $1 in
# should get bool retrun value from each level to say weather passed or failed
    #premissions need to be set during the init so the levels can be called

    1)
        ./level1/rising_acid.py;;

    2)
        ./level2/puzzle2x;;
    
    3) 
        echo "Puzzle not complete";;

    4)

        ./level4/puzzle4x;;
    5)

        ./level5/regex_challange.py;;

esac

# this will work to get the path choice return, but needs to be stored in a local variable 

# ./path_choice/pathChoicex

# echo "the power up recived was " $?
