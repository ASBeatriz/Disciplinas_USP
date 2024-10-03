// Exercício inserção ordenada - run codes
// OBS: Essa aplicação é considerando o fim apontando par o espaço vazio, diferente da implementação original no TAD lista_seq. 

#include "lista.h"

#ifndef STRUCTS_

#define STRUCTS_

struct lista_{ 

    ITEM *lista[TAM_MAX];

    int inicio; // pos do primeiro item

    int fim; // pos do próximo espaço vazio

    int tamanho;

};
typedef struct lista_ LISTA;

#endif

void deslocar_dir(LISTA *lista, int pos){ 
    for(int i = lista->fim; i>pos; i--){
        lista->lista[i] = lista->lista[i-1];
    }
}

bool lista_inserir(LISTA *lista, ITEM *item){
    if(lista != NULL && !lista_cheia(lista)){
        if(lista->tamanho == 0){
            lista->lista[lista->fim] = item;
            lista->tamanho++;
            lista->fim++;
            return true;
        }
        for(int i = lista->inicio; i < lista->fim; i++){
            if(item_get_chave(item) <= item_get_chave(lista->lista[i])){
                //deslocar para dir e inserir
                deslocar_dir(lista, i);
                lista->lista[i] = item;
                lista->fim++;
                lista->tamanho++;
                return true;
            }
        }
        // caso em que o item inserido é maior que todos
        lista->lista[lista->fim] = item;
        lista->tamanho++;
        lista->fim++;
        return true;
    }
    return false;
}