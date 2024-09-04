#include <stdio.h>

int main()
{
    unsigned int n, qtd=0;
    scanf("%d", &n);

    for(int i=1; i<13; i++){
        int pot5 = 1;
        for(int j=1; j<=i; j++){
            pot5 *= 5;
        }
        if(pot5 > n) break;
        qtd += n/pot5;
    }
    printf("%d", qtd);

    return 0;
}

