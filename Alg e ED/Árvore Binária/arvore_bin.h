#ifndef ARVORE_BIN_H
#define ARVORE_BIN_H
#include "item.h"
#include <string.h>

#define ERRO -32000
#define FILHO_ESQ 0
#define FILHO_DIR 1
#define INT_MAX 1e8
#define INT_MIN -1e8

typedef struct no NO;
typedef struct arvore_bin AB;

AB *ab_criar();
bool ab_inserir(AB *arvore, ITEM *item, int lado, int chave_pai);
void ab_imprimir(AB *arvore, char str[]);
void ab_apagar(AB **arvore);
int ab_profundidade(AB *arvore);

// Funções de Exercícios RunCodes
int ab_estritamente_binaria (AB *T); /*Essa função devolve 0 e a Árvore é estritamente binária e 1 caso contrário*/
int ab_checar_busca (AB *T); // Essa função devolve 0 se a árvore é de busca e 1 caso contrário

// (Minha função)
void ab_imprime_filhos(AB *arvore);

#endif
