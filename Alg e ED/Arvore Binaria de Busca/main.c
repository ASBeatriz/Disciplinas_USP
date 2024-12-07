#include <stdio.h>
#include "arvore_bin_busca.h"

int main(){
    ITEM *it1, *it2, *it3, *it4,*it5, *it6;
    int val1 = 1, val2 = 2, val3 = 3, val4 = 4, val5 = 5,  val6 = 6;
    it1 = item_criar(10, &val1), it2 = item_criar(20, &val2), it3 = item_criar(30, &val3), it4 = item_criar(40, &val4), it5 = item_criar(50, &val5), it6 = item_criar(60, &val6);  

    ABB *arvore = abb_criar();

    // Faz as inserções
    abb_inserir(arvore, it4);
    abb_inserir(arvore, it2);
    abb_inserir(arvore, it1);
    abb_inserir(arvore, it3);
    abb_inserir(arvore, it5);
    abb_inserir(arvore, it6);

    // Faz buscas
    int elem1 = 20, elem2 = 70;
    if(abb_busca(arvore, elem1) != NULL) printf("Elemento %d existe na árvore\n", elem1);
    else printf("Elemento %d não existe na árvore\n", elem1);

    if(abb_busca(arvore, elem2) != NULL) printf("Elemento %d existe na árvore\n", elem2);
    else printf("Elemento %d não existe na árvore\n", elem2);

    // Imprime se a árvore é perfeitamente balanceada
    if(!abb_perfeitamente_balanceada(arvore)) printf("É perfeitamente balanceada!\n");
    else printf("Não é perfeitamente balanceada!\n");

    // Imprime os nós e seus filhos
    abb_imprime_filhos(arvore);

    // Imprime a árvore de diferentes maneiras
    printf("pre ordem:\n    ");
    abb_imprimir(arvore, "preordem");
    printf("pos ordem:\n    ");
    abb_imprimir(arvore, "posordem");
    printf("em ordem:\n    ");
    abb_imprimir(arvore, "emordem");

    int x1 = 40;
    if(abb_remover(arvore, x1)) printf("elemento de chave %d apagado com sucesso!\n", x1);
    else printf("elemento de chave %d não apagado.\n", x1);
    x1 = 20;
    if(abb_remover(arvore, x1)) printf("elemento de chave %d apagado com sucesso!\n", x1);
    else printf("elemento de chave %d não apagado.\n", x1);
    abb_imprime_filhos(arvore);

    // Apaga a árvore
    abb_apagar(&arvore);
    if(arvore == NULL) printf("arvore apagada!\n");
}
/*

         4
       /   \
      2     5
     / \     \
    1   3     6
*/