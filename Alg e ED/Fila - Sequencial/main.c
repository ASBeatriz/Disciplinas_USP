#include "Fila.h"
#include <stdio.h>

int main(){
    ITEM *it1, *it2, *it3;
    int val1 = 1, val2 = 2, val3 = 3;
    it1 = item_criar(0, &val1), it2 = item_criar(0, &val2), it3 = item_criar(0, &val3);  

    FILA *fila = fila_criar();
    fila_inserir(fila, it1);
    fila_inserir(fila, it2);
    fila_inserir(fila, it3);
    // 1 2 3

    fila_imprimirInt(fila);

    fila_remover(fila);  // 2 3
    fila_imprimirInt(fila);
    
    
    fila_remover(fila); // 3
    fila_inserir(fila, it1);  // 3 1
    fila_imprimirInt(fila);

    ITEM* removido = fila_remover(fila);
    printf("item removido: %d\n", *((int *)item_get_dados(removido)));
    fila_imprimirInt(fila);

    if(fila == NULL) printf ("Fila apagada\n");
    else printf("Fila nao apagada\n");
    
    fila_apagar(&fila);
    
    if(fila == NULL) printf ("Fila apagada\n");
    else printf("Fila nao apagada\n");
}