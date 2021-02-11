main: bin/main

test: bin/main-test

bin/main: build/main.o build/board.o build/board_print.o
	gcc -Wall -Werror build/main.o build/board.o build/board_print.o -o bin/main

bin/main-test: build/main-test.o build/board.o build/board_print.o
	gcc -Wall -Werror build/main-test.o build/board.o build/board_print.o -o bin/main-test

build/main-test.o: test/main.c
	gcc -std=c99 -I thirdparty -I scr -c test/main.c -o build/main-test.o

build/main.o: src/main.c
	gcc -std=c99 -Wall -Werror -c src/main.c -o build/main.o

build/board.o: src/board.c
	gcc -std=c99 -Wall -Werror -c src/board.c -o build/board.o

build/board_print.o: src/board_print.c
	gcc -std=c99 -Wall -Werror -c src/board_print.c -o build/board_print.o

.PHONY : clean
clean:
	rm -rf build/*.o
