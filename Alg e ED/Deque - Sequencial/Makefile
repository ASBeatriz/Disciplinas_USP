all: item.o Deque.o main.o
	gcc item.o Deque.o main.o -o main -std=c99 -Wall

item.o:
	gcc -c item.c

Deque.o:
	gcc -c Deque.c

main.o:
	gcc -c main.c

run:
	./main

clean:
	rm *.o main