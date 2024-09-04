// Programa para testar o funcionamento do TAD pilha
#include <stdio.h>
#include "pilha_seq.h"

int main(){
    int a=1, b=2, c=3;
    ITEM *i1 = item_criar(1, &a);
    ITEM *i2 = item_criar(2, &b);
    ITEM *i3 = item_criar(3, &c);
    PILHA_S *p = pilha_criar();
    pilha_empilhar(p, i1);
    pilha_empilhar(p, i2);
    pilha_empilhar(p, i3);
    pilha_desempilhar(p);

    ITEM *topo = pilha_topo(p);
    int *dado_topo = (int *)item_get_dados(topo);
    printf("%d\n", *dado_topo);
}