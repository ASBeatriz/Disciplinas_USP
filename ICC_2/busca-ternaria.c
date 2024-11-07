#include <stdio.h>

void imprimeVetor(int vec[], int tam){
    printf("Vetor: ");
    for(int i=0; i<tam; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// É parecido com a busca binária, só que o vetor é "dividido" em 3 partes em vez de 2
int buscaTer_it(int vetor[],int tam, int x){
    int meio1, meio2, ini = 0, fim = tam-1;

    while(ini <= fim){
        meio1 = ini + (fim-ini)/3;
        meio2 = fim - (fim-ini)/3;

        if(vetor[meio1] == x){
            return meio1;
        }
        if(vetor[meio2] == x){
            return meio2;
        }
        if(vetor[meio1] > x){
            fim = meio1 - 1;
        }
        else if(vetor[meio2] < x){
            ini = meio2 + 1;
        }
        else{
            ini = meio1 + 1;
            fim = meio2 - 1;
        }
    }
    return -1; //caso de não achar
}

// Versão recursiva
int buscaTer_rec(int vetor[],int ini, int fim, int x){
    if (ini > fim) return -1;   // caso de não achar

    int meio1, meio2;
    meio1 = ini + (fim-ini)/3;
    meio2 = fim - (fim-ini)/3;

    if(vetor[meio1] == x){
        return meio1;
    }
    if(vetor[meio2] == x){
        return meio2;
    }
    if(vetor[meio1] > x){
        return buscaTer_rec(vetor, ini, meio1-1, x);
    }
    else if(vetor[meio2] < x){
        return buscaTer_rec(vetor, meio2+1, fim, x);
    }
    else{
        return buscaTer_rec(vetor, meio1+1, meio2-1, x);
    }    
}

int main(){
    int vec[] = {2, 4, 5, 7, 8, 10, 12};
    int tam = (sizeof(vec)/sizeof(int)), x;

    imprimeVetor(vec, tam);
    printf("Procure um elemento: ");
    scanf("%d", &x);

    // int pos = buscaTer_it(vec, tam, x);
    int pos = buscaTer_rec(vec, 0, tam-1, x);
    printf("Posição de %d: %d\n", x, pos);
}