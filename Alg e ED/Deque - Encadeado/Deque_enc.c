//Implementação Deque duplamente encadeada

#include "Deque_enc.h"

struct No {
    ITEM* item;
    NO *prox;
    NO *anterior;
};

struct Deque {
    int tamanho;
    NO* inicio;
    NO* fim;
};

DEQUE* deque_criar(void){
    DEQUE* deque = (DEQUE*)malloc(sizeof(DEQUE));
    if(deque != NULL){
        deque->tamanho = 0;
        deque->inicio = NULL;
        deque->fim = NULL;
        return deque;
    }
    return NULL;
}

bool deque_inserir_fim(DEQUE* deque, ITEM *item){
    if(!deque_cheia(deque) && deque != NULL){
        NO *novoNo = (NO*)malloc(sizeof(NO));
        // preencho os campos no novo nó
        novoNo->item = item;
        novoNo->prox = NULL;
        novoNo->anterior = deque->fim;

        if(deque->fim == NULL && deque->inicio == NULL){ //verifica caso inicial de inicio = fim = NULL
            deque->inicio = novoNo;
        }
        else{
            // antes de mudar o fim do deque, faço o prox do fim atual apontar para o novo fim
            deque->fim->prox = novoNo;
        }

        deque->fim = novoNo;
        deque->tamanho++;
        return true;
    }
    return false;
}

bool deque_inserir_inicio(DEQUE* deque, ITEM *item){
    if(!deque_cheia(deque) && deque != NULL){
        NO *novoNo = (NO*)malloc(sizeof(NO));
        // preencho os campos no novo nó
        novoNo->item = item;
        novoNo->prox = deque->inicio;
        novoNo->anterior = NULL;


        // caso em que o deque está vazio
        if(deque->tamanho == 0) deque->fim = novoNo;
        else{ //antes de mudar o inicio do deque, faço o anterior do início atual apontar para o novo início
            deque->inicio->anterior = novoNo;
        }

        deque->inicio = novoNo;
        deque->tamanho++;
        return true;
    }
    return false;
}

// Desaloca o nó e retorna o item removido
ITEM* deque_remover_inicio(DEQUE *deque){
    if(!deque_vazia(deque) && deque != NULL){
        NO* noRemovido = deque->inicio;
        ITEM *removido = noRemovido->item;

        deque->inicio = noRemovido->prox;
        //deque->inicio->anterior = NULL;

        if(deque->fim == noRemovido) deque->fim = NULL;   //se a pessoa (nó) removida for a única da deque, então o fim da deque passa a ser nulo

        free(noRemovido);
        noRemovido = NULL;

        deque->tamanho--;
        return removido;
    }
    return NULL;
}

ITEM* deque_remover_fim(DEQUE *deque){
    if(!deque_vazia(deque) && deque != NULL){
        NO* noRemovido = deque->fim;
        ITEM *removido = noRemovido->item;

        deque->fim = noRemovido->anterior;
        //deque->fim->prox = NULL;

        if(deque->inicio == noRemovido) deque->inicio = NULL;   //se a pessoa (nó) removida for a única da deque, então o inicio do deque passa a ser nulo

        // desaloca o nó
        free(noRemovido); 
        noRemovido = NULL;

        deque->tamanho--;
        return removido;
    }
    return NULL;
}

int deque_tamanho(DEQUE* deque){
    if(deque != NULL){
        return deque->tamanho;
    }
    return -1;
}

bool deque_cheia(DEQUE* deque){
    if(deque == NULL) return true;

    NO* no = (NO*)malloc(sizeof(NO));
    if(no != NULL){
        free(no);
        return false;
    }
    return true;
}

bool deque_vazia(DEQUE* deque){
    if(deque != NULL){
        return (deque_tamanho(deque) == 0);
    }
    return false;
}

/* Apaga o deque
algoritmo: 
chama a função de remover o item do deque até que a deque esteja vazia (inicio == NULL) 
e vai apagando os itens removidos. Por fim, desaloca a estrutura Deque.
*/
void deque_apagar(DEQUE **deque){
    if(*deque == NULL) return;
    while((*deque)->tamanho > 0){
        ITEM *itRemovido = deque_remover_fim(*deque); //função deque_remover já desaloca o nó
        item_apagar(&itRemovido);
    }
    free(*deque);   
    *deque = NULL; //faz o conteudo para o qual (**deque) aponta receber NULL
}

void deque_imprimirInt(DEQUE* deque){
    int tam = deque_tamanho(deque);
    NO* no = deque->inicio;
    for(int i=0; i<tam; i++){
        int *val = (int *)item_get_dados(no->item);
        printf("%d ", *val);
        no = no->prox;
    }    
    printf("\n");
}

