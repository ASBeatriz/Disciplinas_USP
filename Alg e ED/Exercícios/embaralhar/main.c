#include "Deque.h"
#include <stdio.h>

int main(){
    //CASO DE TESTE

    ITEM *it1, *it2, *it3, *it4, *it5, *it6;
    int val1 = 1, val2 = 2, val3 = 3, val4 = 4, val5 = 5, val6 = 6;
    it1 = item_criar(0, &val1), it2 = item_criar(0, &val2), it3 = item_criar(0, &val3), it4 = item_criar(0, &val4), it5 = item_criar(0, &val5), it6 = item_criar(0, &val6);  

    DEQUE *deque1 = deque_criar();
    deque_inserir_fim(deque1, it1);
    deque_inserir_fim(deque1, it2);
    deque_inserir_fim(deque1, it3);
    deque_inserir_fim(deque1, it4);
    deque_inserir_fim(deque1, it5);
    deque_inserir_fim(deque1, it6);

    DEQUE *deque2 = deque_criar();
    deque_inserir_fim(deque2, it1);
    deque_inserir_fim(deque2, it2);
    deque_inserir_fim(deque2, it3);
    deque_inserir_fim(deque2, it4);
    deque_inserir_fim(deque2, it5);
    deque_inserir_fim(deque2, it6);

    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int orig;
        char pos_orig[7], pos_dest[7];
        scanf("%d %s %s", &orig, pos_orig, pos_dest);

        DEQUE *aux_orig = (orig == 1 ? deque1 : deque2);
        DEQUE *aux_dest = (orig == 1 ? deque2 : deque1);
        ITEM *item = (pos_orig[0] == 'i' ? deque_remover_inicio(aux_orig) : deque_remover_fim(aux_orig));  
        pos_dest[0] == 'i' ? deque_inserir_inicio(aux_dest, item) : deque_inserir_fim(aux_dest, item); 
    
        deque_imprimirInt(deque1);
        deque_imprimirInt(deque2);
    }
}