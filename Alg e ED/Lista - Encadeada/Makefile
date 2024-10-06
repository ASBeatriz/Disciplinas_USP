all: item.o Lista_enc.o main.o
	gcc item.o Lista_enc.o main.o -o main -std=c99 -Wall

item.o:
	gcc -c item.c

Lista_enc.o:
	gcc -c Lista_enc.c

main.o:
	gcc -c main.c

run:
	./main

clean:
	rm *.o main