#include <stdio.h>
#include "arvore_avl.h"

int main(){
    ITEM *it10, *it7, *it20, *it15,*it17, *it6;
    int val10 = 10, val7 = 7, val20 = 20, val15 = 15, val17 = 17,  val6 = 6;
    it10 = item_criar(10, &val10), it7 = item_criar(7, &val7), it20 = item_criar(20, &val20), it15 = item_criar(15, &val15), it17 = item_criar(17, &val17), it6 = item_criar(60, &val6);  

    AVL *arvore = avl_criar();

    // Faz as inserções
    avl_inserir(arvore, it10);
    avl_inserir(arvore, it7);
    avl_inserir(arvore, it20);
    avl_inserir(arvore, it15);
    avl_inserir(arvore, it17);
    // avl_inserir(arvore, it6/);

    // Faz buscas
    int elem1 = 20, elem2 = 70;
    if(avl_busca(arvore, elem1) != NULL) printf("Elemento %d existe na árvore\n", elem1);
    else printf("Elemento %d não existe na árvore\n", elem1);

    if(avl_busca(arvore, elem2) != NULL) printf("Elemento %d existe na árvore\n", elem2);
    else printf("Elemento %d não existe na árvore\n", elem2);

    // // Imprime se a árvore é perfeitamente balanceada
    // if(!avl_perfeitamente_balanceada(arvore)) printf("É perfeitamente balanceada!\n");
    // else printf("Não é perfeitamente balanceada!\n");

    // Imprime os nós e seus filhos
    avl_imprime_filhos(arvore);

    // Imprime a árvore de diferentes maneiras
    // printf("pre ordem:\n    ");
    // avl_imprimir(arvore, "preordem");
    // printf("pos ordem:\n    ");
    // avl_imprimir(arvore, "posordem");
    printf("em ordem:\n    ");
    avl_imprimir(arvore, "emordem");

    int x1 = 40;
    if(avl_remover(arvore, x1)) printf("elemento de chave %d apagado com sucesso!\n", x1);
    else printf("elemento de chave %d não apagado.\n", x1);
    x1 = 10;
    if(avl_remover(arvore, x1)) printf("elemento de chave %d apagado com sucesso!\n", x1);
    else printf("elemento de chave %d não apagado.\n", x1);
    avl_imprime_filhos(arvore);

    // Apaga a árvore
    avl_apagar(&arvore);
    if(arvore == NULL) printf("arvore apagada!\n");
}
/* AVL:
         10
       /   \
      7    17
          /  \
        15    20
*/