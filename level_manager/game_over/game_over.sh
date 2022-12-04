#! /bin/bash

# Sebastien Van Den Bremt
# Jasper Charlinski

# This program ends the current game session by
#   displaying game over screen
#   killing all current game processes
#   calling start menu

# dispaly game over screen
clear

cat ./level_manager/game_over/GameOverScreen.txt

sleep 4

# add kill by PID

. start_menu/mainMenu.sh 