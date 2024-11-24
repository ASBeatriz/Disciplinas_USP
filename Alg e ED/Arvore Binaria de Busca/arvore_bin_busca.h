#ifndef ARVORE_BIN_BUSCA_H
#define ARVORE_BIN_BUSCA_H
#include "item.h"
#include <string.h>

#define ERRO -32000
#define FILHO_ESQ 0
#define FILHO_DIR 1

typedef struct no NO;
typedef struct arvore_bin_busca ABB;

ABB *abb_criar();
bool abb_inserir(ABB *arvore, ITEM *item);
void abb_imprimir(ABB *arvore, char str[]);
void abb_apagar(ABB **arvore);
ITEM *abb_busca(ABB *arvore, int chave);
bool abb_remover(ABB *arvore, int chave);

// (Minha função)
void abb_imprime_filhos(ABB *arvore);

// Função Exercício RunCodes
bool abb_perfeitamente_balanceada(ABB *T);

#endif
