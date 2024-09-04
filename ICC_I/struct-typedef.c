#include <stdio.h>

//typedef permite definir (ou redefinir) um tipo de dado
typedef int inteiro;

//structs são uma forma de agrupar diversas variáveis ​​relacionadas em um só lugar
struct Player{
    char *nome[12];
    inteiro idade;
};

int main(){
    inteiro a=2, b=3;
    printf("a: %d, b: %d\n", a, b);

    struct Player p1;
    *p1.nome = "ok";
    p1.idade = 18;
    printf("%s\n", *p1.nome); 
    printf("%d", p1.idade); 

}