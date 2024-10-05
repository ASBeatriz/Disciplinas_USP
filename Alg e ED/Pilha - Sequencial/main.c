// Programa para testar o funcionamento do TAD pilha
#include <stdio.h>
#include "pilha_seq.h"

void imprimir_pilha(PILHA_S *pilha){
    while(!pilha_vazia(pilha)){
        int *pTopo = (int *)item_get_dados(pilha_desempilhar(pilha));
        printf("%d\n", *pTopo);
    }
}

int main(){
    int a=1, b=2, c=3;
    ITEM *i1 = item_criar(1, &a);
    ITEM *i2 = item_criar(2, &b);
    ITEM *i3 = item_criar(3, &c);
    PILHA_S *p = pilha_criar();
    pilha_empilhar(p, i1);
    pilha_empilhar(p, i2);
    pilha_empilhar(p, i3);
    //pilha: 3 2 1

    ITEM *topo = pilha_topo(p);
    int *dado_topo = (int *)item_get_dados(topo);
    printf("topo: %d\n", *dado_topo);

    pilha_inverter(p); //inverte pilha

    //pilha: 1 2 3
    imprimir_pilha(p);
}