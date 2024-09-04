// Exercício passado em sala - aula 22/08
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

void escreva(char *str, ...){
    va_list ap;
    va_start(ap, str);
    for(int i=0; i<strlen(str); i++){
        if(str[i] == '%'){
            printf("%u", va_arg(ap, unsigned));
            i++;
        }
        else{
            printf("%c", str[i]);
        }
    }
}


int main(){
    //adicionar scanf
    escreva("o numero eh: %u dassad a %u sss %u", 2, 3, 4);
}