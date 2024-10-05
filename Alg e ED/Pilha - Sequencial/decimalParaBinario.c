// Exercício - ultilizar pilha para converter um número decimal em binário
#include <stdio.h>
#include "pilha_seq.h"

int main(){
    PILHA_S *pilha = pilha_criar();

    int n;
    scanf("%d", &n);

    /*
    Ideia: vai dividindo o número por 2 e armazenando os restos. Exemplo:    
    divisão:     10 -> 5 -> 2 -> 1 -> 0
    restos:            0    1    0    1
    */
    while (n > 0){
        int resto = n%2;
        ITEM *item = item_criar(resto, NULL);

        pilha_empilhar(pilha, item);
        n /= 2;
    }

    // imprime a pilha do topo à base (ordem correta do número binário, inclusive)
    while(!pilha_vazia(pilha)){
        printf("%d ", item_get_chave(pilha_desempilhar(pilha)));
    }
}