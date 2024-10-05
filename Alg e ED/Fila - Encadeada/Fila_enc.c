//Implementação fila encadeada

#include "Fila_enc.h"

struct No {
    ITEM* item;
    NO *prox;
};

struct Fila {
    int tamanho;
    NO* inicio;
    NO* fim;
};

FILA* fila_criar(void){
    FILA* fila = (FILA*)malloc(sizeof(FILA));
    if(fila != NULL){
        fila->tamanho = 0;
        fila->inicio = NULL;
        fila->fim = NULL;
        return fila;
    }
    return NULL;
}

bool fila_inserir(FILA* fila, ITEM *item){
    if(!fila_cheia(fila) && fila != NULL){
        NO *novoNo = (NO*)malloc(sizeof(NO));
        novoNo->item = item;
        novoNo->prox = NULL;
        if(fila->fim == NULL && fila->inicio == NULL){ //verifica caso inicial de inicio = fim = NULL
            fila->inicio = novoNo;
            fila->fim = novoNo;
        }
        else{
            fila->fim->prox = novoNo;
            fila->fim = novoNo; 
        }

        fila->tamanho++;

        // Debug
        // printf("Fila inicio: %d ", *(int *)item_get_dados(fila->inicio->item));
        // printf("Fila fim: %d\n", *(int *)item_get_dados(fila->fim->item));
        return true;
    }
    return false;
}

// Desaloca o nó e retorna o item removido
ITEM* fila_remover(FILA *fila){
    if(!fila_vazia(fila) && fila != NULL){
        NO* noRemovido = fila->inicio;
        ITEM *removido = noRemovido->item;
        fila->inicio = noRemovido->prox;
        if(fila->fim == noRemovido) fila->fim = NULL;   //se a pessoa (nó) removida for a única da fila, então o fim da fila passa a ser nulo

        fila->tamanho--;
        free(noRemovido); noRemovido = NULL;

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
    if(fila == NULL) return true;

    NO* no = (NO*)malloc(sizeof(NO));
    if(no != NULL){
        free(no);
        return false;
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
chama a função de remover o item da fila até que a fila esteja vazia (inicio == NULL) 
e vai apagando os itens removidos. Por fim, desaloca a estrutura Fila.
*/
void fila_apagar(FILA **fila){
    if(*fila == NULL) return;
    while((*fila)->inicio != NULL){
        ITEM *itRemovido = fila_remover(*fila); //função fila_remover já desaloca o nó
        item_apagar(&itRemovido);
    }
    free(*fila);
    *fila = NULL; //faz o conteudo para o qual (**fila) aponta receber NULL
    /* Se fosse:
        fila_apagar(*fila){
        ...
        fila = NULL
        }
       Então o que receberia NULL seria a cópia do ponteiro *fila, e não o ponteio 
       em si passado como parâmatro da função.
     */
}

void fila_imprimirInt(FILA* fila){
    int tam = fila_tamanho(fila);
    NO* no = fila->inicio;
    for(int i=0; i<tam; i++){
        int *val = (int *)item_get_dados(no->item);
        printf("%d ", *val);
        no = no->prox;
    }    
    printf("\n");
}

