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

# Kill level manager

LvlManPID=$(pgrep LvlManagerx)
kill $LvlManPID
exit
