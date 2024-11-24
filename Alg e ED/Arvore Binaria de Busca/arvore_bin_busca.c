#include "arvore_bin_busca.h"

struct no {
    ITEM *item;
    NO *esq;
    NO *dir;
    int filhos_total;
};

struct arvore_bin_busca {
    NO *raiz;
    int altura;
    // ...
};

// ----------------------------- FUNÇÕES AUXILIARES -------------------------------------

void apagar(NO **no){
    if((*no) != NULL){
        apagar(&((*no)->esq));
        apagar(&((*no)->dir));
        item_apagar(&((*no)->item));
        free(*no);
        *no = NULL;
    }
}

// int calc_profundidade(NO *no, int p){
//     if(no != NULL){
//         p++;
//         int p1 = calc_profundidade(no->esq, p);
//         int p2 = calc_profundidade(no->dir, p);
//         p = ((p1 > p2)? p1 : p2);
//     }
//     return p;
// }

// Código do professor
int calc_profundidade(NO *no) {
    if (no == NULL) return -1;
    int e = calc_profundidade(no->esq);
    int d = calc_profundidade(no->dir);
    return ((e > d) ? e : d) + 1;
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

ITEM *busca(NO *no, int chave){
    if(no == NULL) return NULL;
    if(chave == item_get_chave(no->item)) return no->item;
    else if(chave < item_get_chave(no->item))
        return busca(no->esq, chave);
    else if(chave > item_get_chave(no->item))
        return busca(no->dir, chave);
}

/* A função "atualiza" a cópia da árvore e depois retorna a raiz da árvore atualizada.
A raiz original, por sua vez, vai receber a raiz dessa cópia que foi atualizada */
NO *inserir_no(NO *raiz, NO* novo_no){
    if(raiz == NULL) 
        raiz = novo_no;
    else if(item_get_chave(raiz->item) > item_get_chave(novo_no->item)){
        raiz->filhos_total++;   // para verificar se é perfeitamente balanceada
        raiz->esq = inserir_no(raiz->esq, novo_no);
    }
    else if(item_get_chave(raiz->item) < item_get_chave(novo_no->item)){
        raiz->filhos_total++;
        raiz->dir = inserir_no(raiz->dir, novo_no);
    }

    return raiz;
}


// ------------------------------ FUNÇÕES PRINCIPAIS ---------------------------------

// Cria e inicializa a árvore
ABB *abb_criar(){
    ABB *arvore = (ABB*)malloc(sizeof(ABB));
    if(arvore != NULL){
        arvore->raiz = NULL;
        arvore->altura = -1;
        return arvore;
    }
}

// Função para inserir um nó na árvore
bool abb_inserir(ABB *arvore, ITEM *item){
    if(arvore == NULL) return false;

    NO *no = (NO*)malloc(sizeof(NO));
    if(no == NULL) return false;
    
    no->item = item;
    no->dir = NULL;
    no->esq = NULL;

    arvore->raiz = inserir_no(arvore->raiz, no);
    return true;
}

// Função para apagar a árvore
void abb_apagar(ABB **arvore) {
    apagar(&((*arvore)->raiz));
    free(*arvore); 
    *arvore = NULL;
}

ITEM *abb_busca(ABB *arvore, int chave){
    return busca(arvore->raiz, chave);
}

int abb_profundidade(ABB *arvore){
    // int p = -1;
    return calc_profundidade(arvore->raiz);
}

// Função para imprimir a árvore
void abb_imprimir(ABB *arvore, char str[]){
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
void abb_imprime_filhos(ABB *arvore){
    percorre(arvore->raiz);
}

// (FUNÇÕES FEITAS NA AULA)

// Função para substituir o elemento retirado pelo maior da subárvore esquerda
void troca_max_esq(NO *troca, NO* no_anterior, NO* raiz){
    if(troca->dir != NULL) troca_max_esq(troca->dir, troca, raiz);
    else{
        // muda o ponteiro do nó anterior ao que vai ser trocado
        if(raiz == no_anterior)
            no_anterior->esq = troca->esq;
        else
            no_anterior->dir = troca->esq;

        raiz->item = troca->item ;   // faz a troca
        free(troca);
        troca = NULL;
    }
}

bool remove_(NO** no, int chave){
    int chave_no = item_get_chave((*no)->item);

    if(*no == NULL) return false;   //caso não encontrar o nó
    else if(chave_no == chave){
        NO *aux = *no;

        // caso o nó seja folha ou tenha um só filho (se um dos filhos é nulo, aponta para o outro)
        if((*no)->esq == NULL){
            *no = (*no)->dir;
        }
        else if((*no)->dir == NULL){
            *no = (*no)->esq;
        }
        else{   // caso o nó tenha dois filhos
            troca_max_esq((*no)->esq, *no, *no);
            return true;
        }

        item_apagar(&((aux)->item));    //é assim que faz mesmo?
        free(aux);
        aux = NULL;
    }
    else if(chave_no > chave) return remove_(&((*no)->esq), chave);
    else return remove_(&((*no)->dir), chave);
}

bool abb_remover(ABB *arvore, int chave){
    if(arvore != NULL)
        return remove_(&(arvore->raiz), chave);
    
    return false;
}

// --------------------- Funções Exercícios RunCodes --------------------------

bool verifica_perfBalanceada(NO *no){
    if(no->dir == NULL || no->esq == NULL){
        // se um dos filhos não existir, o nó em questão só pode ter no máx 1 descendente
        return ((no->filhos_total > 1)? true : false);
    }
    int dif = no->dir->filhos_total - no->esq->filhos_total;
    if(dif < -1 || dif > 1) return true;
    else return (verifica_perfBalanceada(no->esq) || verifica_perfBalanceada(no->dir));
}

/*Essa função devolve 0 se a Árvore é perfeitamente balanceada e 1 caso contrário*/
bool abb_perfeitamente_balanceada(ABB *T){
    if(T->raiz == NULL) return false;
    return verifica_perfBalanceada(T->raiz);
}