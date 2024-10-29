#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int vec[], int tam){
    printf("Vetor: ");
    for(int i=0; i<tam; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
}

void bubble_sort(int *vec, int tam){
    // a cada iteração, o maior número é colocado no seu devido lugar
    for(int j=tam-1; j>=1; j--){    // j indica a posição que vai ser "acertada"
        int troca = 0;
        for(int i=0; i<j; i++){     // i só vai até j porque as posições seguintes já foram acertadas
            if(vec[i] > vec[i+1]){
                int aux = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = aux;
                troca = 1;
            }
        }
        if(troca == 0) break; // se não houver nenhuma troca, pode encerrar
    }
}

// implementação recursiva: troca a versão iterativa da posição a ser acertada (j) pela recursiva
void bubble_sort_rec(int *vec, int tam){
    if (tam > 1){
        int trocas = 0;
        for(int i=0; i<tam-1; i++){     // i só vai até j porque as posições seguintes já foram acertadas
            if(vec[i] > vec[i+1]){
                int aux = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = aux;
                trocas = 1;
            }
        }
        if(!trocas) return;
        bubble_sort_rec(vec, tam-1);
    }
}

int main(){
    int tam, *vec;
    printf("Digite a quantidade de elementos: ");
    scanf("%d", &tam);
    vec = (int *)malloc(tam*sizeof(int));
    
    printf("Digite os elementos: ");
    for(int i=0; i<tam; i++){
        scanf("%d", &vec[i]);
    }

    bubble_sort(vec, tam);
    bubble_sort_rec(vec, tam);

    imprimeVetor(vec, tam);
}