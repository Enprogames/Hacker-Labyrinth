#!/usr/bin/bash

# Main Menu GUI for Hackers Labyrinth

path="start_menu/"
clear
cat ${path}/Menu

echo -n "                              >>USER ENTER OPTION HERE:  "
while true; do
	
	read Option

	case $Option in

		S | s)
			echo "Starting Game"
			#Call to the main Game script
			./level_manager/LvlManagerx
			sleep 2
			# Goes back to start menu after game is finished
			./start_menu/mainMenu.sh
    		;;

  		D | d)
			echo -n "Easy: 1  Medium: 2  Hard : 3             Set the difficulty setting:"	  
    		read Set
    		if [[ $Set -eq 1 ]]
    		then
        		diff=$Set
			echo -n "Difficulty is set to Easy"
			sleep 2s
			clear
			cat ${path}/Menu
			echo -n "                              >>USER ENTER OPTION HERE:  "
    		elif [[ $Set -eq 2 ]] 
    		then
        		diff=$Set
        		echo -n "Difficulty is set to Medium"
        		sleep 2s
        		clear
        		cat ${path}/Menu
			echo -n "                              >>USER ENTER OPTION HERE:  "
    		elif [[ $Set -eq 3 ]] 
    		then
        		diff=$Set
        		echo -n "Difficulty is set to Hard"
        		sleep 2s
        		clear
        		cat ${path}/Menu
			echo -n "                              >>USER ENTER OPTION HERE:  "
    		else
	    		echo "Wrong input, Try again"
			clear
			cat ${path}/Menu
			echo -n "                              >>USER ENTER OPTION HERE:  "
    		fi
    		;;

  		Q | q)
    		echo "Quitting Program"
    		sleep 1s
		exit
    		;;

  		*)
    		echo "Wrong input"
		sleep 1s
		clear
		cat ${path}/Menu
		echo -n "                              >>USER ENTER OPTION HERE:  "
    		;;
	esac
done
