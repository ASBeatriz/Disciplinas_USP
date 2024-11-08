/*  
Shell Sort:
Modificação do Insertion Sort. Em vez de só trocar itens adjacentes, o Shell Sort permite trocar itens distante
por um certo gap, que começa em um valor e termina em um (insertion sort). Assim, em certos casos, o número de comparações
é diminuída.
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

void shell_sort(int vec[], int tam){

    // aqui, o gap começa com tam/2 e vai até 1.
    for(int gap = tam/2; gap >= 1; gap /= 2){
        printf("GAP: %d\n", gap);

        for(int i=gap; i<tam; i++){
            int atual = vec[i];
            int j = i-gap;
            printf("Valor atual: %d\n", atual);

            while(j >= 0 && vec[j] > atual){
                // faz as trocas tal qual insertio sort
                vec[j+gap] = vec[j];
                j -= gap;

                imprimeVetor("", vec, tam);
            }
            vec[j+gap] = atual;

            imprimeVetor("", vec, tam);
        }
    }
}

int main(){
    int tam;
    int *vec = interacao(&tam);
    imprimeVetor("", vec, tam);

    shell_sort(vec, tam);

    imprimeVetor("ordenado", vec, tam);
}