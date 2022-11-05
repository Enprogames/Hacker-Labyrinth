#!/usr/bin/bash

path="start_menu/"
clear
cat ${path}/Menu

echo -n ">>USER ENTER OPTION HERE:  "
while true; do
	
	read Option

	case $Option in

		S | s)
    			echo "Starting Game"
    			#Call to the main Game script
    		;;

  		D | d)
		echo -n "Easy: 1  Medium: 2  Hard : 3             Set the difficulty setting:"	  
    		read Set
    		if [[ $Set -eq 1 ]]
    		then
        		diff=$Set
			echo -n "Difficulty is set to Easy"
			sleep 3s
			clear
			cat ${path}/Menu
			echo -n ">>USER ENTER OPTION HERE:  "
    		elif [[ $Set -eq 2 ]] 
    		then
        		diff=$Set
        		echo -n "Difficulty is set to Medium"
        		sleep 3s
        		clear
        		cat ${path}/Menu
			echo -n ">>USER ENTER OPTION HERE:  "
    		elif [[ $Set -eq 3 ]] 
    		then
        		diff=$Set
        		echo -n "Difficulty is set to Hard"
        		sleep 3s
        		clear
        		cat ${path}/Menu
			echo -n ">>USER ENTER OPTION HERE:  "
    		else
	    		echo "Wrong input, Try again"
			clear
			cat ${path}/Menu
			echo -n ">>USER ENTER OPTION HERE:  "
    		fi
    		;;

  		H | h)
    		echo  "Help Menu"
    		#Create a Help Menu to print
    		;;

  		Q | q)
    		echo "Quitting Program"
    		sleep 2s
		exit
    		;;

  		*)
    		echo "Wrong input"
		sleep 2s
		clear
		cat ${path}/Menu
		echo -n ">>USER ENTER OPTION HERE:  "
    		;;
	esac
done
