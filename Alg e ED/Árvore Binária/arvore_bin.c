#include "arvore_bin.h"

struct no {
    ITEM *item;
    NO *esq;
    NO *dir;
    //int profundidade;
};

struct arvore_bin {
    NO *raiz;
    int altura;
    // ...
};

// ----------------------------- FUNÇÕES AUXILIARES -------------------------------------

// Procura o nó com a chave correspondente e retorna ele. Caso não ache, retorna NULL;
NO *busca_no(NO* no_atual, int chave_pai){
    
    if(no_atual != NULL){
        if(item_get_chave(no_atual->item) == chave_pai) return no_atual;
        NO *n1 = busca_no(no_atual->esq, chave_pai);
        NO *n2 = busca_no(no_atual->dir, chave_pai);
        if(n1 != NULL)return n1;
        else if(n2 != NULL)return n2;
    }
    return NULL;
}

void apagar(NO **no){
    if((*no) != NULL){
        apagar(&((*no)->esq));
        apagar(&((*no)->dir));
        free(*no);
        *no = NULL;
    }
}

int verifica_estritamente_bin(NO *no){
    if (no->dir == NULL && no->esq == NULL ) return 0;
    else if(no->dir != NULL && no->esq != NULL){
        return (verifica_estritamente_bin(no->esq) || verifica_estritamente_bin(no->dir));
    }
    else return 1;
}

void imprime_preordem(NO *raiz){
    if(raiz != NULL){
        printf("%d ", *(int*)item_get_dados(raiz->item));
        imprime_preordem(raiz->esq);
        imprime_preordem(raiz->dir);
    }
}

void imprime_emordem(NO *raiz){
    if(raiz != NULL){
        imprime_emordem(raiz->esq);
        printf("%d ", *(int*)item_get_dados(raiz->item));
        imprime_emordem(raiz->dir);
    }
}
void imprime_posordem(NO *raiz){
    if(raiz != NULL){
        imprime_posordem(raiz->esq);
        imprime_posordem(raiz->dir);
        printf("%d ", *(int*)item_get_dados(raiz->item));
    }
}

void percorre (NO *no){
    if(no != NULL){
        printf("no: %d ", *(int*)item_get_dados(no->item));
        printf("\nfilhos:");
        if(no->esq != NULL){
            printf(" %d", *(int*)item_get_dados(no->esq->item));
        }   
        if(no->dir != NULL){
            printf(" %d", *(int*)item_get_dados(no->dir->item));
        }
        printf("\n");
        percorre(no->esq);
        percorre(no->dir);
    }
}

// ------------------------------ FUNÇÕES PRINCIPAIS ---------------------------------

// Cria e inicializa a árvore
AB *ab_criar(){
    AB *arvore = (AB*)malloc(sizeof(AB));
    if(arvore != NULL){
        arvore->raiz = NULL;
        arvore->altura = -1;
        return arvore;
    }
}

// Função para inserir um nó na árvore
bool ab_inserir(AB *arvore, ITEM *item, int lado, int chave_pai){
    NO *no = (NO*)malloc(sizeof(NO));
    if(arvore == NULL || no == NULL) return false;
    no->item = item;
    no->dir = NULL;
    no->esq = NULL;

    if(arvore->altura == -1){ //primeiro nó
        arvore->raiz = no;
        arvore->altura++;
    }
    else{
        NO *no_pai = busca_no(arvore->raiz, chave_pai);
        if(no_pai == NULL){    //verifica se a chave não é válida
            free(no);
            return false;
        }

        if(lado == FILHO_ESQ) no_pai->esq = no;
        else no_pai->dir = no; 
    }
    return true;
}

// Função para apagar a árvore
void ab_apagar(AB **arvore) {
    apagar(&((*arvore)->raiz));
    free(*arvore); 
    *arvore = NULL;
}

/*Essa função devolve 0 se a Árvore é estritamente binária e 1 caso contrário*/
int ab_estritamente_binaria (AB *arvore){
  if(arvore->raiz == NULL) return 0;
  else return verifica_estritamente_bin(arvore->raiz);
}

// Função para imprimir a árvore
void ab_imprimir(AB *arvore, char str[]){
    if(strcmp(str, "preordem") == 0){
        imprime_preordem(arvore->raiz);
        printf("\n");
    }
    else if(strcmp(str, "emordem") == 0){
        imprime_emordem(arvore->raiz);
        printf("\n");
    }
    else if(strcmp(str, "posordem") == 0){
        imprime_posordem(arvore->raiz);
        printf("\n");
    }
}

// Função para imprimir cada nó e indicar seus filhos
void ab_imprime_filhos(AB *arvore){
    percorre(arvore->raiz);
}