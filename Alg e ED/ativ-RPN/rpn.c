#include "Pilha.h"
#include <stdlib.h>

float rpn(char *sequencia){
    PILHA *pilha = pilha_criar();

    for(int i=0; sequencia[i] != '\0'; i++){
        char c = sequencia[i];
        if((int)c >= 48 && (int)c <= 57){
            // ascii: 0 = 48, 9 = 57.
            float *num = (float*)malloc(sizeof(float)); //alocação dinâmica para os endereços dos elementos não serem o mesmo
            *num = (float)((int)c - 48);
            ITEM *itNum = item_criar(0, num);
            pilha_empilhar(pilha, itNum);
        }
        else if(c == '+'){
            float n1 = *(float *)item_get_dados(pilha_desempilhar(pilha));
            float n2 = *(float *)item_get_dados(pilha_desempilhar(pilha));
            float *res = (float*)malloc(sizeof(float));
            *res = n1+n2;
            ITEM *itResul = item_criar(0, res);
            pilha_empilhar(pilha, itResul);
        }
        else if(c == '-'){
            float n1 = *(float *)item_get_dados(pilha_desempilhar(pilha));
            float n2 = *(float *)item_get_dados(pilha_desempilhar(pilha));
            float *res = (float*)malloc(sizeof(float));
            *res = n2-n1;
            ITEM *itResul = item_criar(0, res);
            pilha_empilhar(pilha, itResul);
        }
        else if(c == '*'){
            float n1 = *(float *)item_get_dados(pilha_desempilhar(pilha));
            float n2 = *(float *)item_get_dados(pilha_desempilhar(pilha));
            float *res = (float*)malloc(sizeof(float));
            *res = n1*n2;
            ITEM *itResul = item_criar(0, res);
            pilha_empilhar(pilha, itResul);
        }
        else if(c == '/'){
            float n1 = *(float *)item_get_dados(pilha_desempilhar(pilha));
            float n2 = *(float *)item_get_dados(pilha_desempilhar(pilha));
            float *res = (float*)malloc(sizeof(float));
            *res = n2/n1;
            ITEM *itResul = item_criar(0, res);
            pilha_empilhar(pilha, itResul);
        }
    }
    return *((float *)item_get_dados(pilha_topo(pilha)));
}