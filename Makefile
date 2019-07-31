test: main.o non_blocking_stdin.o
	gcc main.o non_blocking_stdin.o -o test
main.o: main.c
	gcc $(DEBUG) -c main.c
non_blocking_stdin.o: non_blocking_stdin.c
	gcc $(DEBUG) -c non_blocking_stdin.c


debug: DEBUG = -DDEBUG -g
debug: test

clean:
	rm *.o test