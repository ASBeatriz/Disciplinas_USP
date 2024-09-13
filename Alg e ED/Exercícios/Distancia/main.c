// Programa cliente que calcula a posição relativa de um ponto a um círculo

#include "circulo.h"

int main(){
    float p1, p2, r;
    int n;
    scanf(" %f %f %f %i", &p1, &p2, &r, &n); //leitura dos dados

    /* utilização das funções: */
    PONTO *pontoc = ponto_criar(p1, p2);
    CIRCULO *circulo = circulo_criar(pontoc, r);

    for(int i=0; i<n; i++){
        float x, y, dist;
        scanf("%f %f", &x, &y);

        PONTO *p = ponto_criar(x, y);
        dist = distancia(p, pontoc);

        if(dist < r){
            printf("dentro\n");
        }
        else if(dist == r){
            printf("no raio\n");
        }
        else{
            printf("fora\n");
        }
    }
}