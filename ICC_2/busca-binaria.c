#include<stdio.h>

void imprimeVetor(int vec[], int tam){
    printf("Vetor: ");
    for(int i=0; i<tam; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int buscaBin(int vec[], int x, int esq, int dir){
    if(esq > dir) return -1;
    int meio = (esq+dir/2);

    if(vec[meio] < x)
        return buscaBin(vec, x, esq+1, dir);

    else if(vec[meio] > x)
        return buscaBin(vec, x, esq, dir-1);

    else
        return meio;
}

int main(){
    int vec[] = {2, 4, 5, 7, 8, 10, 12};
    int tam = (sizeof(vec)/sizeof(int)), x;

    imprimeVetor(vec, tam);
    printf("Procure um elemento: ");
    scanf("%d", &x);

    int pos = buscaBin(vec, x, 0, tam-1);
    printf("Posição de %d: %d\n", x, pos);
}