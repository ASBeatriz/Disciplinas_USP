#include <stdio.h>

int main()
{
    int n, *pn, **pp;
    scanf("%d", &n);
    printf("Valor inicial da variavel: %d\n", n);
    
    pn = &n;
    printf("Valor do ponteiro antes do incremento: %d\n", *pn);
    
    *pn = *pn + 10;
    printf("Valor do ponteiro depois do incremento: %d\n", *pn);
    
    pp = &pn;
    printf("Valor do ponteiro para ponteiro antes do incremento: %d\n", **pp);
    
    **pp = **pp + 10;
    printf("Valor do ponteiro para ponteiro depois da mudanca: %d\n", **pp);
    printf("Valor final da variavel: %d\n", n);
    
    return 0;
}