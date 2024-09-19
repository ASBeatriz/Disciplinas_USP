#include "Lista_seq.h"

//separar e modularaizar melhor as operações de lista ordenada/não ordenada

struct lista{
    ITEM *itens[TAM_MAX];
    int inicio;
    int fim;
    int tamanho;
    bool ordenada;
};

LISTA *lista_criar(bool ordenada){
    LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
    if(lista != NULL){
        lista->inicio = 0;
        lista->fim = 0;
        lista->tamanho = 0;
        lista->ordenada = ordenada;
    }
    return lista;
}

bool inserir_nao_ordenado(LISTA *lista, ITEM *item){
    if(lista != NULL && !lista_cheia(lista)){
        if(lista->tamanho != 0) lista->fim++;

        lista->itens[lista->fim] = item;
        lista->tamanho++;
        return true;
    }
    return false;
}

//desloca parte da lista para a direita
void deslocar_dir(LISTA *lista, int pos){ 
    //if(pos != lista->fim){  //só desloco se houver elementos após a posiçaõ indicada
        for(int i = lista->fim+1; i>pos; i--){
            lista->itens[i] = lista->itens[i-1];
        }
    //}
}

bool inserir_ordenado(LISTA *lista, ITEM *item){ //ordenado por chave
    if(lista != NULL && !lista_cheia(lista)){
        if(lista->tamanho == 0){
            lista->itens[lista->fim] = item;
            lista->tamanho++;
            return true;
        }
        for(int i = lista->inicio; i <= lista->fim; i++){
            if(item_get_chave(item) <= item_get_chave(lista->itens[i])){
                //deslocar para dir e inserir
                deslocar_dir(lista, i);
                lista->itens[i] = item;
                lista->fim++;
                lista->tamanho++;
                return true;
            }
        }
        // caso em que o item inserido é maior que todos
        lista->fim++;
        lista->itens[lista->fim] = item;
        lista->tamanho++;
        return true;
    }
    return false;
}

bool lista_inserir(LISTA *lista, ITEM *item){
    return (lista->ordenada ? inserir_ordenado(lista, item) : inserir_nao_ordenado(lista, item));
}

//desloca parte da lista para a esquerda
void deslocar_esq(LISTA *lista, int pos){ 
    if(pos != lista->fim){ //só desloco se houver elementos após a posição indicada
        for(int i=pos; i<lista->fim; i++){
            // cada posição recebe o item da próxima (exceto pela posição final, que passa a ser nulo)
            if(i == lista->fim){
                lista->itens[i] = NULL;
                break;
            }
            lista->itens[i] = lista->itens[i+1];
        }
    }
}

ITEM *lista_remover(LISTA *lista, int chave){ //remover do fim (mudar para remover com uma chave e retornar o item)
    if(lista != NULL && !lista_vazia(lista)){
        int pos = lista->inicio;

        // percorre a lista procurando a chave correspondente
        for(int i=0; i<lista->tamanho; i++){
            if(item_get_chave(lista->itens[pos]) == chave){
                ITEM *removido = lista->itens[pos];
                deslocar_esq(lista, pos);
                lista->tamanho--;
                lista->fim--;
                return removido;
            }
            pos++;
        }
    }
    return NULL;
}

ITEM *lista_busca(LISTA *lista, int chave){
    if(lista != NULL){
        int pos = lista->inicio;
        for(int i=0; i<lista->tamanho; i++){
            if(item_get_chave(lista->itens[pos]) == chave){
                return lista->itens[pos];
            }
            pos++;
        }
    }
    return NULL;
}

bool lista_apagar(LISTA **lista){ 
    if(*lista == NULL) return true;

    while((*lista)->tamanho != 0){
        ITEM *removido = lista_remover(*lista, item_get_chave((*lista)->itens[(*lista)->fim]));
        item_apagar(&removido);
    }
    free(*lista);
    *lista = NULL;
}

bool lista_cheia(LISTA *lista){
    if(lista != NULL){
        return (lista->tamanho == TAM_MAX);
    }
    return true;
}

bool lista_vazia(LISTA *lista){
    if(lista != NULL){
        return (lista->tamanho == 0);
    }
    return false;
}

int lista_tamanho(LISTA *lista){
    if(lista != NULL){
        return lista->tamanho;
    }
    return ERRO;
}

void lista_imprimir(LISTA* lista){
    if(lista != NULL){
        if(lista_vazia(lista)) printf("lista vazia!\n");
        else{
            int pos = lista->inicio;
            for(int i=0; i<lista->tamanho; i++){
                int val = *(int *)item_get_dados(lista->itens[pos]);
                printf("%d ", val);
                pos++;
            }
            printf("\n");
        }
    }
}

