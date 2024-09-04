#include <stdio.h>

int main(){
    int n,b;

    scanf("%d %d",&n, &b);

    if(n<1 || n>7){
        printf("Dia nao registrado");
        return 0;
    }
    // se o switch verificar uma condição que não tem break no fim, ele automaticamente executa todo o resto (sem mais verificar a condição dos cases)
    switch (n){
        case 1:
            printf("Segunda: Aula de computacao\n");
            if(b == 1) break;
        case 2:
            printf("Terca: Treino de volei\n");
            if(b == 1) break;
        case 3:
            printf("Quarta: Aula de calculo\n");
            if(b == 1) break;
        case 4:
            printf("Quinta: Lista de GA\n");
            if(b == 1) break;
        case 5:
            printf("Sexta: Festa da Sacim\n");
            if(b == 1) break;
        case 6:
            printf("Sabado: Jantar em familia\n");
            if(b == 1) break;
        case 7:
            printf("Domingo: Depressao pos final de semana\n");
            if(b == 1) break;
    }

    return 0;
}
