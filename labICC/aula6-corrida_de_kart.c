#include <stdio.h>

int main()
{
    float velA, velB, dist;
    int n,t;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%f %f %d", &velA, &velB, &t);
        
        if(t == 0) printf("A corrida ainda nao comecou\n");
        else{
            if(velA == 0 || velB == 0){
                if(velA == velB) printf("Os dois pilotos nao querem competir\n");
                else if (velA > velB) printf("O piloto B desistiu inesperadamente\n");
                else printf("O piloto A desistiu inesperadamente\n");
            }
            else if(t < 0){
                printf("De alguma forma os pilotos voltaram no tempo\n");
            }
            else if(velA == velB){
                dist = velA*t;
                printf("Os karts empataram, percorrendo cada %.2fkm\n",dist);
            }
            else if (velA > velB){
                dist = (velA-velB)*t;
                printf("O kart A venceu e percorreu %.2fkm a mais que o kart B\n", dist);               
            }
            else if(velB > velA){
                dist = (velB-velA)*t;
                printf("O kart B venceu e percorreu %.2fkm a mais que o kart A\n", dist);
            }
        }
    }

    return 0;
}
