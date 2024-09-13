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
        ITEM *removido = fila->itens[fila->inicio]; //guarda o ponteiro do item a ser removido numa variavel auxiliar
        fila->itens[fila->inicio] == NULL;  //faz o ponteiro original (no vetor) receber NULL
        fila->inicio = (fila->inicio + 1) % TAM_MAX; //ajusta a nova posição do inicio
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

/* Apaga a fila
algoritmo: 
chama a função de remover o item da fila até que a fila esteja vazia (tam == 0) 
e vai apagando os itens removidos. Por fim, desaloca a estrutura Fila.
*/
void fila_apagar(FILA **fila){
    while((*fila)->tamanho != 0){
        ITEM *itRemovido = fila_remover(*fila);
        item_apagar(&itRemovido);
    }
    free(*fila);
    *fila = NULL;
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