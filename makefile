all: sieve.o main.o
	gcc -o -lm tests sieve.o main.o

sieve.o: sieve.c sieve.h
	gcc -c sieve.c

main.o: main.c sieve.h
	gcc -c main.c

run:
	./tests

clean:
	rm *.o