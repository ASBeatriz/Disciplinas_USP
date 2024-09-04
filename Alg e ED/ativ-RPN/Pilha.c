#include "Pilha.h"

struct pilha{
    ITEM *itens[TAM];
    int tamanho; //topo da pilha
};

PILHA *pilha_criar(void){
    PILHA *pilha = (PILHA *)malloc(sizeof(PILHA));
    if(pilha != NULL){
        pilha->tamanho = 0;
        return pilha;
    }
    return NULL;
}

bool pilha_empilhar(PILHA *pilha, ITEM *item){
    if(!(pilha_cheia(pilha)) && !(pilha == NULL)){
        pilha->itens[pilha->tamanho] = item;    //adiciona o item no vetor da struct pilha
        pilha->tamanho = pilha->tamanho + 1;
        return true;
    }
    return false;
}

ITEM *pilha_desempilhar(PILHA *pilha){
    if(!(pilha_vazia(pilha)) && !(pilha == NULL)){
        ITEM *i = pilha_topo(pilha);    //guarda o item do topo para retornar
        pilha->itens[((pilha->tamanho) - 1)] = NULL;    //"apaga" o item do topo
        pilha->tamanho--;   //diminui o tamanho da pilha
        return i;
    }
    return NULL;
}

void pilha_apagar(PILHA **pilha){
    if(*pilha != NULL){
        free(*pilha);
        *pilha = NULL;
    }
}

bool pilha_vazia(PILHA *pilha){
    if(pilha != NULL){
        return ((pilha->tamanho == 0)? true : false);
    }
    return false;
}

bool pilha_cheia(PILHA *pilha){
    if(pilha != NULL){
        return ((pilha->tamanho == TAM)? true : false);
    }
    return true; //true ou false ????
}

int pilha_tamanho(PILHA *pilha){
    if(pilha != NULL){
        return pilha->tamanho;
    }
    exit(1);
}

ITEM *pilha_topo(PILHA *pilha){
    if(pilha != NULL){
        // printf("(topo)tam: %d", pilha_tamanho(pilha)); DEBUG
        return pilha->itens[((pilha->tamanho)-1)];
    }
    return NULL;
}
