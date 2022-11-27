#!/usr/bin/bash

path="level_manager/"

#clear screen and display the in game menu
clear
#cat ${path}/inGameMenu
cat ${path}/inGameMenu
#Declare process ID
PID=$$

echo -n "                              >>USER ENTER OPTION HERE:  "
while true; do
	
	read Option

	case $Option in

		N | n)
        #NOTEPAD ACCESS
    		echo "Opening The NotePad"
    	    sleep 1s

            #if using from main.sh
		    vim ${path}/notePad.txt

            #if running locally from level/manager
            #vim notePad.txt
    		;;
  		H | h)
        clear
		echo "                 Select the level you are seeking hints for (Enter 1 -5):" 
        echo "                 1 - Rising Acid "
        echo "                 2 - Fifteen Tiles "
        echo "                 3 - DeCrypt Keeper "
        echo "                 4 - Cipher Escape "
        echo "                 5 - Regex Challenge "
        echo "                 "
    		read Set
    		if [[ $Set -eq 1 ]]
    		then
			echo "Rising Acid:"
            #Insert info on using rising acid here

            echo "Type any one key then press enter to return to Menu"
            read -p Back
            clear
            cat ${path}/inGameMenu
			echo -n "                              >>USER ENTER OPTION HERE:  "
    		elif [[ $Set -eq 2 ]] 
    		then
			echo  "Fifteen Tiles:"
            #Insert info on using Fifteen Tiles here

            echo "Type any one key then press enter to return to inGameMenu"
            read -p Back
            clear
            cat ${path}/inGameMenu
			echo -n "                              >>USER ENTER OPTION HERE:  "
    		elif [[ $Set -eq 3 ]] 
    		then
			echo "DeCrypt Keeper:"
            #Insert info on using DeCrypt Keeper here

            echo -n "Type any one key then press enter to return to inGameMenu"
            read -p Back
            clear
            cat ${path}/inGameMenu
			echo -n "                              >>USER ENTER OPTION HERE:  "
            elif [[ $Set -eq 4 ]] 
    		then
			echo "Cipher Escape:"
            #Insert info on using Cipher Escape here

            echo "Type any one key then press enter to return to inGameMenu"
            read -p Back
            clear
            cat ${path}/inGameMenu
			echo -n "                              >>USER ENTER OPTION HERE:  "
                		elif [[ $Set -eq 5 ]] 
    		then
			echo "Regex Challenge:"
            #Insert info on using Regex Challenge here

            echo "Type any one key then press enter to return to inGameMenu"
            read -p Back
            clear
            cat ${path}/inGameMenu
			echo -n "                              >>USER ENTER OPTION HERE:  "
    		else
	    		echo "Wrong input, returning to inGameMenu"
			clear
			cat ${path}/inGameMenu
			echo -n "                              >>USER ENTER OPTION HERE:  "
    		fi
    		    ;;

  		Q | q)
    		echo  "Quitting Menu"
            sleep 1s
            kill $PID
    		;;

  		E | e)
    		echo "Exiting Program"
    		sleep 1s
		exit
    		;;

  		*)
    		echo "Wrong input"
		sleep 1s
		clear
		cat ${path}/inGameMenu
		echo -n "                              >>USER ENTER OPTION HERE:  "
    		;;
	esac
done