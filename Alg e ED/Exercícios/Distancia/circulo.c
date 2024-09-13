/* Implementação da struct e das funções do TAD CIRCULO*/
#include "circulo.h"

// TAD círculo
struct circulo_{
    PONTO *ponto;
    float raio;
};

// função para criar um circulo, recebe o tamanho do raio e o ponto central
CIRCULO *circulo_criar (PONTO *p, float raio){
    CIRCULO *c;
    c = (CIRCULO *)malloc(sizeof(CIRCULO));
    if(c != NULL){
        c->ponto = p;
        c->raio = raio;
        return c;
    }
    return NULL;
}

// função para modificar o ponto central do circulo
bool circulo_set_ponto (CIRCULO *c, PONTO *p){
    if(c != NULL){
        c->ponto = p;
        return (true);
    }
    else return (false);
}

// função para modificar o valor do raio do circulo
bool circulo_set_raio (CIRCULO *c, float raio){
    if(c != NULL){
        c->raio = raio;
        return (true);
    }
    else return (false);
}

// função que retorna o ponto central do circulo
PONTO *circulo_get_ponto (CIRCULO *c){
    return c->ponto;
}

// função que retorna o valor do raio do circulo
float circulo_get_raio (CIRCULO *c){
    return c->raio;
}

// função para liberar a memória alocada do círculo e fazer o ponteiro receber NULL
void circulo_apagar (CIRCULO **circulo){
    free(*circulo);
    *circulo = NULL;
}
