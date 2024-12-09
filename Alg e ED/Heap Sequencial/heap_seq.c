#include "heap_seq.h"

struct heap_seq {
    ITEM *vetor[TAM];
    int fim;
};

// Faz a troca entre dos itens da heap
void swap(HEAP_SEQ *heap, int pos1, int pos2){
    ITEM *temp = heap->vetor[pos1];
    heap->vetor[pos1] = heap->vetor[pos2];
    heap->vetor[pos2] = temp;
}

void fix_up(HEAP_SEQ *heap){
    int ultimo = item_get_chave(heap->vetor[heap->fim]);
    int pos_ultimo = heap->fim;
    int pos_pai = (heap->fim-1)/2;

    while(pos_pai >= 0 && ultimo > item_get_chave(heap->vetor[pos_pai])){
        swap(heap, pos_pai, pos_ultimo);
        pos_ultimo = pos_pai;
        pos_pai = (pos_ultimo - 1)/2;    
    }
}   

void fix_down(HEAP_SEQ *heap){
    int pos_primeiro = 0;
    int pos_fesq = 1;
    int pos_fdir = 2;

    while(pos_fesq <= heap->fim || pos_fdir <= heap->fim){
        ITEM *maior;
        int maior_pos;
        int val_primeiro = item_get_chave(heap->vetor[pos_primeiro]);

        if(pos_fesq > heap->fim){
            maior = heap->vetor[pos_fdir];
            maior_pos = pos_fdir;
        }
        else if(pos_fdir > heap->fim){
            maior = heap->vetor[pos_fesq];
            maior_pos = pos_fesq;
        }
        else if(item_get_chave(heap->vetor[pos_fdir]) > item_get_chave(heap->vetor[pos_fesq])){
            maior = heap->vetor[pos_fdir];
            maior_pos = pos_fdir;
        }
        else{
            maior = heap->vetor[pos_fesq];
            maior_pos = pos_fesq;
        }

        if(val_primeiro > item_get_chave(maior)) break;

        swap(heap, pos_primeiro, maior_pos);
        pos_primeiro = maior_pos;
        pos_fesq = 2*pos_primeiro + 1;
        pos_fdir = 2*pos_primeiro + 2;
    }
}

HEAP_SEQ *heap_criar(){
    HEAP_SEQ *heap = (HEAP_SEQ*)malloc(sizeof(HEAP_SEQ));
    if (heap != NULL){
        heap->fim = -1;
    }
    return heap;
}

bool heap_cheia(HEAP_SEQ *heap){
    if(heap == NULL) return true;
    return (heap->fim == TAM-1);
}

bool heap_vazia(HEAP_SEQ *heap){
    if (heap == NULL) return true; 
    return (heap->fim == -1);
}

bool heap_enfileirar(HEAP_SEQ *heap, ITEM *item){
    if(heap != NULL){
        if(!heap_cheia(heap)){
            heap->fim++;
            heap->vetor[heap->fim] = item;
            fix_up(heap);
            heap_imprimir(heap);
            return true;
        }
    }
    return false;
}

ITEM *heap_remover(HEAP_SEQ *heap){
    ITEM *removido = NULL;
    if(heap != NULL){
        if(!heap_vazia(heap)){
            // guarda o item removido
            removido = heap->vetor[0];
            
            // troca com o último item
            heap->vetor[0] = heap->vetor[heap->fim];
            heap->vetor[heap->fim] = NULL;
            heap->fim--;

            // conserta a ordem da heap
            fix_down(heap);
        }
    }
    return removido;
}

void heap_imprimir(HEAP_SEQ* heap){
    if(heap != NULL){
        if(heap_vazia(heap)) printf("heap vazia!\n");
        else{
            int pos = 0;
            while(pos <= heap->fim){
                int val = item_get_chave(heap->vetor[pos]);
                printf("%d ", val);
                pos++;
            }
            printf("\n");
        }
    }
}

void heap_apagar(HEAP_SEQ **heap){
    if((*heap) != NULL){
        for(int pos = 0; pos <= (*heap)->fim; pos++){
            item_apagar(&((*heap)->vetor[pos]));
        }
        free(*heap);
        *heap = NULL;
    }
}