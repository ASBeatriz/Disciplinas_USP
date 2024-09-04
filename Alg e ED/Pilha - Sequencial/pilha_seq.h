#ifndef PILHA_SEQ_H
#define PILHA_SEQ_H
    #include <stdbool.h>
    #include <stdlib.h>
    #include "item.h"

    #define TAM 100 //tamanho máximo de uma pilha

    typedef struct pilha PILHA_S;

    PILHA_S *pilha_criar(void);
    void pilha_apagar(PILHA_S **pilha);
    bool pilha_vazia(PILHA_S *pilha);
    bool pilha_cheia(PILHA_S *pilha);
    int pilha_tamanho(PILHA_S *pilha);
    ITEM *pilha_topo(PILHA_S *pilha);
    bool pilha_empilhar(PILHA_S *pilha, ITEM *item);
    ITEM *pilha_desempilhar(PILHA_S *pilha);
    void pilha_print(PILHA_S *p);
    void pilha_inverter(PILHA_S *p);


#endif