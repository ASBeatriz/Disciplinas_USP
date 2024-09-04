all: item.o pilha_enc.o main.o 
	gcc item.o pilha_enc.o main.o -o main -std=c99 -Wall -lm

item.o: 
	gcc -c ./item.c -o item.o	
	
pilha_enc.o: 
	gcc -c ./pilha_enc.c -o pilha_enc.o

main.o: main.c
	gcc -c ./main.c -o main.o
	 
run:
	./main

clean:
	rm *.o main