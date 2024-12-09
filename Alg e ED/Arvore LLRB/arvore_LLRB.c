#include "arvore_LLRB.h"

struct no {
    int info;   // Por algum motivo, o prof n usou TAD item (amém)
    int cor;    // 0 = preto, 1 = vermelho
    NO *esq;
    NO *dir;
};

struct arvore_LLRB {
    NO *raiz;
    // ...
};

// ----------------------------- FUNÇÕES AUXILIARES -------------------------------------

void apagar(NO **no){
    if((*no) != NULL){
        apagar(&((*no)->esq));
        apagar(&((*no)->dir));
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
        printf("%d, ", raiz->info);
        imprime_preordem(raiz->esq);
        imprime_preordem(raiz->dir);
    }
}

void imprime_emordem(NO *raiz){
    if(raiz != NULL){
        imprime_emordem(raiz->esq);
        printf("%d, ", raiz->info);
        imprime_emordem(raiz->dir);
    }
}
void imprime_posordem(NO *raiz){
    if(raiz != NULL){
        imprime_posordem(raiz->esq);
        imprime_posordem(raiz->dir);
        printf("%d, ", raiz->info);
    }
}

void percorre (NO *no){
    if(no != NULL){
        printf("no: %d (cor: %d)", no->info, no->cor);
        printf("\nfilhos:");
        if(no->esq != NULL){
            printf(" %d", no->esq->info);
        }   
        if(no->dir != NULL){
            printf(" %d", no->dir->info);
        }
        printf("\n");
        percorre(no->esq);
        percorre(no->dir);
    }
}

int busca(NO *no, int chave){
    if(no == NULL) return -1;
    if(chave == no->info) return no->info;
    else if(chave < no->info)
        return busca(no->esq, chave);
    else if(chave > no->info)
        return busca(no->dir, chave);
}

NO *rodar_direita(NO *c){
    NO *b = c->esq;

    // Faz a rotação
    c->esq = b->dir;
    b->dir = c;

    // Ajusta as cores
    b->cor = c->cor;
    c->cor = 1;

    return b;
}

NO *rodar_esquerda(NO *a){
    NO *b = a->dir;

    // Faz a rotação
    a->dir = b->esq;
    b->esq = a;

    // Ajusta as cores
    b->cor = a->cor;
    a->cor = 1;

    return b;
}

int vermelho(NO* no){
    if(no == NULL) return 0;
    else return no->cor;
}

// Inverte as cores
void inverte(NO *no){
    if(no != NULL){
        no->cor = !(no->cor);
        if(no->esq != NULL)
            no->esq->cor = !(no->esq->cor);

        if(no->dir != NULL)
            no->dir->cor = !(no->dir->cor);
    }
}

/* A função "atualiza" a cópia da árvore e depois retorna a raiz da árvore atualizada.
A raiz original, por sua vez, vai receber a raiz dessa cópia que foi atualizada */
NO *inserir_no(NO *raiz, NO* novo_no){
    if(raiz == NULL) 
        return novo_no;
    else if((raiz->info) > (novo_no->info)){
        raiz->esq = inserir_no(raiz->esq, novo_no);
    }
    else if((raiz->info) < (novo_no->info)){
        raiz->dir = inserir_no(raiz->dir, novo_no);
    }

    // Verifica necessidade de reajuste
    if(!vermelho(raiz->esq) && vermelho(raiz->dir)){
        raiz = rodar_esquerda(raiz);
    }
    if(vermelho(raiz->esq) && vermelho(raiz->esq->esq)){
        raiz = rodar_direita(raiz);
    }
    if(vermelho(raiz->esq) && vermelho(raiz->dir)){
        inverte(raiz);
    }

    return raiz;
}

// Função para substituir o elemento retirado pelo maior da subárvore esquerda
void troca_max_esq(NO *troca, NO* no_anterior, NO   * raiz){
    if(troca->dir != NULL) troca_max_esq(troca->dir, troca, raiz);
    else{
        if(raiz == no_anterior)
            no_anterior->esq = troca->esq;
        else
            no_anterior->dir = troca->esq;

        raiz->info = troca->info ;   // faz a troca
        // Desaloca o nó
        free(troca);
        troca = NULL;
    }
}

// Não sei como fazer a remoção, esse é o da AVL !!!!!
bool remove_(NO** no, int chave){
    bool removido;
    if(*no == NULL){
        return false;   //caso não encontrar o nó
    }
    else{
        int chave_no = (*no)->info;
        if(chave_no == chave){

            if((*no)->esq == NULL || (*no)->dir == NULL){
                NO *aux = *no;
                if((*no)->esq == NULL){
                    *no = (*no)->dir;
                }
                else if((*no)->dir == NULL){
                    *no = (*no)->esq;
                }
                free(aux);
                aux = NULL;
            }
            else{
                troca_max_esq((*no)->esq, *no, *no);
            }
            removido = true;
        }
        else if(chave_no > chave) removido = remove_(&((*no)->esq), chave);
        else if(chave_no < chave) removido = remove_(&((*no)->dir), chave);
    }

    if (removido == false) return false;

    return true;
}

// ------------------------------ FUNÇÕES PRINCIPAIS ---------------------------------

// Cria e inicializa a árvore
LLRBT *llrbt_criar(){
    LLRBT *arvore = (LLRBT*)malloc(sizeof(LLRBT));
    if(arvore != NULL){
        arvore->raiz = NULL;
    }
    return arvore;
}

// Função para inserir um nó na árvore
bool llrbt_inserir(LLRBT *arvore, int item){
    if(arvore == NULL) return false;

    NO *no = (NO*)malloc(sizeof(NO));
    if(no == NULL) return false;
    
    no->info = item;
    no->dir = NULL;
    no->esq = NULL;
    no->cor = 1;

    arvore->raiz = inserir_no(arvore->raiz, no);
    return true;
}

// Função para apagar a árvore
void llrbt_apagar(LLRBT **arvore) {
    apagar(&((*arvore)->raiz));
    free(*arvore); 
    *arvore = NULL;
}

int llrbt_busca(LLRBT *arvore, int chave){
    return busca(arvore->raiz, chave);
}

int llrbt_profundidade(LLRBT *arvore){
    // int p = -1;
    return calc_profundidade(arvore->raiz);
}

// Função para imprimir a árvore
void llrbt_imprimir(LLRBT *arvore, char str[]){
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
void llrbt_imprime_filhos(LLRBT *arvore){
    percorre(arvore->raiz);
}

bool llrbt_remover(LLRBT *arvore, int chave){
    if(arvore != NULL)
        return remove_(&(arvore->raiz), chave);
    
    return false;
}

