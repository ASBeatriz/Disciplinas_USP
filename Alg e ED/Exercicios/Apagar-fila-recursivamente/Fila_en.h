//Fila encadeada

#ifndef FILA_EN_H
#define FILA_EN_H

#include "item.h"
#include <stdbool.h>
#define TAM_MAX 100

typedef struct No NO;
typedef struct Fila FILA;
FILA* fila_criar(void);
bool fila_inserir(FILA* fila, ITEM* item);
ITEM* fila_remover(FILA *fila);
int fila_tamanho(FILA *fila);
bool fila_cheia(FILA *fila);
bool fila_vazia(FILA *fila);
// void fila_apagar(FILA **fila);
void fila_apagar(FILA **f);

void fila_imprimirInt(FILA* fila); //criada para a main

#endif