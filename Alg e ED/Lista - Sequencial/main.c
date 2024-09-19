#include "Lista_seq.h"
#include <stdio.h>

int main(){
    ITEM *it1, *it2, *it3, *it4;
    int val1 = 1, val2 = 2, val3 = 3, val4 = 4;
    it1 = item_criar(10, &val1), it2 = item_criar(20, &val2), it3 = item_criar(30, &val3), it4 = item_criar(40, &val4);  

    LISTA *lista = lista_criar(true);
    lista_inserir(lista, it2);
    lista_inserir(lista, it4);
    lista_inserir(lista, it3);
    lista_inserir(lista, it1);
    lista_imprimir(lista);
    
    // procura item na lista
    int dado, chave = 15;
    if(item_get_dados(lista_busca(lista, chave)) != NULL) 
        dado = *(int*)(item_get_dados(lista_busca(lista, chave)));
    else dado = -1;

    if(dado != -1) printf("buscar item com chave %d: %d\n", chave, dado);
    else printf("dado nao encontrado\n");

    // remove um item da lista
    lista_remover(lista, 30);
    lista_imprimir(lista);

    // apaga a lista    
    lista_apagar(&lista);
    if(lista == NULL) printf("lista apagada\n");
}