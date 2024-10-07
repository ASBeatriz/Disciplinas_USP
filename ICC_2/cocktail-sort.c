#include <stdio.h>

void imprimeVetor(int vec[], int tam){
    for(int i=0; i<tam; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// Funciona como um bubble sort bidirecional
void cocktailSort(int vec[], int tam){
    int trocas = 1;
    int fim = tam-1;
    int inicio = 0;

    while(trocas){
        imprimeVetor(vec, tam);
        trocas = 0;

        // vai trocando o maior valor em direção ao fim
        for(int i=inicio; i<fim; i++){
            if(vec[i] > vec[i+1]){
                int aux = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = aux;
                trocas = 1;
            }
        }
        if(!trocas) break;
        imprimeVetor(vec, tam);

        trocas = 0;
        fim--;  //uma vez estabelecido o maior valor no fim, não é mais necessário acessá-lo

        // vai trocando o menor valor em direção ao inicio
        for(int i=fim; i>inicio; i--){
            if(vec[i] < vec[i-1]){
                int aux = vec[i];
                vec[i] = vec[i-1];
                vec[i-1] = aux;
                trocas = 1;
            }
        }
        inicio++;   //mesma ideia do fim--
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int vec[n];
    for(int i=0; i<n; i++){
        scanf("%d", &vec[i]);   
    }

    cocktailSort(vec, n);
}