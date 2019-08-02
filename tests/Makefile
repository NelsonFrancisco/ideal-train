UNITY_FOLDER = ../Unity
LIBRARY_FOLDER= ../src

tests: non_blocking_stdin.test.o non_blocking_stdin.o unity.o
	gcc non_blocking_stdin.test.o non_blocking_stdin.o unity.o -o tests

non_blocking_stdin.test.o: non_blocking_stdin.test.c
	gcc $(DEBUG) -c -I$(LIBRARY_FOLDER) -I$(UNITY_FOLDER) non_blocking_stdin.test.c

non_blocking_stdin.o: $(LIBRARY_FOLDER)/non_blocking_stdin.c
	gcc $(DEBUG) -c ../src/non_blocking_stdin.c

unity.o: $(UNITY_FOLDER)/unity.c
	gcc $(DEBUG) -c -I$(UNITY_FOLDER) $(UNITY_FOLDER)/unity.c


debug: tests
debug: DEBUG = -DDEBUG -g

clean:
	rm *.o tests