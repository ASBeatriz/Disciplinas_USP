#include <stdio.h>
#include "heap_seq.h"

int main(){
    ITEM *it1, *it2, *it3, *it4,*it5, *it6;
    int val1 = 1, val2 = 2, val3 = 3, val4 = 4, val5 = 5,  val6 = 6;
    it1 = item_criar(10, &val1), it2 = item_criar(20, &val2), it3 = item_criar(30, &val3), it4 = item_criar(40, &val4), it5 = item_criar(50, &val5), it6 = item_criar(60, &val6);  

    HEAP_SEQ *heap = heap_criar();

    // Faz as inserções
    heap_enfileirar(heap, it4);
    heap_enfileirar(heap, it2);
    heap_enfileirar(heap, it1);
    heap_enfileirar(heap, it3);
    heap_enfileirar(heap, it5);
    heap_enfileirar(heap, it6);

    // Faz buscas
    // int elem1 = 20, elem2 = 70;
    // if(heap_busca(heap, elem1) != NULL) printf("Elemento %d existe na árvore\n", elem1);
    // else printf("Elemento %d não existe na árvore\n", elem1);

    // if(heap_busca(heap, elem2) != NULL) printf("Elemento %d existe na árvore\n", elem2);
    // else printf("Elemento %d não existe na árvore\n", elem2);

    heap_imprimir(heap);

    int x1 = 40;
    if(heap_remover(heap) != NULL) printf("elemento removido com sucesso!\n");
    else printf("elemento não removido.\n");
    heap_imprimir(heap);

    if(heap_remover(heap) != NULL) printf("elemento removido com sucesso!\n");
    else printf("elemento não removido.\n");
    heap_imprimir(heap);

    // Apaga a árvore
    heap_apagar(&heap);
    if(heap == NULL) printf("heap apagada!\n");
}
/* Heap máx:

         60
       /   \
     40    50
     / \     \
   20  30    10
*/