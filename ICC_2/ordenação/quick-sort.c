#include <stdio.h>
#include <stdlib.h>

// Função para imprimir um vetor.
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
void ordena_pivo(int vec[], int esq, int dir, int *posPivo, int tam){
    int pivo = vec[(esq+dir)/2];
    printf("\npivo: %d\n", pivo);
    int i = esq, j = dir;

    printf("trocas:\n");
    while(i < j){
        // incrementa enquanto não achar um numero maior ou igual na esquerda
        if(!(vec[i] >= pivo)) i++;

        // incrementa enquanto não achar um numero menor ou igual na direita
        if(!(vec[j] <= pivo)) j--;
        
        if(vec[i] >= pivo && vec[j] <= pivo){
            // troca
            printf("(%d e %d)\n", vec[i], vec[j]);
            int aux = vec[i];
            vec[i] = vec[j];
            vec[j] = aux;
            imprimeVetor("", vec, tam);
        }
    }
    // no fim, i = j = posição do pivô após trocas
    *posPivo = i;
}

void quick_sort(int vec[], int esq, int dir, int tam){
    int posPivo;

    // aplica a ordenação a partir do pivo e nos dois subvetores de cada lado.
    ordena_pivo(vec, esq, dir, &posPivo, tam);
    if(posPivo+1 < dir)
        quick_sort(vec, posPivo+1, dir, tam);
    if(posPivo-1 > esq)
        quick_sort(vec, esq, posPivo-1, tam);
}

int main(){
    int tam; 
    int *vec = interacao(&tam);

    quick_sort(vec, 0, tam-1, tam); // variável tam só está sendo usada para imprimir o passo a passo no terminal

    imprimeVetor("ordenado", vec, tam);
    free(vec);
}