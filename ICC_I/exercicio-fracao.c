#include <stdio.h>

struct fracao{
    int num, den;
};

typedef struct fracao Fracao;

Fracao soma_fracao(Fracao f1, Fracao f2){
    Fracao fs;
    fs.den = f1.den * f2.den;
    fs.num = (f1.num*f2.den) + (f2.num*f1.den);
    return fs;
}

int main(){
    Fracao f1, f2, f3;
    scanf("%d %d %d %d", &f1.num, &f1.den, &f2.num, &f2.den);
    f3 = soma_fracao(f1, f2);
    printf("%d/%d", f3.num, f3.den);
}