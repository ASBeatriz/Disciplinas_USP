#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoas{
    char *nome, *cpf;
    int idade;
    float saldo, credito, total;
} Pessoas;

void leituraClientes(int n, Pessoas* clientes){
    for(int i=0; i<n; i++){
        char *nome = (char*)malloc(30*sizeof(char));

        scanf(" %[^,]s", nome);
        clientes[i].nome = (char*)malloc(strlen(nome)*sizeof(char));
        strcpy(clientes[i].nome, nome);
        free(nome);
        nome = NULL;

        getchar();
        clientes[i].cpf = (char*)malloc(12*sizeof(char));
        scanf(" %[^,]s", clientes[i].cpf);
        
        getchar();
        scanf(" %d", &clientes[i].idade);
        getchar();
        scanf(" %f", &clientes[i].saldo);
        getchar();
        scanf(" %f", &clientes[i].credito);
        getchar();
        clientes[i].total = clientes[i].saldo - clientes[i].credito;
    }
}

void imprimeClientes(int n, Pessoas* clientes){
    for(int i=0; i<n; i++){
        printf("Dados da pessoa %d:\n", i+1);
        printf("Nome: %s\nCPF: %s\nIdade: %d\nSaldo: %.2f\nCredito: %.2f\n", clientes[i].nome, clientes[i].cpf, clientes[i].idade, clientes[i].saldo, clientes[i].credito);
        printf("\n");
    }
}

void imprimeEndividados(int n, Pessoas* clientes){
    printf("Pessoas endividadas:");
    int exists = 0;
    for(int i=0; i<n; i++){
        if(clientes[i].total < 0){
            printf("\nNome: %s\nCPF: %s\nDivida: %.2f\n", clientes[i].nome, clientes[i].cpf, -(clientes[i].total));
            exists = 1;
        }
    }
    if(!exists){
        printf("\nNenhuma pessoa endividada encontrada.");
    }
}

desalocaCampos(int n, Pessoas* clientes){
    for(int i = 0; i < n; i++){
        free(clientes[i].nome);
        free(clientes[i].cpf);
        clientes[i].nome = NULL;
        clientes[i].cpf = NULL;
    }
}

int main(){
    Pessoas *clientes = (Pessoas *)malloc(60*sizeof(Pessoas));
    int n;
    scanf("%d ", &n);
    
    leituraClientes(n, clientes);
    imprimeClientes(n, clientes);
    imprimeEndividados(n, clientes);

    desalocaCampos(n, clientes);
    
    free(clientes);
    clientes = NULL;
}