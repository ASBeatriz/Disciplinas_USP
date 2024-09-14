all: item.o Fila_en.o main.o
	gcc item.o Fila_en.o main.o -o main -std=c99 -Wall

item.o:
	gcc -c item.c

Fila_en.o:
	gcc -c Fila_en.c

main.o:
	gcc -c main.c

run:
	./main

clean:
	rm *.o main