#include <stdio.h>

int contaChar(char *string){
    int i=0;
    for(; string[i] != '\0'; i++);
    return i;
}

int stringsIguais(char *s1, char *s2){
    for(int i=0; s1[i] == s2[i]; i++){
        if(s1[i] == '\0') return 1;
    }
    return 0;
}

int main(){
    char str[100], str1[100], str2[100];
    scanf("%s", str);
    printf("A string \"%s\" tem tamanho %d\n", str, contaChar(str));    
    scanf("%s %s", str1, str2);
    printf("As strings \"%s\" e \"%s\"", str1, str2);
    printf((stringsIguais(str1, str2))?" sao iguais\n":" nao sao iguais\n");  
}