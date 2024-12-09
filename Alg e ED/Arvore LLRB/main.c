#include <stdio.h>
#include "arvore_LLRB.h"

int main(){

    LLRBT *arvore = llrbt_criar();

    // Faz as inserções
    llrbt_inserir(arvore, 21);
    llrbt_inserir(arvore, 5);
    llrbt_inserir(arvore, 13);
    llrbt_inserir(arvore, 10);
    llrbt_inserir(arvore, 15);
    llrbt_inserir(arvore, 20);
    llrbt_inserir(arvore, 30);

    // Faz buscas
    int elem1 = 2, elem2 = 7;
    if(llrbt_busca(arvore, elem1) != -1) printf("Elemento %d existe na árvore\n", elem1);
    else printf("Elemento %d não existe na árvore\n", elem1);

    if(llrbt_busca(arvore, elem2) != -1) printf("Elemento %d existe na árvore\n", elem2);
    else printf("Elemento %d não existe na árvore\n", elem2);

    // Imprime os nós e seus filhos
    llrbt_imprime_filhos(arvore);

    // Imprime a árvore de diferentes maneiras
    printf("pre ordem:\n    ");
    llrbt_imprimir(arvore, "preordem");
    printf("pos ordem:\n    ");
    llrbt_imprimir(arvore, "posordem");
    printf("em ordem:\n    ");
    llrbt_imprimir(arvore, "emordem");

    // int x1 = 4;
    // if(llrbt_remover(arvore, x1)) printf("elemento de chave %d apagado com sucesso!\n", x1);
    // else printf("elemento de chave %d não apagado.\n", x1);
    // x1 = 2;
    // if(llrbt_remover(arvore, x1)) printf("elemento de chave %d apagado com sucesso!\n", x1);
    // else printf("elemento de chave %d não apagado.\n", x1);
    // llrbt_imprime_filhos(arvore);

    // Apaga a árvore
    llrbt_apagar(&arvore);
    if(arvore == NULL) printf("arvore apagada!\n");
}
/*

         4
       /   \
      2     5
     / \     \
    1   3     6
*/