#!/usr/bin/bash

#Ensure Init.sh is executable
if ! [ -x init_bash/Init.sh ]; then
    chmod u+x init_bash/Init.sh
fi


# call to the Initialization Script
. init_bash/Init.sh

#Reset the text in notePad
" " > level_manager/notePad.txt
echo "                    HACKER'S LABYRINTH NOTEPAD " >> level_manager/notePad.txt
echo "" >> level_manager/notePad.txt
echo "This notepad uses the same commands as VIM. Use ESC + i to insert, ESC + wq to write and quit."

# call to the Main Menu
. start_menu/mainMenu.sh 
