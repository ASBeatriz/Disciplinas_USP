#include "pilha_enc.h"

int main(){
    PILHA *pilha = pilha_criar();
    char palavra1[] = "algo", palavra2[] = "something", palavra3[] = "alguma_coisa";
    ITEM *item1 = item_criar(1, palavra1);
    ITEM *item2 = item_criar(2, palavra2);
    ITEM *item3 = item_criar(3, palavra3);

    pilha_empilhar(pilha, item1);
    pilha_empilhar(pilha, item2);
    pilha_empilhar(pilha, item3);

    char *pTopo = (char *)item_get_dados(pilha_topo(pilha));
    printf("%s\n", pTopo);
}