/* Implementação da struct e das funções do TAD PONTO*/
#include "ponto.h"

// TAD ponto
struct ponto_{
    float p1, p2;
};

// função para criar um ponto, recebe as coordendas
PONTO *ponto_criar (float x, float y){
    PONTO *p;
    p = (PONTO *)malloc(sizeof(PONTO));
    if(p != NULL){
        p->p1 = x;
        p->p2 = y;
        return p;
    }
    return NULL;
}

// função para liberar a memória alocada do ponto e fazer o ponteiro receber NULL
void ponto_apagar (PONTO **p){
    free(*p);
    *p = NULL;
}

// função para modificar as coordenadas do ponto    
bool ponto_set (PONTO *p, float x, float y){
    if(p != NULL){
        p->p1 = x;
        p->p2 = y;
        return (true);
    }
    else return (false);
}
 
// função que retorna o valor da coordenada x do ponto
float ponto_get_x (PONTO *p){
    return p->p1;
}

// função que retorna o valor da coordenada y do ponto
float ponto_get_y (PONTO *p){
    return p->p2;
}

// função que imprime o ponto no terminal
void ponto_print (PONTO *p){
    float x = ponto_get_x(p), y = ponto_get_y(p);
    printf("Ponto: (%.1f, %.1f)\n", x , y);
}

// função que calcula e retorna a distancia entre dois pontos
/* Justificativa: visto que a função recebe apenas dados do tipo PONTO e calcula um resultado baseado
apenas nesse tipo, é mais adequado colocá-la no TAD PONTO*/
float distancia(PONTO *pa, PONTO *pb){
    float pa1 = ponto_get_x(pa);
    float pa2 = ponto_get_y(pa);
    float pb1 = ponto_get_x(pb);
    float pb2 = ponto_get_y(pb);
    float t1 = pa1 - pb1, t2 = pa2 - pb2;

    float dist = (float)sqrt((double)pow(t1,2)+pow(t2,2));
    return dist;
}
