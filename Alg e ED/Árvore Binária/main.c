#include <stdio.h>
#include "arvore_bin.h"

int main(){
    ITEM *it1, *it2, *it3, *it4,*it5, *it6;
    int val1 = 1, val2 = 2, val3 = 3, val4 = 4, val5 = 5,  val6 = 6;
    it1 = item_criar(10, &val1), it2 = item_criar(20, &val2), it3 = item_criar(30, &val3), it4 = item_criar(40, &val4), it5 = item_criar(50, &val5), it6 = item_criar(60, &val6);  

    AB *arvore = ab_criar();

    // Faz as inserções e testa se são válidas
    if(ab_inserir(arvore, it1, 0, 10)) printf("inserção feita com sucesso!\n");
    else printf("não foi possível fazer a inserção!\n");

    if(ab_inserir(arvore, it2, 0, 10)) printf("inserção feita com sucesso!\n");
    else printf("não foi possível fazer a inserção!\n");

    if(ab_inserir(arvore, it3, 1, 10)) printf("inserção feita com sucesso!\n");
    else printf("não foi possível fazer a inserção!\n");

    if(ab_inserir(arvore, it4, 0, 20)) printf("inserção feita com sucesso!\n");
    else printf("não foi possível fazer a inserção!\n");

    if(ab_inserir(arvore, it5, 1, 20)) printf("inserção feita com sucesso!\n");
    else printf("não foi possível fazer a inserção!\n");

    if(ab_inserir(arvore, it6, 1, 70)) printf("inserção feita com sucesso!\n");
    else printf("não foi possível fazer a inserção!\n");

    // Imprime os nós e seus filhos
    ab_imprime_filhos(arvore);

    // Imprime a árvore de diferentes maneiras
    printf("pre ordem:\n    ");
    ab_imprimir(arvore, "preordem");
    printf("pos ordem:\n    ");
    ab_imprimir(arvore, "posordem");
    printf("em ordem:\n    ");
    ab_imprimir(arvore, "emordem");

    // Imprime se é ou não estritamente binária
    if(ab_estritamente_binaria(arvore)) printf("Não é estritamente binaria!\n");
    else printf("eh estritamente binária!\n");
 
    // Imprime se é ou não árvore de busca
    if(!ab_checar_busca(arvore)) printf("Não é árvore de busca!\n");
    else printf("eh árvore de busca!\n");

    printf("profundidade: %d\n", ab_profundidade(arvore));

    // Apaga a árvore
    ab_apagar(&arvore);
    if(arvore == NULL) printf("arvore apagada!\n");
}
/*

         1
       /   \
      2     3
     / \     
    4   5     (6)
*/