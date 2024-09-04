#include <stdio.h>

//soma recursiva: decrementa uma unidade dos numeros até que ambos sejam 0 (retornando a soma=0)
int soma(int a, int b){
    if(a == 0 && b > 0) return (soma(0, b-1)+1);
    else if (b == 0 && a > 0) return (soma(a-1, 0)+1);
    if(a == 0 && b == 0) return 0;  //solução trivial

    return soma(a-1, b-1)+2;
}

int main(){
    int a,b;
    scanf("%d %d", &a, &b);

    int s = soma(a, b);
    printf("%d", s);
}