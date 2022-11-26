Flag=-Wall -Wextra
CC=g++


level2=level2/puzzle2.o level2/puzzle2functions.o level2/puzzle2x
pathChoice=path_choice/path_choice_main.o path_choice/path_choice_functions.o path_choice/pathChoicex

all: LvlManagerx level2/puzzle2x level4/puzzle4x path_choice/pathChoicex level3/puzzle3x

LvlManagerx: LvlManager.o LvlFunctions.o
	${CC} LvlManager.o LvlFunctions.o -o $@

LvlManager.o: LvlManager.cpp LvlManager.h
	${CC} ${Flag} -c $< -o $@

LvlFunctions.o: LvlFunctions.cpp LvlManager.h
	${CC} ${Flag} -c $< -o $@

#level 2 compilation

level2/puzzle2x: level2/puzzle2.o level2/puzzle2functions.o
	${CC} level2/puzzle2.o level2/puzzle2functions.o -o $@


level2/puzzle2.o: level2/fifteenTiles_main.cpp level2/fifteenTiles_header.h
	${CC} ${Flag} -c $< -o $@

level2/puzzle2functions.o: level2/fifteenTiles_functions.cpp level2/fifteenTiles_header.h
	${CC} ${Flag} -c $< -o $@

level3/puzzle3x: level3/puzzle3.o
	${CC} level3/puzzle3.o -o $@

level3/puzzle3.o: level3/decrypt_keeper.cpp level3/decrypt_keeper.h
	${CC} ${Flag} -c $< -o $@


#level 4 compilation

level4/puzzle4x: level4/CipherEscape.cpp level4/CipherEscape.h
	${CC} ${Flag} -c $< -o $@

#path choice compilation

path_choice/pathChoicex: path_choice/path_choice_main.o path_choice/path_choice_functions.o
	${CC} path_choice/path_choice_main.o path_choice/path_choice_functions.o -o $@

path_choice/path_choice_main.o: path_choice/path_choice_main.cpp path_choice/path_choice_header.h
	${CC} ${Flag} -c $< -o $@

path_choice/path_choice_functions.o: path_choice/path_choice_functions.cpp path_choice/path_choice_header.h
	${CC} ${Flag} -c $< -o $@

.PHONY: clean
clean:
	-rm -rf ${level2} ${pathChoice}


