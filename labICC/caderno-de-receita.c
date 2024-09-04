/*
R (registrar receita): nome, qtFarinha, qtOvos, qtOleo, qtAcucar, qtChocolate
C (cadastrar compra): qtFarinha, qtOvos, qtOleo, qtAcucar, qtChocolate
F (fazer receita): numReceita
S = sair do programa

no final seu programa deve imprimir a quantidade remanecente de ingredientes e a quantidade de
receitas registradas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Receita{
    char *nome;
    int ingred[5]; //farinha, ovos, oleo, acucar, chocolate (cade o leite?)
} Receita;


void regReceita(Receita *receitas, int i){
    char nome[20];
    scanf("%s", nome);
    receitas[i].nome = (char*)malloc(sizeof(char)*strlen(nome));
    strcpy(receitas[i].nome, nome); //aloca o nome

    for(int j=0; j<5; j++){
        scanf("%d ", &receitas[i].ingred[j]);
    }
}

void desalocaReceitas(Receita **receitas, int linhas){
    for(int i=0; i<linhas; i++){
        free((*receitas)[i].nome);
        (*receitas)[i].nome = NULL;
    }
    free(*receitas);
    receitas = NULL;
}

int main(){
    char opc[2];
    Receita *receitas = (Receita*)malloc(sizeof(Receita));
    int cont=0, qtdIngred[5];
    char nomeIngred[5][9] = {"Farinha", "Ovos", "Oleo", "Acucar", "Chocolate"};

    for(int i=0; i<5; i++) qtdIngred[i] = 0;
    
    while(1){
        scanf("%s", opc);

        if(opc[0] == 'S') break;

        if(opc[0] == 'R'){
            if(cont){
                receitas = realloc(receitas, sizeof(Receita)*(cont+1)); //realoca o tamanho do vetor para caber mais uma receita
            }
            regReceita(receitas, cont++);
        }
        else if(opc[0] == 'C'){
            for(int i=0; i<5; i++){
                int qtd;
                scanf("%d ", &qtd);
                qtdIngred[i]+= qtd;
            }
        }
        else if(opc[0] == 'F'){
            int id, insuf=0;
            scanf("%d ", &id);
            if(id >= cont){
                printf("Receita nao encontrada!\n");
                continue;
            }
            for(int i=0; i<5; i++){

                if(receitas[id].ingred[i] > qtdIngred[i]){
                    if(i!=1) printf("%s insuficiente\n", nomeIngred[i]);
                    else printf("%s insuficientes\n", nomeIngred[i]);
                    insuf = 1;
                    break;
                }
            }
            if(!insuf){
                printf("%s feita com sucesso!\n", receitas[id].nome);
                for(int i=0; i<5; i++){
                    qtdIngred[i] -= receitas[id].ingred[i];
                }
            }
        }
        else{
            printf("Codigo invalido\n");
        }
    } 

    printf("Quantidade no estoque:\n");
    
    printf("Acucar: %d\nChocolate: %d\nFarinha: %d\nOleo: %d\nOvos: %d\n", qtdIngred[3], qtdIngred[4], qtdIngred[0], qtdIngred[2], qtdIngred[1]);

    printf("Receitas cadastradas: %d", cont);
    
    desalocaReceitas(&receitas, cont);
}