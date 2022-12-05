#!/usr/bin/bash

# Sebastien Van Den Bremt
# Jasper Charlinski

# This program sets up the initial environment for the game to run by
#   changing the terminal window size 
#   changing terminal text color
#   compiling necessary files
#   setting executable permissions for user on necessary executables
#	resets notepad file and final level exit code file

# MUST BE RUN FROM HACKER-LABYRINTH DIR NOT init_bash


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

# set local variables

declare time=4.00
userID=$(whoami)
declare -i diff=2
declare -i powerUp
declare -i currLvl=0
declare -i maxLvl=3

# compile files and set permmissions

# touch all files in level manager subtree
# add -print to show files being touched
find level_manager -exec touch {} \;

# compile files
(cd level_manager && make)


# set permissions for game manager scripts

if ! [ -x start_menu/mainMenu.sh ]; then
	chmod u+x start_menu/mainMenu.sh
fi

if ! [ -x level_manager/inGameMenu.sh ]; then
	chmod u+x level_manager/inGameMenu.sh
fi

if ! [ -x level_manager/startEndLvl.sh ]; then
	chmod u+x level_manager/startEndLvl.sh
fi

if ! [ -x level_manager/inGameMenu.sh ]; then
	chmod u+x level_manager/inGameMenu.sh
fi

if ! [ -x level_manager/game_over/game_over.sh ]; then
	chmod u+x level_manager/game_over/game_over.sh
fi

if ! [ -x level_manager/final_level/code_entry.sh ]; then
	chmod u+x level_manager/final_level/code_entry.sh 
fi

# set permissions for level scripts

if ! [ -x level_manager/LvlManagerx ]; then
	chmod u+x level_manager/LvlManagerx
fi

if ! [ -x level_manager/level1/rising_acid.py ]; then
	chmod u+x level_manager/level1/rising_acid.py
fi

if ! [ -x level_manager/level2/puzzle2x ]; then
	chmod u+x level_manager/level2/puzzle2x
fi

if ! [ -x level_manager/level3/puzzle3x ]; then
	chmod u+x level_manager/level3/puzzle3x
fi

if ! [ -x level_manager/level4/puzzle4x ]; then
	chmod u+x level_manager/level4/puzzle4x
fi

if ! [ -x level_manager/level5/regex_challenge.py ]; then
	chmod u+x level_manager/level5/regex_challenge.py
fi

#Reset the text in notePad and exit code for final level

truncate -s 0 level_manager/notePad.txt # empty file by setting size in bytes to 0
truncate -s 0 level_manager/final_code.txt # empty file by setting size in bytes to 0

echo -e "---HACKER'S LABYRINTH NOTEPAD----\n\n" >> level_manager/notePad.txt
# echo "This notepad uses the same commands as VIM. Use ESC + i to insert, ESC + wq to write and quit."
