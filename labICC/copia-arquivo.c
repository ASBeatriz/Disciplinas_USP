#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char nomeArq[13];
    scanf("%s", nomeArq);

    FILE *fp = fopen(nomeArq, "rb");
    fseek(fp, 0, SEEK_END);
    int tam = ftell(fp); //tamanho em bytes
    fseek(fp, 0, SEEK_SET);

    char *str = (char *)malloc(tam);
    fread(str, sizeof(char), tam, fp); 

    printf("%s", str);

    fclose(fp);
    free(str);
    str = NULL;
}