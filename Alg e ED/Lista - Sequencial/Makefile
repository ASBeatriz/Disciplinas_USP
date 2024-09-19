all: item.o Lista_seq.o main.o
	gcc item.o Lista_seq.o main.o -o main -std=c99 -Wall

item.o:
	gcc -c item.c

Lista_seq.o:
	gcc -c Lista_seq.c

main.o:
	gcc -c main.c

run:
	./main

clean:
	rm *.o main