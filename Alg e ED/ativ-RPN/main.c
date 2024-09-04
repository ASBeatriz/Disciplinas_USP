#include "Pilha.h"
#include <stdio.h>

int main(){
    printf("teste a notacao polonesa reversa: \n");
    char str[100];
    scanf("%s", str);
    printf("resultado: %.2f\n",rpn(str));
}