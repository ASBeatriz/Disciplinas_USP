#include <stdio.h>

void lerNumeros(int n, int *vetor){
    for(int i=1; i<n; i++){
        int num;
        scanf("%d",&num);
        vetor[num] = 1;
    }
}

void numDesconhecido(int n, int *vetor){
    for(int i=1; i<=n; i++){
        if(vetor[i] == 0){
            printf("Numero desaparecido: %d", i);
        }
    }
}

int main(){
    int n, v[1000000];
    scanf("%d", &n);
    for(int i=0; i<=n; i++) v[i] = 0;

    lerNumeros(n,v);
    numDesconhecido(n,v);
    
    return 0;
}