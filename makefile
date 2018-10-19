all: sieve.o main.o
	clang -o tests sieve.o main.o

sieve.o: sieve.c sieve.h
	clang -c sieve.c

main.o: main.c sieve.h
	clang -c main.c

run:
	./tests

clean:
	rm *.o