all: item.o Fila.o main.o
	gcc item.o Fila.o main.o -o main -std=c99 -Wall

item.o:
	gcc -c item.c

Fila.o:
	gcc -c Fila.c

main.o:
	gcc -c main.c

run:
	./main

clean:
	rm *.o main