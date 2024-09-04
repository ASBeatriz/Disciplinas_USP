#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ascii(char c);
void toLowerP(char **str);
void toLowerW(char str[]);

//função para deixar todos as letras da strings em minúsculas
void toLowerP(char **str){
    for(int i=0; i < (int)strlen(*str); i++){
        int numAscii = ascii((*str)[i]);

        if(numAscii >= 65 && numAscii <= 90){
            (*str)[i] = (char)(numAscii+32);
        }
    }
}

void toLowerW(char str[]){
    for(int i=0; i < (int)strlen(str); i++){
        int numAscii = ascii((str)[i]);

        if(numAscii >= 65 && numAscii <= 90){
            (str)[i] = (char)(numAscii+32);
        }
    }
}

int ascii(char c){
    return ((int)c);
}

int isLowerLetter(char c){
    if(((int)c >= 97) && ((int)c <= 122)) return 1;
    else return 0; 
}

int main(){
    char nomeArq[6], palavra[20];
    scanf("%s %s", nomeArq, palavra);

    FILE *fp = fopen(nomeArq, "r");
    fseek(fp, 0, SEEK_END);
    int tam = ftell(fp);
    rewind(fp);
    
    char* str = (char *)malloc(tam*sizeof(char)+1);
    fread(str, sizeof(char), tam, fp);

    toLowerP(&str);
    //printf("%s\n", str);
    toLowerW(palavra);

    int cont=0;
    
    char *token = strstr(str, palavra);
    

    while(token != NULL){

        if((*(token-1) == ' ') && (((int)*(token+strlen(palavra)) < 33) || ((int)*(token+strlen(palavra)) > 126) || (*(token+strlen(palavra)) == ',') || (*(token+strlen(palavra)) == ';') || (*(token+strlen(palavra)) == '.'))) cont++;


        token = strstr(token+strlen(palavra), palavra);
    }
    printf("quantidade: %d", cont);

    fclose(fp);
    free(str);
    str = NULL;
}