// Especificadores de formato % para conversão de bases numericas - scanf e printf

#include <stdio.h>

int main(){
    int num;
    scanf("%i", &num); //detecta a base do número
/*
    0x - predicado hexadecimal  (ex: 0x7b)
    0  - predicado octal        (ex: 0173)
    decimal não tem predicado   (ex: 123)
*/

    printf("numero em decimal: %d \n", num);        //imprime em formato decimal
    printf("numero em octal: %o \n", num);          //imprime em formato octal
    printf("numero em hexadecimal: %x \n", num);    //imprime em formato hexadecimal (com letras minúsculas)
    printf("numero em hexadecimal: %X \n", num);    //imprime em formato hexadecimal (com letras minúsculas)

    //Bônus:
    printf("caractere correspondente: %c \n", num); //imprime o caractere correspondente (tabela ASCII)
}