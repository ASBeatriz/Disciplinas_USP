#ifndef _PILHA_H
#define _PILHA_H

  #include "item.h"
  #include <stdbool.h>
  #include <stdio.h>

  #define TAM 1005

  typedef struct pilha PILHA;

  PILHA* pilha_criar(void);
  void pilha_apagar(PILHA** pilha);
  bool pilha_vazia(PILHA* pilha);
  bool pilha_cheia(PILHA* pilha);
  int pilha_tamanho(PILHA* pilha);
  ITEM* pilha_topo(PILHA* pilha);
  bool pilha_empilhar(PILHA* pilha, ITEM* item);
  ITEM* pilha_desempilhar(PILHA* pilha);
  bool balanceada(char *sequencia);

#endif 