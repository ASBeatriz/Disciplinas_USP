#include "arvore_avl.h"

struct no {
    ITEM *item;
    NO *esq;
    NO *dir;
    int filhos_total;
    int FB;     // fator de balanceamento
    // int altura;
};

struct arvore_avl {
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

int max(int a, int b){
    return ((a>b) ? a : b);
}

int get_altura(NO *no){
    if(no == NULL){
        return -1;
    }
    else if (no->esq == no || no->dir == no) { // ciclo detectado
        printf("Erro: ciclo detectado no nó!\n");
        return -1;
    }
    else{
        return ((max(get_altura(no->esq), get_altura(no->dir))) + 1);
    }
}

int get_FB(NO* no){
    if(no == NULL) return 0;
    else return get_altura(no->esq) - get_altura(no->dir);
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
        printf("no: %d", *(int*)item_get_dados(no->item), get_altura(no));
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

NO *rodar_direita(NO *a){
    NO *b = a->esq;
    
    // Faz a rotação
    a->esq = b->dir;
    b->dir = a;

    // Ajusta os novos fatores de balanceamento
    a->FB = b->FB = 0;  

    return b;
}

NO *rodar_esquerda(NO *a){
    NO *b = a->dir;

    // Faz a rotação
    a->dir = b->esq;
    b->esq = a;

    // Ajusta os novos fatores de balanceamento
    a->FB = b->FB = 0;  

    return b;
}

NO *rodar_esq_dir(NO *a){
    a->esq = rodar_esquerda(a->esq);
    return rodar_direita(a);
}

NO *rodar_dir_esq(NO *a){
    a->dir = rodar_direita(a->dir);
    return rodar_esquerda(a);
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

    // Verifica necessidade de balanceamento
    if(get_FB(raiz) == 2){
        if(get_FB(raiz->esq) >= 0) raiz = rodar_direita(raiz);
        else raiz = rodar_esq_dir(raiz);
    }
    else if(get_FB(raiz) == -2){
        if(get_FB(raiz->dir) <= 0) raiz = rodar_esquerda(raiz);
        else raiz = rodar_dir_esq(raiz);
    }

    return raiz;
}

// Função para substituir o elemento retirado pelo maior da subárvore esquerda
void troca_max_esq(NO *troca, NO* no_anterior, NO* raiz){
    if(troca->dir != NULL) troca_max_esq(troca->dir, troca, raiz);
    else{
        if(raiz == no_anterior)
            no_anterior->esq = troca->esq;
        else
            no_anterior->dir = troca->esq;

        raiz->item = troca->item ;   // faz a troca
        // Desaloca o nó
        free(troca);
        troca = NULL;
    }
}

// mudança em relação a abb, remove_ agora retorna NO* e funcionamento é parecido com o >> inserir <<

bool remove_(NO** no, int chave){
    bool removido;
    if(*no == NULL){
        return false;   //caso não encontrar o nó
    }
    else{
        int chave_no = item_get_chave((*no)->item);
        if(chave_no == chave){
            item_apagar(&((*no)->item));    //apaga o item do nó

            // caso o nó seja folha ou tenha um só filho (se um dos filhos é nulo, aponta para o outro)
            if((*no)->esq == NULL || (*no)->dir == NULL){
                /*
                Passo a passo:
                    - Muda o ponteiro do nó para um de seus filhos
                    - Exclui o nó
                */
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
            else{   // caso o nó tenha dois filhos
                /*
                Passo a passo:
                    - Acha o nó para substituir
                    - Muda o ponteiro do nó anterior ao que vai substituir
                    - Troca o valor dos nós
                    - Exclui o nó que antes substituiu
                */
                troca_max_esq((*no)->esq, *no, *no);
            }
            removido = true;
        }
        else if(chave_no > chave) removido = remove_(&((*no)->esq), chave);
        else if(chave_no < chave) removido = remove_(&((*no)->dir), chave);
    }

    if (removido == false) return false;

    // Verifica se precisa balancear (identico ao de inserção)
    if(*no != NULL){
        (*no)->FB = get_FB(*no);

        if(get_FB(*no) == 2){
            if(get_FB((*no)->esq) >= 0){
                printf("rotação direita\n");
                *no = rodar_direita((*no));
            }
            else{
                printf("rotação esquerda direita\n");
                *no = rodar_esq_dir((*no));
            }
        }
        else if(get_FB((*no)) == -2){
            if(get_FB((*no)->dir) <= 0){
                *no = rodar_esquerda((*no));
                printf("rotação esquerda\n");
            }
            else {
                *no = rodar_dir_esq(*no);
                printf("rotação direito esquerda\n");
            }
        }
    }
    return true;
}

// ------------------------------ FUNÇÕES PRINCIPAIS ---------------------------------

// Cria e inicializa a árvore
AVL *avl_criar(){
    AVL *arvore = (AVL*)malloc(sizeof(AVL));
    if(arvore != NULL){
        arvore->raiz = NULL;
        arvore->altura = -1;
    }
    return arvore;
}

// Função para inserir um nó na árvore
bool avl_inserir(AVL *arvore, ITEM *item){
    if(arvore == NULL) return false;

    NO *no = (NO*)malloc(sizeof(NO));
    if(no == NULL) return false;
    
    no->item = item;
    no->dir = NULL;
    no->esq = NULL;
    no->FB = 0;
    no->filhos_total = 0;
    // no->altura = 0;

    arvore->raiz = inserir_no(arvore->raiz, no);
    return true;
}

// Função para apagar a árvore
void avl_apagar(AVL **arvore) {
    apagar(&((*arvore)->raiz));
    free(*arvore); 
    *arvore = NULL;
}

ITEM *avl_busca(AVL *arvore, int chave){
    return busca(arvore->raiz, chave);
}

int avl_profundidade(AVL *arvore){
    // int p = -1;
    return calc_profundidade(arvore->raiz);
}

// Função para imprimir a árvore
void avl_imprimir(AVL *arvore, char str[]){
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
void avl_imprime_filhos(AVL *arvore){
    percorre(arvore->raiz);
}

bool avl_remover(AVL *arvore, int chave){
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
bool avl_perfeitamente_balanceada(AVL *T){
    if(T->raiz == NULL) return false;
    return verifica_perfBalanceada(T->raiz);
}
