#ifndef ARVORE_BIN_H
#define ARVORE__BIN_H
#include "item.h"
#include <string.h>

#define ERRO -32000
#define FILHO_ESQ 0
#define FILHO_DIR 1

typedef struct no NO;
typedef struct arvore_bin AB;

AB *ab_criar();
bool ab_inserir(AB *arvore, ITEM *item, int lado, int chave_pai);
void ab_imprimir(AB *arvore, char str[]);
void ab_apagar(AB **arvore);

int ab_estritamente_binaria (AB *T); /*Essa função devolve 0
se a Árvore é estritamente binária e 1 caso contrário*/

// (Minha função)
void ab_imprime_filhos(AB *arvore);

#endif
