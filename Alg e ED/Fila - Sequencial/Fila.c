#include "Fila.h"

struct Fila {
    ITEM* itens[TAM_MAX];
    int tamanho;
    int inicio;
    int fim;
};

FILA* fila_criar(void){
    FILA* fila = (FILA*)malloc(sizeof(FILA));
    if(fila != NULL){
        fila->tamanho = 0;
        fila->inicio = 0;
        fila->fim = 0;
        return fila;
    }
    return NULL;
}

bool fila_inserir(FILA* fila, ITEM *item){
    if(!fila_cheia(fila) && fila != NULL){
        fila->itens[fila->fim] = item;
        fila->fim = (fila->fim+1) % TAM_MAX;
        fila->tamanho++;
        return true;
    }
    return false;
}

ITEM* fila_remover(FILA *fila){
    if(!fila_vazia(fila) && fila != NULL){
        ITEM *removido = fila->itens[fila->inicio];
        fila->itens[fila->inicio] == NULL;
        fila->inicio = (fila->inicio + 1) % TAM_MAX;
        fila->tamanho--;
        return removido;
    }
    return NULL;
}

int fila_tamanho(FILA* fila){
    if(fila != NULL){
        return fila->tamanho;
    }
    return -1;
}

bool fila_cheia(FILA* fila){
    if(fila != NULL){
        return (fila_tamanho(fila) == TAM_MAX);
    }
    return true;
}

bool fila_vazia(FILA* fila){
    if(fila != NULL){
        return (fila_tamanho(fila) == 0);
    }
    return false;
}

void fila_imprimirInt(FILA* fila){
    int tam = fila_tamanho(fila), ini = fila->inicio;
    for(int i=0; i<tam; i++){
        int *val = (int *)item_get_dados(fila->itens[ini]);
        printf("%d ", *val);
        ini = (ini+1)%TAM_MAX;
    }    
    printf("\n");
}