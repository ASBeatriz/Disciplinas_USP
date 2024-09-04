#include<stdio.h>
#include<ctype.h>

int main(){
    int v[100000], n, i=0;
    char opc;

    while(scanf("%d", &n)){
        if(n == 1) break;
        v[i++] = n;
    }
    scanf(" %c", &opc);
    if(opc == 'a'){
        while(1){
            int troca = 0;
            for(int j=0; j<i-1; j++){
                if(v[j] > v[j+1]){
                    int g = v[j];
                    v[j] = v[j+1];
                    v[j+1] = g;
                    troca=1;
                }
            }
            if(!troca) break;
        }
        printf("vetor ordenado:");
        for(int j=0; j<i; j++) printf("%d ",v[j]);
    }
    else if(opc == 'b'){
        int fibonacci[18];
        fibonacci[0] = 0;
        fibonacci[1] = 1;
        for(int j=2; j<18; j++){
            fibonacci[j] = fibonacci[j-1]+fibonacci[j-2];
        }
        printf("Numeros de Fibonacci:");
        for(int j=0; j<i; j++){
            for(int t=0; t<18; t++){
                if(v[j] == fibonacci[t]) printf("%d ", v[j]);
            }
        }
    }
    else if(opc == 'c'){
        printf("Vetor maiusculo:");
        for(int j=0; j<i; j++){
            printf("%c ", toupper((char)v[j]));
        }
    }
    else printf("Comando inexistente\n");
}