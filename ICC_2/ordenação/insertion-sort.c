/*  
Insertion Sort:
Consiste em ter um subvetor ordenado na parte esquerda e ir adicionando elementos da parte direita de forma ordenada 
nele. Inicialmente, o subvetor ordenado é apenas o primeiro elemento.    
*/
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

void insertion_sort(int vec[], int tam){
    printf("Ordenando: \n");
    for(int i=1; i<tam; i++){
        int atual = vec[i];
        int j = i-1;
        printf("Valor atual: %d\n", atual);
        while(j >= 0 && atual < vec[j]){
            // Enquanto os elementos ordenados (vindo da direita pra esquerda) são maiores que o valor que eu quero inserir,
            // eu passo eles para frente (n tem perigo de sobreescrever algum valor e perder pq eu já guardei o atual).
            vec[j+1] = vec[j];
            j--;
            imprimeVetor("", vec, tam);
        }
        // Quando eu finalmente encontrar um número menor ou igual ao que eu quero inserir, 
        // eu paro de shiftar e coloco meu número no vetor.
        vec[j+1] = atual;
        imprimeVetor("", vec, tam);
    }
}

int main(){
    int tam;
    int *vec = interacao(&tam);
    imprimeVetor("", vec, tam);

    insertion_sort(vec, tam);

    imprimeVetor("ordenado", vec, tam);
}