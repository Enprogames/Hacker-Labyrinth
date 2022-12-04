#!/usr/bin/bash

# Main Script Caller

# This is how the game is started for the first time

#Ensure Init.sh is executable
if ! [ -x init_bash/Init.sh ]; then
    chmod u+x init_bash/Init.sh
fi

# call to the Initialization Script
. init_bash/Init.sh

# # call to the Main Menu
. start_menu/mainMenu.sh 
