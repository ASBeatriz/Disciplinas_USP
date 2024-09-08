#ifndef FILA_H
#define FILA_H

#include "item.h"
#include <stdbool.h>
#define TAM_MAX 100

typedef struct Fila FILA;
FILA* fila_criar(void);
bool fila_inserir(FILA* fila, ITEM* item);
ITEM* fila_remover(FILA *fila);
int fila_tamanho(FILA *fila);
bool fila_cheia(FILA *fila);
bool fila_vazia(FILA *fila);

void fila_imprimirInt(FILA* fila); //criada para a main

#endif