all: item.o arvore_bin.o main.o
	gcc item.o arvore_bin.o main.o -o main -std=c99 -Wall

item.o:
	gcc -c item.c

arvore_bin.o:
	gcc -c arvore_bin.c

main.o:
	gcc -c main.c

run:
	./main

clean:
	rm *.o main