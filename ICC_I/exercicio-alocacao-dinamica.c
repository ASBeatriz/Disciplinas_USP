#include <stdio.h>
#include <stdlib.h>

double *aloca();

double *aloca(int tam){
    double *p;
    if((p = (double *)malloc(tam*sizeof(double))) == NULL){
        printf("Sem memoria");
        exit(1);
    }
    else{
        return p;
    }
}

//programa que aloca dinamicamente um vetor de doubles com a dimensão e os elementeos determinados pelo usuário
int main(){
    int tamanho;
    double *vet;

    scanf("%d", &tamanho);
    vet = aloca(tamanho);

    for(int i=0; i<tamanho; i++) scanf("%lf", &vet[i]); //ponteiros podem ser indexados
    for(int j=0; j<tamanho; j++) printf("%.2lf ", vet[j]);
}