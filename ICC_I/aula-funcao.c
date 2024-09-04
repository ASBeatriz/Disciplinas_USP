#include<stdio.h>

void swap(int *x, int *y){
    int g = *x;
    *x = *y;
    *y = g;
}

void ordenar(int *x, int *y, int *z){
    int g;
    if(*x > *y){
        g = *x;
        *x = *y;
        *y = g;
    }
    if(*y > *z){
        g = *y;
        *y = *z;
        *z = g;
    }
    if(*x > *y){
        g = *x;
        *x = *y;
        *y = g;
    }
}

int main(){
    int a =10,b=5;
    printf("a: %d b: %d\n", a, b);
    swap(&a,&b);
    printf("a: %d b: %d\n", a, b);

    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    ordenar(&A, &B, &C);
    printf("%d %d %d\n", A, B, C);
}