#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H
#include "item.h"
#include <string.h>

#define ERRO -32000
#define FILHO_ESQ 0
#define FILHO_DIR 1
// #define max(a,b) (a>b)? a : b

typedef struct no NO;
typedef struct arvore_avl AVL;

AVL *avl_criar();
bool avl_inserir(AVL *arvore, ITEM *item);
void avl_imprimir(AVL *arvore, char str[]);
void avl_apagar(AVL **arvore);
ITEM *avl_busca(AVL *arvore, int chave);
bool avl_remover(AVL *arvore, int chave);

// (Minha função)
void avl_imprime_filhos(AVL *arvore);

// Função Exercício RunCodes
bool avl_perfeitamente_balanceada(AVL *T);

#endif
