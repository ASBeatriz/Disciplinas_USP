#include <stdio.h>

int main(){
    long long int n;
    scanf("%lld",&n); //scanf é uma função externa, por isso é necessário passar o endereço (com &) da minha variável para que ela possa acessar
    printf("char: %lld\n", n*sizeof(char));
    printf("int: %lld\n", n*sizeof(int));
    printf("double: %lld\n", n*sizeof(double));

    return 0;
}
