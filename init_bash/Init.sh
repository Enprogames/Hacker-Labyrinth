#!/usr/bin/bash


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

#compile files and set permmissions
# clear code file from previous sessions

# touch all files in level manager subtree
# add -print to show files being touched
find ../level_manager -exec touch {} \;

# compile files
(cd ../level_manager && make)


#add permissions to scripts
if ! [ -x ../start_menu/mainMenu.sh ]; then
	chmod u+x ../start_menu/mainMenu.sh
fi
if ! [ -x ../level_manager/inGameMenu.sh ]; then
	chmod u+x ../level_manager/inGameMenu.sh
fi
if ! [ -x ../level_manager/startEndLvl.sh ]; then
	chmod u+x ../level_manager/startEndLvl.sh
fi
if ! [ -x ../level_manager/inGameMenu.sh ]; then
	chmod u+x ../level_manager/inGameMenu.sh
fi


#set permissions 

if ! [ -x ../level_manager/LvlManagerx ]; then
	chmod u+x ../level_manager/LvlManagerx
fi

if ! [ -x ../level_manager/level1/rising_acid.py ]; then
	chmod u+x ../level_manager/level1/rising_acid.py
fi

if ! [ -x ../level_manager/level2/puzzle2x ]; then
	chmod u+x ../level_manager/level2/puzzle2x
fi

if ! [ -x ../level_manager/level3/puzzle3x ]; then
	chmod u+x ../level_manager/level3/puzzle3x
fi

if ! [ -x ../level_manager/level4/puzzle4x ]; then
	chmod u+x ../level_manager/level4/puzzle4x
fi

if ! [ -x ../level_manager/level5/regex_challenge.py ]; then
	chmod u+x ../level_manager/level5/regex_challenge.py
fi

if ! [ -x ../level_manager/game_over/game_over.sh ]; then
	chmod u+x ../level_manager/game_over/game_over.sh
fi
