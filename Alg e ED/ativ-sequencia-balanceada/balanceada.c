#include "Pilha.h"

bool balanceada(char *sequencia){
    PILHA *delim = pilha_criar();
    char *c = sequencia;
    bool res = true;
    while(*c != '\0'){
        int chave;
        if(*c == '(' || *c == ')') chave = 1; 
        if(*c == '[' || *c == ']') chave = 2; 
        if(*c == '{' || *c == '}') chave = 3; 
        ITEM *item = item_criar(chave, c);

        if(*c == '(' || *c == '[' || *c == '{'){
            pilha_empilhar(delim, item);
        }
        else{
            if(pilha_vazia(delim)){
                res = false;
                break;
            }
            int chaveTopo = item_get_chave(pilha_topo(delim));
            // printf("pilha topo: %c\n", *(char *)item_get_dados(pilha_topo(delim)));  //debug
            if(chaveTopo == item_get_chave(item)){
                pilha_desempilhar(delim);
            }
            else{
                res = false;
                break;
            }
        }
        c++;
    }
    if(!pilha_vazia(delim)) res = false;
    return res;
}