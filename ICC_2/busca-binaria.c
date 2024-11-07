#include<stdio.h>

void imprimeVetor(int vec[], int tam){
    printf("Vetor: ");
    for(int i=0; i<tam; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int buscaBin_it(int vetor[],int tam, int x){
    int meio, ini = 0, fim = tam-1;

    while(ini <= fim){
        meio = (ini+fim)/2;

        if(vetor[meio] < x){
            ini = meio + 1;
        }
        else if(vetor[meio] > x){
            fim = meio - 1;
        }
        else return meio;
    }
    return -1; //caso de não achar
}

int buscaBin_rec(int vec[], int x, int esq, int dir){
    if(esq > dir) return -1;
    int meio = (esq+dir/2);

    if(vec[meio] < x)
        return buscaBin_rec(vec, x, esq+1, dir);

    else if(vec[meio] > x)
        return buscaBin_rec(vec, x, esq, dir-1);

    else
        return meio;
}

int main(){
    int vec[] = {2, 4, 5, 7, 8, 10, 12};
    int tam = (sizeof(vec)/sizeof(int)), x;

    imprimeVetor(vec, tam);
    printf("Procure um elemento: ");
    scanf("%d", &x);

    int pos = buscaBin_rec(vec, x, 0, tam-1);
    // int pos = buscaBin_it(vec, tam, x);

    printf("Posição de %d: %d\n", x, pos);
}