#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char string1[130], string2[130], param[20];
    scanf("%[^\n]s", string1);
    scanf(" %[^\n]s", string2);
    scanf(" %[^\n]s", param);

    char *token = strstr(string1, param); //aponta para o começo do parametro
    if(token == NULL) printf("%s ", string1);
    else{
        for(int i=0; i < strlen(string1); i++){ //imprime a string1 até imediatamente antes do paramentro 
            if((&string1[i] == token)) break;
            printf("%c", string1[i]);
        }
    }
    token = strstr(string2, param);
    token = token+strlen(param)+1;
    printf("%s", token);
}