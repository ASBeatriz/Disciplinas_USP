// Left-Leaning Red-Black Tree (Árvore Rubro-Negra versão LLRB)

#ifndef ARVORE_LLRB_H
#define ARVORE_LLRB_H
#include "item.h"
#include <string.h>

#define ERRO -32000
#define FILHO_ESQ 0
#define FILHO_DIR 1

typedef struct no NO;
typedef struct arvore_LLRB LLRBT;

LLRBT *llrbt_criar();
bool llrbt_inserir(LLRBT *arvore, int item);
void llrbt_imprimir(LLRBT *arvore, char str[]);
void llrbt_apagar(LLRBT **arvore);
int llrbt_busca(LLRBT *arvore, int chave);
bool llrbt_remover(LLRBT *arvore, int chave);

// (Minha função)
void llrbt_imprime_filhos(LLRBT *arvore);
#endif
