#ifndef DEQUE_H
#define DEQUE_H

#include "item.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM_MAX 100

typedef struct deque_ DEQUE;
DEQUE* deque_criar();
void deque_apagar(DEQUE** deque);
bool deque_inserir_inicio(DEQUE* deque, ITEM* item);
bool deque_inserir_fim(DEQUE* deque, ITEM* item);
ITEM* deque_remover_inicio(DEQUE* deque);
ITEM* deque_remover_fim(DEQUE* deque);

//operações auxiliares
ITEM* deque_primeiro(DEQUE* deque);
ITEM* deque_ultimo(DEQUE* deque);
int deque_contar(DEQUE* deque);
bool deque_vazia(DEQUE* deque);
bool deque_cheia(DEQUE* deque);

void deque_imprimirInt(DEQUE *deque); //criada para a main

#endif