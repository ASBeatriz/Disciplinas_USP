// Radix Sort adaptado para incluir números negativos
#include <stdio.h>

// função auxiliar para pegar o maior valor de um array
int getMax(int v[], int n){
    int max = 0;
    for(int i=0; i<n; i++){
        if(v[i] > max) max = v[i];
    }
    return max;
}

// counting sort para ordenar os elementos baseado em um de seus dígitos
void countingSort(int v[], int n, int exp){

    // 0 a 18 => -9 a 9
    int counter[19] = {0};
    
    // preenche o vetor counter
    for(int i=0; i<n; i++){
        int digito = (v[i]/exp)%10;
        counter[digito + 9]++;
    }

    // faz a soma acumulativa no vetor 
    for(int i=1; i < 19; i++){
        counter[i] += counter[i-1];
    }
    
    // imprime o vetor counter
    // printf("vetor counter: ");
    // for(int i=0; i<18; i++){
    //     printf("%d ", counter[i]);
    // }
    // printf("\n");
    
    
    int ordenado[n];
    for(int i=0; i<n; i++){ //impede que posições não alteradas fiquem sem atribuição no vetor
        ordenado[i] = v[i];
    }

    // preenche o vetor ordenado baseado no vetor counter
    for(int i=n-1; i >= 0; i--){
        int digito = (v[i]/exp)%10;
        ordenado[counter[(digito + 9)]-1] = v[i]; 
        counter[digito+9]--;  
    }

    // imprime o vetor ordenado
    for(int i=0; i<n; i++){
        printf("%d ", ordenado[i]);
        v[i] = ordenado[i]; //atualiza o vetor 
    }
    printf("\n");
}

// Função que ordena os elementos processando-os dígito por dígito
void radixSort(int v[], int n){
    int max = getMax(v, n);

    for(int exp = 1; max/exp >= 1; exp *= 10){  //a potência de 10 só incrementa até onde é necessário
        countingSort(v, n, exp);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int v[n];
    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    for(int i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    radixSort(v, n);
}