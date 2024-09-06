#include <stdio.h>
#include <stdlib.h>

void printVetor(int *v){
    printf("%d\n", v[2]);
    *(v+1) = 50;
}

int main(){
    int *v = malloc(5*sizeof(int));
    v[0] = 2;
    v[1] = 3;
    v[2] = 4;
    
    printVetor(v);
    printf("%d\n", *(v+1));

    int v2[] = {10, 20, 30};
    int *p = v2;
    
    for(int i=0; i<3; i++){
        printf("%d ", *(p+i));
    }
}