#include<stdio.h>

void defineOcupacao(char matriz[21][21], int *vetLinha, int *vetColuna, int l, int c);
void matrizResposta(int lin, int col, char matriz[21][21], int *vetLinha, int *vetColuna, int *cont);
void printaResult(int cont, int  lin, int col, char matriz[21][21]);

void printaResult(int cont, int  lin, int col, char matriz[21][21]){
    if(cont){
        for(int l=0; l<lin; l++){
            for(int c=0; c<col; c++){
                printf("%c ", matriz[l][c]);
            }
            printf("\n");
        }
    }
    else printf("Eh um dia triste para os mono Yasuo\n");
}

void defineOcupacao(char matriz[21][21], int *vetLinha, int *vetColuna, int l, int c){
    if(matriz[l][c] == 'c'){
        vetColuna[c] = 1;
        vetLinha[l] = 1;
    }
}

void matrizResposta(int lin, int col, char matriz[21][21], int *vetLinha, int *vetColuna, int *cont){
    for(int l=0; l<lin; l++){
        for(int c=0; c<col; c++){
            if((matriz[l][c] == 'v') && (!vetColuna[c]) && (!vetLinha[l])){
                matriz[l][c] = 'o';
                *cont=1;
            }
            else matriz[l][c] = 'x';
        }
    }
}


int main(){
    int lin, col, ocupLin[21], ocupCol[21];
    char m[21][21];
    scanf("%d %d", &lin, &col);

    for(int i=0; i<lin; i++) ocupLin[i]=0;
    for(int i=0; i<col; i++) ocupCol[i]=0;

    for(int l=0; l<lin; l++){
        for(int c=0; c<col; c++){
            scanf(" %c", &m[l][c]);
            defineOcupacao(m, ocupLin, ocupCol, l, c);
        }
    }
    
    int cont=0;
    matrizResposta(lin, col, m, ocupLin, ocupCol, &cont);
    
    printaResult(cont, lin, col, m);
}