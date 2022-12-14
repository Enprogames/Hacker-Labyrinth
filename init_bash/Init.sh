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


#reset the window size to full size
printf '\e[8;60;160t'



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
