/*
RESOLUÇÃO DE PROBLEMAS RECURSIVOS:

❑ 1º ponto: definir o problema de forma recursiva

❑ 2º ponto: definir a condição de término

❑ 3º ponto: a cada chamada recursiva, deve-se tentar garantir que 
se está mais próximo de satisfazer a condição de término
*/

#include <stdio.h>

// Retorna a soma dos primeiros n elementos
int somaAte(int n){
    if(n == 1) return 1; //solução trivial
    return n+somaAte(n-1); //solução recursiva
}

// Imprime elementos de um vetor de inteiros iterativamente
void imprimir_it(int vetor[], int tam){
    for(int i=0; i<tam; i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");
}

// Imprime elementos de um vetor de inteiros recursivamente
void imprimir_rec(int vetor[], int tam, int indice){
    if(indice < tam){
        printf("%d ", vetor[indice]);
        imprimir_rec(vetor, tam, indice+1);
    }
}

// Imprime o n-ésimo número de fibonacci de forma recursiva
int fibonacci_rec(int n){
    if(n == 1) return 1;
    if(n == 2) return 1;
    return fibonacci_rec(n-1) + fibonacci_rec(n-2);
    
    // Outra forma/estrutura:
    
    // int res;
    // if(n == 1 || n == 2) res = 1;
    // else res = fibonacci_rec(n-1)+fibonacci_rec(n-2);

    // return res;
}

// Imprime o n-ésimo número de fibonacci de forma iterativa
int fibonacci_it(int n){
    // if(n == 1 || n == 2) return 1;
    // int vet[100];
    // vet[0] = vet[1] = 1;
    // for(int i=2; i < n; i++){
    //     vet[i] = vet[i-1] + vet[i-2];
    // }
    // return vet[n-1];

    //solução do slide (mais genial):
    int i=1, k, resultado=0;

    for (k=1;k<=n;k++) {
        resultado=resultado+i;  //adiciona o resultado anterior
        i=resultado-i;  
    }

    return(resultado); 
}

int fatorial(int n){
    if(n == 0 || n == 1) return 1;
    else return n*fatorial(n-1);
}

int fatorial_cauda(int n, int m){
    if(n == 0 || n == 1) return m;
    else return fatorial_cauda(n-1, n*m);
}

//Descreve os movimentos para resolver o jogo 'Torre de Hanoi' de com n discos
/*
Algoritmo:
para mover n disco da torre A para a torre C, move-se primeiro n-1 discos para a torre B,
depois o disco n para a torre C e, por fim, os n-1 discos da torre B para a torre C.
*/
void torreDeHanoi(int n, char origem, char destino, char temporaria){
    if(n == 1){
        printf("mova o disco 1 da haste %c para a haste %c\n", origem, destino);
    }
    else{
        torreDeHanoi(n-1, origem, temporaria, destino);
        printf("mova o disco %d da haste %c para a haste %c\n", n, origem, destino);
        torreDeHanoi(n-1, temporaria, destino, origem);
    }
}

int main(){
    // testa somaAte
    int num;
    scanf("%d", &num);
    printf("soma ate %d: %d\n", num, somaAte(num));

    // testa imprimir_it e _rec
    int v[] = {1, 2, 3, 4};
    printf("vetor = ");
    imprimir_it(v, 4);
    printf("vetor = ");
    imprimir_rec(v, 4, 0);

    //testa fibonacci_it e _rec
    int n;
    scanf("%d", &n);
    printf("fibonacci de %d:\n%d \n%d\n", n, fibonacci_it(n), fibonacci_rec(n));

    printf("fatoraial de %d: %d\n", n, fatorial_cauda(n, 1));

    //testa torreDeHanoi
    int n2;
    scanf("%d", &n2);
    torreDeHanoi(n2, 'A', 'C', 'B');
}