test: main.o
	gcc main.o -o test
main.o: main.c
	gcc $(DEBUG) -c main.c

debug: DEBUG = -DDEBUG -g
debug: test

clean:
	rm *.o test