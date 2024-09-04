#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char string1[130], string2[130], param[20];
    scanf("%[^\n]s", string1);
    scanf(" %[^\n]s", string2);
    scanf(" %[^\n]s", param);
    
    string1[strcspn(string1, "\r\n")] = '\0';
    string2[strcspn(string2, "\r\n")] = '\0';
    param[strcspn(param, "\r\n")] = '\0';

    char *token = strstr(string1, param); //aponta para o começo do parametro
    if(token == NULL) printf("%s", string1);
    else{
        for(int i=0; i < strlen(string1); i++){ //imprime a string1 até imediatamente antes do parametro 
            if(&string1[i] == token) break;
            printf("%c", string1[i]);
        }
    }
    char *token2 = strstr(string2, param);

    if(token2 != NULL){
        if(token == NULL) printf("%s", token2+strlen(param)); //se a string 1 foi printada com espaço
        else printf("%s", token2+strlen(param)+1);
    }
}