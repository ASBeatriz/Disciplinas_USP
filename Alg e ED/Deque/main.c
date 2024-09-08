#include "Deque.h"
#include <stdio.h>

int main(){
    ITEM *it1, *it2, *it3;
    int val1 = 1, val2 = 2, val3 = 3;
    it1 = item_criar(0, &val1), it2 = item_criar(0, &val2), it3 = item_criar(0, &val3);  

    DEQUE *deque = deque_criar();
    deque_inserir_fim(deque, it1);
    deque_inserir_fim(deque, it2);
    deque_inserir_inicio(deque, it3);
    deque_inserir_inicio(deque, it1);
    deque_imprimirInt(deque);

    ITEM* removido = deque_remover_inicio(deque);
    printf("item removido: %d\n", *((int *)item_get_dados(removido)));
    deque_imprimirInt(deque);

    removido = deque_remover_fim(deque);
    printf("item removido: %d\n", *((int *)item_get_dados(removido)));
    deque_imprimirInt(deque);
}