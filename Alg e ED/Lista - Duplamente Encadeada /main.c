// Programa cliente para testar o TAD Lista Sequencial

#include "Lista_dup_enc.h"
#include <stdio.h>

int main(){
    ITEM *it1, *it2, *it3, *it4,*it5, *it6;
    int val1 = 1, val2 = 2, val3 = 3, val4 = 4, val5 = 5,  val6 = 6;
    it1 = item_criar(10, &val1), it2 = item_criar(20, &val2), it3 = item_criar(30, &val3), it4 = item_criar(40, &val4), it5 = item_criar(50, &val5), it6 = item_criar(60, &val6);  

    // true = ordenada, false = não ordenada
    LISTA *lista = lista_criar(false), *lista2 = lista_criar(true);

    // insere itens nas listas
    printf("INSERINDO:\n");
    printf("Lista 1: \n");
    lista_inserir(lista, it2, 'I');
    lista_imprimir(lista);
    lista_inserir(lista, it5, 'F'); //inserir fim
    lista_imprimir(lista);
    lista_inserir(lista, it3, 'I'); //inserir inicio
    lista_imprimir(lista);
    lista_inserir(lista, it1, 'I');
    lista_imprimir(lista);
    lista_inserir(lista, it6, 'F');
    lista_imprimir(lista);
    // lista 1:   1 3 2 5 6

    printf("Lista 2: \n");
    lista_inserir(lista2, it3, 'X');    //caractere não importa
    lista_imprimir(lista2);
    lista_inserir(lista2, it1, 'X');
    lista_imprimir(lista2);
    lista_inserir(lista2, it5, 'X');
    lista_imprimir(lista2);
    lista_inserir(lista2, it2, 'X');
    lista_imprimir(lista2);
    lista_inserir(lista2, it6, 'X');
    lista_imprimir(lista2);
    // lista 2:   1 2 3 5 6

    printf("\nBUSCA:\n");
    lista_busca(lista, 20);
    lista_busca(lista, 10);
    lista_busca(lista, 60);
    lista_busca(lista, 40);

    lista_busca(lista2, 10);
    lista_busca(lista2, 60);
    lista_busca(lista2, 30);
    lista_busca(lista2, 40);


    printf("\nREMOVENDO:\n");
    printf("Lista 1: \n");
    lista_imprimir(lista);
    lista_remover(lista, 10);
    lista_imprimir(lista);
    lista_remover(lista, 60);
    lista_imprimir(lista);
    lista_remover(lista, 20);
    lista_imprimir(lista);

    printf("\nLista 2: \n");
    lista_imprimir(lista2);
    lista_remover(lista2, 10);
    lista_imprimir(lista2);
    lista_remover(lista2, 60);
    lista_imprimir(lista2);
    lista_remover(lista2, 30);
    lista_imprimir(lista2);

    lista_apagar(&lista);
    if(lista == NULL) printf("\nlista1 apagada!\n");

    // comentado para não dá conflito de double free()
    // lista_apagar(&lista2);
    // if(lista2 == NULL) printf("lista2 apagada!\n");
}