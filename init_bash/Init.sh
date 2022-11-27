#!/usr/bin/bash

#This block is to resize the window to desired size
#wmctrl must be installed

#wid=(window id)
#wh=(size of height)
#ww=(size of width)
#wmctrl -i -r $wid -e  0,0,0,$ww,$wh

#To set the color and maybe size of the terminal text
#https://unix.stackexchange.com/questions/64268/is-there-a-way-to-temporarily-change-the-terminal-colour

#reset the window size to full size
printf '\e[8;60;160t'

#reset the color of text
Print () {

	str=$1
	printf "\033[92m${str}\033[0m"
	#local resetColor='\033[0m'
	#printf "{\033[102m}%s${resetColor}\n" "${str}"
}

Print


#set local variables

declare time=4.00
userID=$(whoami)
declare -i diff=2
declare -i powerUp
declare -i currLvl=0
declare -i maxLvl=3

#compile files and set premmissions

touch ../level_manager/path_choice/path_choice_main.cpp
touch ../level_manager/path_choice/path_choice_functions.cpp
touch ../level_manager/path_choice/path_choice_functions.cpp
touch ../level_manager/level2/fifteenTiles_main.cpp
touch ../level_manager/level2/fifteenTiles_functions.cpp
touch ../level_manager/level3/decrypt_keeper.cpp
touch ../level_manager/level3/cipher_escape.cpp

(cd ../level_manager && make)

chmod u+x ../level_manager/LvlManagerx
chmod u+x ../level_manager/level1/rising_acid.py
chmod u+x ../level_manager/level2/puzzle2x
chmod u+x ../level_manager/level3/puzzle3x
chmod u+x ../level_manager/level4/puzzle4x
chmod u+x ../level_manager/level5/regex_challenge.py