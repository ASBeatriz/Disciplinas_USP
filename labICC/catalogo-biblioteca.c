#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, cont_linha = 0;
    scanf("%d ", &n);
    char **titulo = (char **)malloc(n*sizeof(char*));
    char **autor = (char **)malloc(n*sizeof(char*));
    char **ano = (char **)malloc(n*sizeof(char*));
    int *contador = (int  *)malloc(n*sizeof(int));

    for(int i=0; i<n; i++){ //leitura dos livros

        char *temp_str = (char*)malloc(150*sizeof(char));
        scanf(" %[^\n]s ", temp_str);

        char *index = strtok(temp_str, ",");

        int existente = 0;

        //percorre o vetor e verifica se o titulo ja existe
        for(int j=0; j < cont_linha; j++){ 

            if(strcmp(index, titulo[j]) == 0){ //se os titulos forem iguais
                existente = 1;
                contador[j]++;
                break;
            }  
        }
        if(existente){
            continue;
        }
        else{
            contador[cont_linha]=1;
            titulo[cont_linha] = (char*)malloc((strlen(index)*sizeof(char))+1); //aloca o tamanho da linha
            strcpy(titulo[cont_linha], index); //copia a linha

            index = strtok(NULL, ",");
            autor[cont_linha] = (char*)malloc((strlen(index)*sizeof(char))+1);
            strcpy(autor[cont_linha], index);

            index = strtok(NULL, "\n");
            ano[cont_linha] = (char*)malloc((strlen(index)*sizeof(char))+1);
            strcpy(ano[cont_linha], index);
            cont_linha++;

        }
        free(temp_str);
        temp_str = NULL;
    }

    printf("Catalogo de Livros:\n");
    for(int i=0; i<cont_linha; i++){
        printf("Livro %d:\nTitulo: %s\nAutor:%s\nAno:%s\nQuantidade: %d\n", i+1, titulo[i], autor[i], ano[i], contador[i]);
        if(i!= cont_linha-1) printf("\n");
    }

    //Desaloca marizes
    for(int i=0; i<cont_linha; i++){
        free(autor[i]);
        free(titulo[i]);
        free(ano[i]);
        autor[i] = NULL;
        titulo[i] = NULL;
        ano[i] = NULL;
    }
    free(autor);
    free(titulo);
    free(ano);
    free(contador);
    autor = NULL;
    titulo = NULL;
    ano = NULL;
    contador = NULL;
}