#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char palavra[20], nomeArq[9];
    scanf("%s %s", palavra, nomeArq);

    FILE *fp = fopen(nomeArq, "rb");
    fseek(fp, 0, SEEK_END);
    int tamArq = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *texto = (char *)malloc(tamArq*sizeof(char)+1);
    fread(texto, sizeof(char), tamArq, fp);
    //printf("%s", texto);

    char *tok = strstr(texto, palavra);
    for(int i=0; i < (int)strlen(texto); i++){
        if(texto+i == tok){
            i+=strlen(palavra);
            if(*(texto+i)==' ') continue;
        }
        
        printf("%c", *(texto+i));
    } 

    fclose(fp);
    free(texto);
    texto = NULL;
}