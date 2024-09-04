#include "item.h"

struct item_ {
    void *dado;
    int chave;  //indexador
};

ITEM *item_criar (int chave, void *dado){
    ITEM *item;
    item = (ITEM *)malloc(sizeof(ITEM));
    if(item != NULL){
        item->chave = chave;
        item->dado = dado;
        return item;
    }
    return NULL;
}

bool item_apagar (ITEM **item){
    if (*item != NULL){
        free(*item);
        *item = NULL;
        return true;
    }
    return false;
}

int item_get_chave (ITEM *item){
    if(item != NULL) return item->chave;
    exit(1);
}

bool item_set_chave (ITEM *item, int chave){
    if(item != NULL){
        item->chave = chave;
        return true;
    }
    else return false;
}

void *item_get_dados (ITEM *item){
    if(item != NULL) return item->dado;
    return NULL;
}