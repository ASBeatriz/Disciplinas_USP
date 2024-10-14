#include <stdio.h>
#include <stdlib.h>

// função auxiliar para pegar o maior valor de um array
int getMax(int v[], int n){
    int max = 0;
    for(int i=0; i<n; i++){
        if(v[i] > max) max = v[i];
    }
    return max;
}

void countingSort(int v[], int n){
    int max = getMax(v, n);

    int *counter = (int *)calloc(max+1, sizeof(int));   //max + 1 pois se o maior elemento for x, os valores variam de 0 a x
    
    // preenche o vetor counter
    for(int i=0; i<n; i++){
        counter[v[i]]++;
    }

    // faz a soma acumulativa no vetor 
    for(int i=1; i<max+1; i++){
        counter[i] += counter[i-1];
    }
    
    //imprime o vetor counter
    // for(int i=0; i<max+1; i++){
    //     printf("%d ", counter[i]);
    // }
    // printf("\n");
    
    // preenche o vetor ordenado
    int ordenado[n];
    for(int i=n-1; i >= 0; i--){
        //counter[v[i]] retorna a valor da soma acumulada relativa ao elemento v[i]. 
        // Esse valor decrescido de 1 é justamente a posição em que o elemento v[i] tem que ficar no vetor ordenado.
        ordenado[counter[v[i]]- 1] = v[i]; 
        counter[v[i]]--;    // caso haja mais de um elemento v[i], ele será colocado na posição anterior ao primeiro
    }

    // imprime o vetor ordenado
    for(int i=0; i<n; i++){
        printf("%d ", ordenado[i]);
    }
    printf("\n");

    free(counter);
}

int main(){
    int n;
    scanf("%d", &n);
    int v[n];
    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    countingSort(v, n);
}