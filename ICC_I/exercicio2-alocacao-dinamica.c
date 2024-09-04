#include <stdio.h>
#include <stdlib.h>

//fazer uma matriz com linhas e colunas dados pelo usuário
int main(){
    int col,lin;
    int **m;
    m = (double **)malloc(lin*sizeof(double *)); //linhas da matriz (vetor de ponteiros)

    for(int i=0; i < lin; i++){
        m[i] = (double *)malloc(col*sizeof(double)); //colunas de cada linha
    }


}