Flag=-Wall -Wextra
CC=g++

level2/puzzle2x: level2/puzzle2.o level2/puzzle2functions.o
	${CC} level2/puzzle2.o level2/puzzle2functions.o -o $@


level2/puzzle2.o: level2/fifteenTiles_main.cpp level2/fifteenTiles_header.h
	${CC} ${Flag} -c $< -o $@

level2/puzzle2functions.o: level2/fifteenTiles_functions.cpp level2/fifteenTiles_header.h
	${CC} ${Flag} -c $< -o $@





.PHONY: clean
clean:
	-rm -rf level2/puzzle2.o level2/puzzle2functions.o level2/puzzle2x


