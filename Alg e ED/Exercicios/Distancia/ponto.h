/* Declaração da struct e das funções do TAD PONTO*/
#ifndef PONTO_H
    #define PONTO_H
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>

    typedef struct ponto_ PONTO;

    /* Funções para manipulação do ponto: */
    PONTO *ponto_criar (float x, float y);
    void ponto_apagar (PONTO **p);
    bool ponto_set (PONTO *p, float x, float y);
    float ponto_get_x (PONTO *p);
    float ponto_get_y (PONTO *p);
    void ponto_print (PONTO *p);
    float distancia(PONTO *pa, PONTO *pb);
#endif
