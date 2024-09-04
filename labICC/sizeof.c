#include <stdio.h>

int main()
{
    char c;
    unsigned char uc; //8 bits = 8 para valores (256 valores posssíveis)
    signed char sc; //8 bits = 1 para sinal + 7 para valores (128 valores possíveis)

    c = 250;
    uc = 250;
    sc = 0b11111010; //250 em binario

    printf("%d %d %d",c,uc,sc);

    return 0;
}
