#include "pilha_enc.h"

struct no{
    ITEM *item;
    NO *anterior;
};

struct pilha{
    NO *topo;
    int tam;
};

PILHA *pilha_criar(void){
    PILHA *pilha = (PILHA *)malloc(sizeof(PILHA));
    if(pilha != NULL){
        pilha->tam = 0;
        pilha->topo = NULL;
        return pilha;
    }
    return NULL;
}

bool pilha_empilhar(PILHA *pilha, ITEM *item){
    if(pilha != NULL && !pilha_cheia(pilha)){
        NO *novoNo = (NO *)malloc(sizeof(NO));  //cria um nó para comportar esse item
        if(novoNo != NULL){
            novoNo->anterior = pilha->topo;     //o topo atual da pilha vira o anterior do novo nó
            novoNo->item = item;        //adiciona o item no nó criado
            pilha->topo = novoNo;       //ajusta o topo da pilha para  o novo nó
            pilha->tam++;           //aumenta o tamanho da pilha
            return true;
        }
    }
    return false;
}

ITEM *pilha_desempilhar(PILHA *pilha){
    if(!pilha_vazia(pilha)){
        ITEM *itemDesemp = pilha->topo->item;   //guarda o item desempilhado para retornar
        NO *aux = pilha->topo;              //ponteiro auxiliar para não perder o endereço do topo e desalocá-lo
        pilha->topo = pilha->topo->anterior;    //ajusta o novo topo da pilha
        pilha->tam--;
        free(aux); 
        aux = NULL;
        return itemDesemp;  //item nao é desalocado pois é retornado na função para o cliente
    }
    return NULL;
}

void pilha_apagar(PILHA **pilha){
    if(*pilha != NULL){
        while((*pilha)->topo != NULL){
            // NO *noTopo = (*pilha)->topo;
            // ITEM *itemTopo = noTopo->item;
            ITEM *itemTopo = pilha_desempilhar(*pilha);     //função desaloca o nó e retorna o item
            item_apagar(&itemTopo);     //desaloca o item
        }
        free(*pilha);
        *pilha = NULL;
    }
}

bool pilha_vazia(PILHA *pilha){
    if(pilha != NULL){
        return (pilha->tam == 0 ? true : false);
    }
    return false;

}

bool pilha_cheia(PILHA *pilha){
    NO *no = (NO*) malloc(sizeof(NO));
    if(no != NULL){
        free(no);
        return false;
    }
    return true;
}

int pilha_tamanho(PILHA *pilha){
    if(pilha != NULL) return pilha->tam;
    return NULL;
}

ITEM *pilha_topo(PILHA *pilha){
    if(pilha != NULL){
        return pilha->topo->item;
    }
    return NULL;
}

