// Programa cliente para testar o TAD Lista Sequencial

#include "Lista_seq.h"
#include <stdio.h>

int main(){
    ITEM *it1, *it2, *it3, *it4,*it5, *it6;
    int val1 = 1, val2 = 2, val3 = 3, val4 = 4, val5 = 5,  val6 = 6;
    it1 = item_criar(10, &val1), it2 = item_criar(20, &val2), it3 = item_criar(30, &val3), it4 = item_criar(40, &val4), it5 = item_criar(50, &val5), it6 = item_criar(60, &val6);  

    // lista = ordenada, lista2 = não ordenada
    LISTA *lista = lista_criar(true), *lista2 = lista_criar(false);
    // insere itens nas listas
    lista_inserir(lista, it2);
    lista_inserir(lista, it5);
    lista_inserir(lista, it3);
    printf("Lista 1: \n  ");
    lista_imprimir(lista);

    lista_inserir(lista2, it1);
    lista_inserir(lista2, it6);
    lista_inserir(lista2, it4);
    printf("Lista 2: \n  ");
    lista_imprimir(lista2);
    
    // procura itens nas listas
    lista_busca(lista, 50);
    lista_busca(lista, 10);

    lista_busca(lista2, 60);
    lista_busca(lista2, 30);

    // remove itens das listas
    int removido = item_get_chave(lista_remover(lista, 30));
    printf("chave removida: %d\n", removido);
    lista_imprimir(lista);

    removido = item_get_chave(lista_remover(lista2, 60));
    printf("chave removida: %d\n", removido);
    lista_imprimir(lista2);

    // inserir elementos nas listas
    printf("inserindo elementos na lista1:\n");
    lista_inserir(lista, it6);
    lista_imprimir(lista);
    lista_inserir(lista, it1);
    lista_imprimir(lista);
    lista_inserir(lista, it3);
    lista_imprimir(lista);  

    printf("inserindo elementos na lista2:\n");
    lista_inserir(lista2, it3);
    lista_imprimir(lista2);
    lista_inserir(lista2, it6);
    lista_imprimir(lista2);

    // apaga as listas    

    // lista_apagar(&lista);    // ta comentado porque as listas têm elementos repetidos estava dando segfault
    // if(lista == NULL) printf("lista1 apagada\n");
    
    lista_apagar(&lista2);
    if(lista2 == NULL) printf("lista2 apagada\n");
}