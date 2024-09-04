#include <stdio.h>

int main()
{
    int *p, a=5;
    p = &a;
    printf("%d %p %p %p\n\n",*p, p,&p,&a);
    
    char palavra[8] = "abcdefg";
    
    printf("%s\n", palavra);
    printf("%p\n", palavra); //quando a variavel é um vetor, seu nome já é o endereço (não precisa de &)
    printf("%c\n", palavra[2]);
    printf("%p\n\n", &palavra[2]);
    
    char *ps = palavra;
    printf("%p\n",ps);
    printf("%c %c\n",*ps, palavra[0]); // ps aponta para a primeiro posição do vetor do qual ele guarda o endereço
    ps++;
    printf("%c",*ps); // agora ps aponta para a segunda posição
    
    return 0;
}
