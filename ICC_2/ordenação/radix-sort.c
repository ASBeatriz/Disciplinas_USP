// Radix Sort - método de ordenação de inteiros processando-os dígito por dígito
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

    int counter[10] = {0};
    
    // preenche o vetor counter
    for(int i=0; i<n; i++){
        int digito = (v[i]/exp)%10;
        counter[digito]++;
    }

    // faz a soma acumulativa no vetor 
    for(int i=1; i < 10; i++){
        counter[i] += counter[i-1];
    }
    
    //imprime o vetor counter
    // for(int i=0; i<max+1; i++){
    //     printf("%d ", counter[i]);
    // }
    // printf("\n");
    
    // preenche o vetor ordenado baseado no vetor counter
    int ordenado[n];
    for(int i=n-1; i >= 0; i--){
        int digito = (v[i]/exp)%10;
        ordenado[counter[digito- 1]] = v[i]; 
        counter[digito]--;  
    }

    // imprime o vetor ordenado
    for(int i=0; i<n; i++){
        printf("%d ", ordenado[i]);
        v[i] = ordenado[i]; //atualiza o vetor 
    }
    printf("\n");
}

// Função que aplica radix sort
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

    radixSort(v, n);
}