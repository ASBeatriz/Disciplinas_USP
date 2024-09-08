#include "Deque.h"

struct deque_{
    ITEM* itens[TAM_MAX];
    int tamanho;
    int inicio;
    int fim;
};

DEQUE* deque_criar(){
    DEQUE* deque = (DEQUE*)malloc(sizeof(DEQUE));
    if(deque != NULL){
        deque->tamanho = 0;
        deque->inicio = 0;
        deque->fim = 0;
        return deque;
    }
    return NULL;
}

void deque_apagar(DEQUE** deque){

}

bool deque_inserir_inicio(DEQUE* deque, ITEM* item){
    if(!deque_cheia(deque) && deque != NULL){
        int novo_ini = deque->inicio - 1;
        if(novo_ini == -1) novo_ini = TAM_MAX - 1;

        deque->inicio = novo_ini; 
        deque->itens[deque->inicio] = item;
        deque->tamanho++;
        return true;
    }
    return false;
}

bool deque_inserir_fim(DEQUE* deque, ITEM* item){
    if(!deque_cheia(deque) && deque != NULL){
        deque->itens[deque->fim] = item;
        deque->fim = (deque->fim+1) % TAM_MAX;
        deque->tamanho++;
        return true;
    }
    return false;
}

ITEM* deque_remover_inicio(DEQUE* deque){
    if(!deque_vazia(deque) && deque != NULL){
        ITEM *removido = deque->itens[deque->inicio];
        deque->itens[deque->inicio] == NULL;
        deque->inicio = (deque->inicio + 1) % TAM_MAX;
        deque->tamanho--;
        return removido;
    }
    return NULL;
}

ITEM* deque_remover_fim(DEQUE* deque){
    if(!deque_vazia(deque) && deque != NULL){
        int novo_fim = deque->fim - 1;
        if(novo_fim == -1) novo_fim = TAM_MAX - 1;
        
        ITEM *removido = deque->itens[novo_fim];
        deque->itens[novo_fim] == NULL;
        
        deque->tamanho--;
        return removido;
    }
    return NULL;
}


//operações auxiliares
ITEM* deque_primeiro(DEQUE* deque){
    if(deque != NULL){
        return deque->itens[deque->inicio];
    }
    return NULL;
}

ITEM* deque_ultimo(DEQUE* deque){
    if(deque != NULL){
        return deque->itens[deque->fim];
    }
    return NULL;
}

int deque_contar(DEQUE* deque){
    if(deque != NULL){
        return deque->tamanho;
    }
    return -1;
}

bool deque_vazia(DEQUE* deque){
    if(deque != NULL){
        return deque->tamanho == 0;
    }
    return false;
}

bool deque_cheia(DEQUE* deque){
    if(deque != NULL){
        return deque->tamanho == TAM_MAX;
    }
    return false;
}


void deque_imprimirInt(DEQUE *deque){
    int tam = deque_contar(deque), ini = deque->inicio;
    for(int i=0; i<tam; i++){
        int *val = (int *)item_get_dados(deque->itens[ini]);
        printf("%d ", *val);
        ini = (ini+1)%TAM_MAX;
    }    
    printf("\n");
}