#include<stdio.h>

void ordenar(int *v, int n){
    while(1){
        int cont = 0;
        for(int i=0; i<n-1; i++){
            if(v[i] < v[i+1]){
                int g = v[i];
                v[i] = v[i+1];
                v[i+1] = g;
                cont++;
            }
            else if(v[i] == v[i+1]){
                v[i+1] = -1;
            }
        }
        if(!cont) break;
    }
}

int main(){
    int n, atletas[101], classif[101];
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        scanf("%d", &atletas[i]);
        classif[i] = atletas[i];
    }
    ordenar(classif, n);
    
    for(int i=0; i<n; i++){
        int j;
        for (j = 0; j < n; j++){
            if(atletas[i] == classif[j]) break;
        }
        
        printf("%dº Atleta, %d Pontos, %dº Colocado\n", i+1, atletas[i], j+1);
    }
    // printf("\n");
    // for(int i=0; i<n; i++){
    //     printf("%d ", classif[i]);
    // }
}