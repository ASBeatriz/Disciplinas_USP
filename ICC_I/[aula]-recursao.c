//Funcao rescursiva gasta mais memoria e mais tempo, mas tem situações em que é mais facil de entender (em problemas naturallmente recursivos)
#include <stdio.h>

//Funcao recursiva - Soma dos primeiros n numeros
int somaAte(int n){
    if(n == 1) return 1; //Solucao trivial  !!Imporatnte garantir que ele é atingido
    return somaAte(n-1)+n;
}

//Funcao recursiva - fatorial de n
long long unsigned int fatorial(int n){
    if(n == 1) return 1; //Solucao trivial
    return n*(fatorial(n-1));
}

//Funcao iterativa - fatorial de n
long long unsigned int fatorialIter(int n){
    int res=1;
    for(int i=1; i<=n; i++) res *= i;
    return res; 
}

//Funcao recursiva - sequencia de fibonacci (começando em 0: 0 1 1 2 3 5 8 13 21 ...)
int fibonacci(int n){
    if(n == 1) return 0;
    if(n == 2) return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

//Funcao recursiva - imprime todos os antecessores de n em ordem crescente
void antecessores(int n){
    if(n == 0) return;
    antecessores(n-1);

    printf("%d ", n); //resolve o problema na "volta" da recursividade
}

int main(){
    int n, res;
    long long unsigned r;
    scanf("%d", &n);

    //r = somaAte(n);
    // r = fatorial(n);
    // printf("%llu\n", r);

    // r = fatorialIter(n);
    // printf("%llu", r);

    // res = fibonacci(n);
    // printf("%d", res);

    antecessores(n);
     
}