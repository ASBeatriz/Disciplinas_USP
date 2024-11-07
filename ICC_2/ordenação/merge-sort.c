#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(char str[], int vec[], int tam){
    printf("Vetor %s: ", str);
    for(int i=0; i<tam; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// Função para fazer a interação com o usuário. Retorna o vetor lido.
int *interacao(int *tam){
    printf("Digite a quantidade de elementos: ");
    scanf("%d", tam);
    int *vec = (int *)malloc((*tam)*sizeof(int));
    
    printf("Digite os elementos: ");
    for(int i=0; i<*tam; i++){
        scanf("%d", &vec[i]);
    }
    return vec;
}

void merge(int *vec, int l, int r,int tam){
    // printf("posicoes: %d %d\n", l, r);   //debug

    int tamT = r - (l-1);
    int tam1 = (tamT/2);
    int tam2 = tamT-tam1;
    int vL[tam1], vR[tam2];

    // printf("tam1: %d tam2: %d\n", tam1, tam2);   //debug

    // Preenche os vetores auxiliares da esquerda e direita
    for(int i=0; i<tam1; i++){
        vL[i] = vec[l+i];
    }
    for(int j=0; j<tam2; j++){
        vR[j] = vec[l+j+tam1];
    }

    int i=0, j=0, k=l;

    // Reescreve o vetor original de forma ordenada comparando os elementos dos vetores auxiliares
    while(i < tam1 && j < tam2){
        if(vL[i] < vR[j]){
            vec[k++] = vL[i++];
        }
        else{
            vec[k++] = vR[j++];
        }
    }

    // Termina de preencher o vetor caso tenha sobrado algum elemento
    while(i < tam1){
        vec[k++] = vL[i++];
    }
    while(j < tam2){
        vec[k++] = vR[j++];
    }

    // MOSTRA PASSO A PASSO DE RESOLUÇÃO (comentar se quiser)
    imprimeVetor("auxiliar esq", vL, tam1);
    imprimeVetor("auxiliar dir", vR, tam2);
    imprimeVetor("após ordenação", vec, tam);
    printf("\n");
}

// (a variavel int tam está apenas para imprimir o vetor após ordenação)
void merge_sort(int *vec, int l, int r, int tam){
    if(l < r){
        int m = (l+r)/2;
        merge_sort(vec, l, m, tam);
        merge_sort(vec, m+1, r, tam);
        
        merge(vec, l, r, tam);
    }
}

int main(){
    int tam; 
    int *vec = interacao(&tam);

    merge_sort(vec, 0, tam-1, tam);

    imprimeVetor("ordenado", vec, tam);
    free(vec);
}