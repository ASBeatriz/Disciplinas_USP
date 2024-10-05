all: item.o Deque_enc.o main.o
	gcc item.o Deque_enc.o main.o -o main -std=c99 -Wall

item.o:
	gcc -c item.c

Deque_enc.o:
	gcc -c Deque_enc.c

main.o:
	gcc -c main.c

run:
	./main

clean:
	rm *.o main