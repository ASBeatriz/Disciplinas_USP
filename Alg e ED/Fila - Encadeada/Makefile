all: item.o Fila_enc.o main.o
	gcc item.o Fila_enc.o main.o -o main -std=c99 -Wall

item.o:
	gcc -c item.c

Fila_enc.o:
	gcc -c Fila_enc.c

main.o:
	gcc -c main.c

run:
	./main

clean:
	rm *.o main