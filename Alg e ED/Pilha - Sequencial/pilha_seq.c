#include "pilha_seq.h"

struct pilha{
    ITEM *itens[TAM];
    int tamanho; //topo da pilha
};

PILHA_S *pilha_criar(void){
    PILHA_S *pilha = (PILHA_S *)malloc(sizeof(PILHA_S));
    if(pilha != NULL){
        pilha->tamanho = 0;
        return pilha;
    }
    return NULL;
}

bool pilha_empilhar(PILHA_S *pilha, ITEM *item){
    if(!(pilha_cheia(pilha)) && !(pilha == NULL)){
        pilha->itens[pilha->tamanho] = item;    //adiciona o item no vetor da struct pilha
        pilha->tamanho = pilha->tamanho + 1;
        return true;
    }
    return false;
}

ITEM *pilha_desempilhar(PILHA_S *pilha){
    if(!(pilha_vazia(pilha)) && !(pilha == NULL)){
        ITEM *i = pilha_topo(pilha);    //guarda o item do topo para retornar
        pilha->itens[pilha->tamanho - 1] = NULL;    //"apaga" o item do topo
        pilha->tamanho--;   //diminui o tamanho da pilha
        return i;
    }
    return NULL;
}

void pilha_apagar(PILHA_S **pilha){
    if(*pilha != NULL){
        free(*pilha);
        *pilha = NULL;
    }
}

bool pilha_vazia(PILHA_S *pilha){
    if(pilha != NULL){
        return ((pilha->tamanho == 0)? true : false);
    }
    return false;
}

bool pilha_cheia(PILHA_S *pilha){
    if(pilha != NULL){
        return ((pilha->tamanho == TAM)? true : false);
    }
    return true; //true ou false ????
}

int pilha_tamanho(PILHA_S *pilha){
    if(pilha != NULL){
        return pilha->tamanho;
    }
    exit(1);
}

ITEM *pilha_topo(PILHA_S *pilha){
    if(pilha != NULL){
        return pilha->itens[(pilha->tamanho-1)];
    }
    return NULL;
}

// Como printar tipo ITEM ?????
// void pilha_print(PILHA_S *pilha){
//     if(pilha != NULL){
//         for(int i=0; i<pilha->tamanho; i++){
//             printf("%*", pilha->itens[i]);
//         }
//     }
//     exit(1);
// }


//void pilha_inverter(PILHA_S *p);
