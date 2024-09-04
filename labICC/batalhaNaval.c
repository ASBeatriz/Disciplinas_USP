#include<stdio.h>

void lerMatriz(int n, char matriz[27][27]);
void imprimirMatriz(char matriz[27][27],int n);
void verifJogada(int  l, int c, char mapa[27][27]);

void lerMatriz(int n, char matriz[27][27]){
    for(int i=0; i<n; i++){
        for(int j=0; j < n; j++){
            scanf(" %c",&matriz[i][j]);
        }
    }
}

void verifJogada(int  l, int c, char mapa[27][27]){
    if(mapa[l][c] == 'N'){
        printf("acerto!\n");
        mapa[l][c] = 'X';
    }
    else printf("erro!\n");
}

void imprimirMatriz(char matriz[27][27],int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n, rounds;
    char mapa[27][27];

    scanf("%d", &n);
    lerMatriz(n,mapa);

    scanf("%d", &rounds);
    
    for (int i = 0; i < rounds; i++){
        char cord[4];
        scanf("%s", cord);
        int lin = (int)cord[0] - 64;
        int col = (int)cord[1] - 48;
        if(cord[2] != '\0'){
            int uni = (int)cord[2] - 48;
            col = col*10 + uni;
        }
        verifJogada(lin-1, col-1, mapa);
    }

    imprimirMatriz(mapa, n);
}