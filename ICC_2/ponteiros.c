// Como passa vetor por referencia ??? e como utilizar ponteiro pra percorrer vetor ???? (vergonha de ICC I T-T )

#include <stdio.h>
#include <stdlib.h>

void printVetor(int v[]){
    int n = *v;
    printf("%d\n", n);
    *v = 50;
}

void print2(int **v){
    //printf("%d", **v);
}

int main(){
    int *v;
    v[0] = 2;
    v[1] = 3;
    v[2] = 4;

    int *p = v;
    
    printVetor(v);
    printf("%d\n", *(v));

    int *v2 = (int *)malloc(sizeof(int)*5);
    // *v2 = 1;
    // *(v2+1) = 2;
    // *(v2+2) = 3;

    //print2(&v2);
}