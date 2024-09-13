all: item.o Pilha.o main.o
	gcc item.o Pilha.o main.o -Wall -std=c99 -o main

item.o: 
	gcc -c item.c

Pilha.o:
	gcc -c Pilha.c

main.o:
	gcc -c main.c

run:
	./main

clean:
	rm *.o main