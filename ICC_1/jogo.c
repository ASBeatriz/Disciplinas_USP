/*
Objetivo do código: Resolver o execício "Jogo" da matéria de ICC1.
Exercício: Ao receber do usuário uma matriz de n linhas e m colunas (n e m também fornecidos pelo usuário)
preenchidas por '.' e 'X', a saída deve ser a mesma matriz reescrita com '*' nos lugares que contém '.' e
que não possuem um número ímpar de vizinhos adjacentes iguais a 'X'.

Autora: Beatriz Santos (2024)
*/

#include <stdio.h>
#include <stdlib.h>

// Protótipo das funções
char **aloca_matriz(int l, int c);
void desaloca_matriz(char ***mat, int l);
void marcar(char** mat, int l, int c);

/* A função aloca_matriz() é responsável por alocar dinamicamente a matriz recebida pelo usuário e retornar seu ponteiro.
Recebe a quantidade de linhas (l) e colunas (c) como parâmetro. */
char **aloca_matriz(int l, int c){
    char **mat;
    mat = (char**)malloc(l*sizeof(char*));

    //Verifica impossibilidade de alocação
    if(mat == NULL){    
        printf("ERRO: Sem memória disponível");
        exit(1);
    }

    for(int i=0; i<l; i++){
        mat[i] = (char *)malloc(c*sizeof(char));

        //Verifica impossibilidade de alocação
        if(mat[i] == NULL){
            printf("ERRO: Sem memória disponível");
            exit(1);
        }
    }
    return mat;
}

/* A função desaloca_matriz() é responsável por liberar o espaço dinamicamente ocupado pela matriz. */
void desaloca_matriz(char ***mat, int l){
    for(int i=0; i<l; i++){
        free((*mat)[i]);
        (*mat)[i] = NULL;
    }
    free(*mat);
    *mat = NULL;
}

/* a função marcar() é responsável por fazer a alteração da matriz, ou seja, marcar com '*' as devidas posições.
Ela percorre a matriz fazendo a verificação de cada posição. */
void marcar(char** mat, int l, int c){
    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            //verifica se a posição pode ser alterada 
            if(mat[i][j] != '.') continue; 

            //determina a quantidade de vizinhos iguais a 'X' e armazena na variável cont
            int cont=0;
            if((i-1 >= 0)&&(mat[i-1][j] == 'X')) cont++;
            if((i+1 < l)&&(mat[i+1][j] == 'X')) cont++;
            if((j-1 >= 0)&&(mat[i][j-1] == 'X')) cont++;
            if((j+1 < c)&&(mat[i][j+1] == 'X')) cont++;

            //verifica se a quantidade de vizinhos 'X' é par
            if(cont%2 == 0) mat[i][j] = '*';
        }
    }
}

/* Função principal. Responsável por ler a quantidade de linhas e colunas, ler a matriz e imprimir a matriz final */
int main (void){
    int n, m;
    scanf("%d %d", &n, &m);

    char **matriz = aloca_matriz(n, m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf(" %c", &matriz[i][j]);
        }
    }

    marcar(matriz, n, m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }

    desaloca_matriz(&matriz, n);

    return 0;
}