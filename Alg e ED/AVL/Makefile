all: item.o arvore_avl.o main.o
	gcc item.o arvore_avl.o main.o -o main -std=c99 -Wall
	rm *.o

item.o:
	gcc -c item.c -o item.o

arvore_avl.o:
	gcc -c arvore_avl.c -o arvore_avl.o

main.o:
	gcc -c main.c -o main.o

run:
	./main 

clean:
	rm main