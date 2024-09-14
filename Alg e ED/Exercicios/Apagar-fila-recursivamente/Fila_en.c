//Implementação fila encadeada
//exercicio - apagar recursivamente

#include "Fila_en.h"

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
        NO* noInicio = fila->inicio;
        ITEM *removido = noInicio->item;
        fila->inicio = noInicio->prox;
        fila->tamanho--;
        free(noInicio); // é necessário?

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

/* Apaga a fila recursivamente
algoritmo:
remove e apaga o item e chama recursivamente até a fila estar vazia. Por fim, desaloca o ponteiro da fila.
*/
void fila_apagar(FILA **f){
    if(*f == NULL) return;
    if((*f)->inicio == NULL){
        free(*f);
        *f = NULL;
        return;
    }

    item_apagar(&(*f)->inicio->item);
    fila_remover(*f);
    fila_apagar(f);
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

