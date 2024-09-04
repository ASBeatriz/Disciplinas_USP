#include<stdio.h>

/*
 o preco de compra, o preco de venda, a quantidade adquirida e a quantidade vendida.
*/

int main(){
    int n;
    float lucrot=0, maiorl=0, p[100];
    scanf("%d", &n);

    if(n==0){
        printf("Sem atividades registradas hoje");
        return 0;
    }
    for(int i=0; i<n; i++){
        int adq, vend;
        float pc, pv;
        scanf("%f %f %d %d", &pc, &pv, &adq, &vend);
        float lucro = (pv*vend) - (pc*adq);
        lucrot += lucro;
        if(lucro > maiorl) maiorl = lucro;
        p[i] = lucro;
    }
    if(lucrot >= 0) printf("lucro: %.2f", lucrot);
    else printf("prejuizo: %.2f", -lucrot);
    for(int i=0; i<n; i++){
        if(p[i] == maiorl){
            printf("\nproduto: %d lucro relativo: %.2f", i+1, p[i]);
        }
    }
}