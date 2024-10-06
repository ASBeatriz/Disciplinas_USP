// Programa cliente para testar o TAD Lista Encadeada

#include "Lista_enc.h"
#include <stdio.h>

int main(){
    ITEM *it1, *it2, *it3, *it4,*it5, *it6;
    int val1 = 1, val2 = 2, val3 = 3, val4 = 4, val5 = 5,  val6 = 6;
    it1 = item_criar(10, &val1), it2 = item_criar(20, &val2), it3 = item_criar(30, &val3), it4 = item_criar(40, &val4), it5 = item_criar(50, &val5), it6 = item_criar(60, &val6);  

    //true = ordenado, false = não ordenado
    LISTA *lista = lista_criar(true);

    // insere itens nas listas
    lista_inserir(lista, it2);
    lista_inserir(lista, it5);
    lista_inserir(lista, it3);
    lista_inserir(lista, it1);
    lista_inserir(lista, it6);
    printf("Lista 1: \n  ");
    lista_imprimir(lista);

    lista_busca_recursivo(lista, 50);
    lista_busca_recursivo(lista, 70);
    lista_busca(lista, 50);
    lista_busca(lista, 70);

    printf("Removendo\n");
    lista_imprimir(lista);
    lista_remover(lista, 30);
    lista_imprimir(lista);
    lista_remover(lista, 10);
    lista_imprimir(lista);
    lista_remover(lista, 20);
    lista_imprimir(lista);
    lista_remover(lista, 60);
    lista_imprimir(lista);

    lista_apagar(&lista);
    if(lista == NULL) printf("lista apagada!\n");

}