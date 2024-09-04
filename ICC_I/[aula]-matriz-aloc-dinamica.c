#include<stdio.h>
#include<stdlib.h>


//Alocação dinâmica de matriz com lin linhas e col colunas
double **aloca(int lin, int col){
    double **p;

    p = (double**) malloc(lin*sizeof(double*)); //aloca as linhas (ponteiro para ponteiro)
    if(p == NULL){
        printf("ERRO: Sem memória disponível\n");
        exit(1);
    }

    for (int i = 0; i<lin; ++i){
        p[i] = (double*) malloc(col*sizeof(double)); //aloca as colunas (ponteiro)
        if(p[i] == NULL){
            printf("ERRO: Sem memória disponível\n");
            exit(1);
        }
    }

    return p;
}

void *aloca_geral (int x){ //função de tipo void para ficar generalizada e definir o tipo com cast (exemplo no int main)
    void *p;
    p = (void *) malloc(x);

    return p;
}

//------------ outras abordagens de aloc dinamica de matriz -------------------------
//1:
//  um vetor para abranger toda a matriz (de forma linear, uma linha após a outra) e um vetor de ponteiros (**p)(matriz) 
//  para indexar onde cada linha começa no vetor v. [mais eficiente pois utiliza menos malloc()]
//2: 
//  um vetor para abranger toda a matriz e utilizar fórmula para acessar as posições (linhas e colunas). (prof vai upar no tidia?)

//-----------------------------------------------------------------------------------

void ler_matriz(double **mat, int lin, int col){
    for(int i=0; i<lin; i++)
        for(int j=0; j<col; j++) 
            scanf("%lf",&mat[i][j]);
}

void desaloca_matriz(double ***mat, int lin, int col){ //recebe o >endereço< da variavel mat (que é um ponteiro para ponteiros)
    //(verificar dps que n tem diferença usar ++i ou i++)
    for(int i=0; i < lin; ++i){ 
        free((*mat)[i]); //libera os vetores linhas
        (*mat)[i] = NULL;
    }
    free(*mat);
    *mat = NULL; //libera a variável mat em si (é para isso que mat foi passado por referência)
}

int main(){
    int lin , col;
    double **m;
    scanf("%d %d", &lin, &col);

    m = aloca(lin, col);
    ler_matriz(m, lin, col); //passa m por valor (função faz uma copia)

    //Desalocar matriz com free():
    //se usar free(matriz), desaloca apenas os primeiros elementos de cada linha,
    //que é o lugar para onde o ponteiro para ponteiro está apontando.
    //Deve-se fazer o free() para cada vetor (linha).
    //Após o free(), faça o ponteiro apontar para nada (NULL).

    desaloca_matriz(&m, lin, col); //passa m por referencia (função recebe o endereço do próprio m, a fim de fazê-lo receber NULL)

    //exemplo com a função generalizada
    int *t;
    float *q;
    t = (int *)aloca_geral(4); 
    q = (float *)aloca_geral(5);

}