#include "Lista_enc.h"

struct no{
    ITEM *item;
    NO *prox;
};

struct lista{
    NO* inicio;
    NO* fim;
    int tamanho;
    bool ordenada;
};

LISTA *lista_criar(bool ordenada){
    LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
    if(lista != NULL){
        lista->fim = NULL;
        lista->inicio = NULL;
        lista->tamanho = 0;
        lista->ordenada = ordenada;
    }
    return lista;
}

bool inserir_nao_ordenado(LISTA *lista, ITEM *item){
    if(lista != NULL && !lista_cheia(lista)){
        NO* novoNO = (NO*)malloc(sizeof(NO));
        if(novoNO != NULL){
            novoNO->prox = NULL;
            novoNO->item = item;

            //se for o primeiro da lista
            if(lista->tamanho == 0) lista->inicio = novoNO;
            else{
                // antes de mudar o fim, defino o campo "prox" do fim atual
                lista->fim->prox = novoNO;
            }
            lista->fim = novoNO;
            lista->tamanho++;
            return true;
        }
    }
    return false;
}

bool inserir_ordenado(LISTA *lista, ITEM *item){ //ordenado por chave
    if(lista != NULL && !lista_cheia(lista)){
        NO * novoNO = (NO*)malloc(sizeof(NO));
        novoNO->item = item;
        int chave = item_get_chave(item);

        //nó é o primeiro
        if(lista->inicio == NULL){  
            novoNO->prox = NULL;
            lista->inicio = novoNO;
            lista->fim = novoNO;
            lista->tamanho++;
            return true;
        }
        
        NO *ant = NULL;
        NO *atual = lista->inicio;

        while(atual != NULL){
            if(item_get_chave(atual->item) >= chave){
                if(ant == NULL){    // nó inserido no inicio
                    lista->inicio = novoNO;
                }
                else{   //nó inserido no meio
                    ant->prox = novoNO;
                }
                novoNO->prox = atual;
                lista->tamanho++;
                return true;
            }
            ant = atual;
            atual = atual->prox;
        }

        // nó inserido no fim
        lista->fim->prox = novoNO;
        lista->fim = novoNO;
        lista->tamanho++;
        return true;

    }
    return false;
}

bool lista_inserir(LISTA *lista, ITEM *item){
    return (lista->ordenada ? inserir_ordenado(lista, item) : inserir_nao_ordenado(lista, item));
}


ITEM *lista_remover(LISTA *lista, int chave){ 
    if(lista != NULL && !lista_vazia(lista)){
        ITEM *removido;
        NO* noBusca = lista->inicio;

        //remoção no inicio
        int chaveBusca = item_get_chave(noBusca->item);
        if(chaveBusca == chave){
            NO* aux = noBusca;
            removido = noBusca->item;
            lista->inicio = noBusca->prox;
            free(aux);
            aux = NULL;
            lista->tamanho--;
            return removido;
        }
        for(int i=0; i<(lista->tamanho - 1); i++){
            int proxChaveBusca = item_get_chave(noBusca->prox->item);
            // remoção no meio ou fim (?)
            if(proxChaveBusca == chave){
                NO *aux = noBusca->prox;
                noBusca->prox = noBusca->prox->prox;
                removido = aux->item;
                free(aux);
                aux = NULL;
                lista->tamanho--;
                return removido;
            }
            noBusca = noBusca->prox;
        }
    }
}

ITEM *lista_busca(LISTA *lista, int chave){
    if(lista != NULL){
        NO *aux = lista->inicio;
        for(int i=0; i<lista->tamanho; i++){
            if(item_get_chave(aux->item) == chave){
                printf("item encontrado: %d\n", item_get_chave(aux->item)); // debug
                return aux->item;
            }
            aux = aux->prox;
        }
        printf("item nao encontrado\n");    // debug
    }
    return NULL;
}

// implementação recursiva de lista_busca (correta?)
ITEM *busca_recursivo(LISTA *lista, NO* no, int chave){
    if(item_get_chave(no->item) == chave){
        printf("item encontrado: %d\n", item_get_chave(no->item)); // debug
        return no->item;
    }
    if(no == lista->fim){
        printf("item nao encontrado\n");
        return NULL;
    }
    return busca_recursivo(lista, no->prox, chave);
}

ITEM *lista_busca_recursivo(LISTA *lista, int chave){
    return busca_recursivo(lista, lista->inicio, chave);
}

bool lista_apagar(LISTA **lista){ 
    if(*lista == NULL) return true;

    while((*lista)->inicio != NULL){
        // forma 1:
        //ITEM* itRemover = lista_remover(*lista, item_get_chave((*lista)->inicio->item));
        //item_apagar(&itRemover);

        //forma 2 (sem função:
        NO* aux = (*lista)->inicio;                     //ponteiro auxiliar aponta para o nó a ser removido (inicio da lista)
        ITEM *itRemovido = aux->item;   
        item_apagar(&itRemovido);                       //apaga (desaloca) item do nó
        (*lista)->inicio = (*lista)->inicio->prox;      //muda o inicio da lista
        free(aux);                                      //desaloca o antigo inicio da lista
        aux = NULL;
    }
    free(*lista);
    *lista = NULL;
}

bool lista_cheia(LISTA *lista){
    if(lista != NULL){
        NO *no = (NO*)malloc(sizeof(NO));
        if(no != NULL){
            free(no);
            no = NULL;
            return false;
        }
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
            NO* no = lista->inicio;
            for(int i=0; i<lista->tamanho; i++){
                int val = *(int *)item_get_dados(no->item);
                printf("%d ", val);
                no = no->prox;
            }
            printf("\n");
        }
    }
}

