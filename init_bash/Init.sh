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

<<<<<<< HEAD
#compile files and set permmissions
# clear code file from previous sessions
=======
>>>>>>> 217f36ff436351d52a69484efb6dacf1971453ce

# touch all files in level manager subtree
# add -print to show files being touched
find ../level_manager -exec touch {} \;

# compile files
(cd ../level_manager && make)

<<<<<<< HEAD
chmod u+x ../level_manager/LvlManagerx
chmod u+x ../level_manager/level1/rising_acid.py
chmod u+x ../level_manager/level2/puzzle2x
chmod u+x ../level_manager/level3/puzzle3x
chmod u+x ../level_manager/level4/puzzle4x
chmod u+x ../level_manager/level5/regex_challenge.py

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

#Reset the text in notePad
> ../level_manager/notePad.txt
echo "                    HACKER'S LABYRINTH NOTEPAD " >> ../level_manager/notePad.txt
echo "" >> ../level_manager/notePad.txt
echo "This notepad uses the same commands as VIM. Use ESC + i to insert, ESC + wq to write and quit."
=======
# set premissions

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
>>>>>>> 217f36ff436351d52a69484efb6dacf1971453ce
