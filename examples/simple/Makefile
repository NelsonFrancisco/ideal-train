LIB_FOLDER = ./non_blocking_stdin

test: main.o non_blocking_stdin.o
	gcc main.o non_blocking_stdin.o -o test
main.o: main.c
	gcc $(DEBUG) -c -I$(LIB_FOLDER) main.c
non_blocking_stdin.o: $(LIB_FOLDER)/non_blocking_stdin.c
	gcc $(DEBUG) -c $(LIB_FOLDER)/non_blocking_stdin.c


debug: DEBUG = -DDEBUG -g
debug: test

clean:
	rm *.o test