#include "Deque.h"
#include <stdio.h>

int main(){
    ITEM *it1, *it2, *it3, *it4,*it5, *it6;
    int val1 = 1, val2 = 2, val3 = 3, val4 = 4, val5 = 5,  val6 = 6;
    it1 = item_criar(10, &val1), it2 = item_criar(20, &val2), it3 = item_criar(30, &val3), it4 = item_criar(40, &val4), it5 = item_criar(50, &val5), it6 = item_criar(60, &val6);  

    DEQUE *deque = deque_criar();
    deque_inserir_fim(deque, it1);
    deque_imprimirInt(deque);
    deque_inserir_fim(deque, it2);
    deque_imprimirInt(deque);
    deque_inserir_inicio(deque, it3);
    deque_imprimirInt(deque);
    deque_inserir_inicio(deque, it4);
    deque_imprimirInt(deque);

    ITEM* removido = deque_remover_inicio(deque);
    printf("item removido: %d\n", *((int *)item_get_dados(removido)));
    deque_imprimirInt(deque);

    removido = deque_remover_fim(deque);
    printf("item removido: %d\n", *((int *)item_get_dados(removido)));
    deque_imprimirInt(deque);

    deque_apagar(&deque);
    if(deque == NULL) printf("Deque apagado!\n");
}