all: item.o Pilha.o rpn.o main.o
	gcc item.o Pilha.o rpn.o main.o -o main -std=c99 -Wall -lm

item.o: 
	gcc -c ./item.c -o item.o	
	
Pilha.o: 
	gcc -c ./Pilha.c -o Pilha.o

rpn.o: rpn.c
	gcc -c ./rpn.c -o rpn.o
	 
main.o: main.c
	gcc -c ./main.c -o main.o

run:
	./main

clean:
	rm *.o rpn	