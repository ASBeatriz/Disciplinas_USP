// Heap Sequencial
#ifndef HEAP_SEQ_H
#define HEAP_SEQ_H
#include "item.h"

#define TAM 100     // tam máximo da heap
typedef struct heap_seq HEAP_SEQ;

HEAP_SEQ *heap_criar();
bool heap_cheia(HEAP_SEQ *heap);
bool heap_vazia(HEAP_SEQ *heap);
bool heap_enfileirar(HEAP_SEQ *heap, ITEM *item);
ITEM *heap_remover(HEAP_SEQ *heap);
void heap_imprimir(HEAP_SEQ* heap);
void heap_apagar(HEAP_SEQ** heap);

#endif