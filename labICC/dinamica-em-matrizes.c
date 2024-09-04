#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int **aloca_matriz(int n){
    int **p = (int **)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++){
        p[i] = (int *)malloc(n*sizeof(int));
    }
    return p;
}


int main(){
    int num;
    scanf("%d", &num);
    int r = sqrt(num);

    int **p = aloca_matriz(r);

    for(int i=0; i<r; i++){
        for(int j=0; j<r; j++){
            scanf("%d",&p[i][j]);
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<r; j++){
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }
}