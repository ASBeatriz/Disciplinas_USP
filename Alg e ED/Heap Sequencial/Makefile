all: item.o heap_seq.o main.o
	gcc item.o heap_seq.o main.o -o main -std=c99 -Wall
	rm *.o

item.o:
	gcc -c item.c -o item.o

heap_seq.o:
	gcc -c heap_seq.c -o heap_seq.o

main.o:
	gcc -c main.c -o main.o

run:
	./main 

clean:
	rm main *.o