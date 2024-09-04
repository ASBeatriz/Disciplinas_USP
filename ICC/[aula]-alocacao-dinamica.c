#include <stdio.h>
#include <stdlib.h>
//alocação de memória na memória heap (?)

// void* calloc (int n, size_t tam);
// aloca espaço contíguo na memória para n elementos com tam bytes cada (e inicializa com 0).
// Se for bem sucedido, retorna um ponteiro void para o endereço base alocado.
// Senão, retorna NULL.

// void* malloc(size_t tam)
// aloca tam bytes na memória. Não inicializa, diferente de calloc. É, portanto, um pouco mais rápido.
// tem o mesmo retorne que calloc.

//free()
//"libera memória". Sinaliza ao sistema operacional que o espaço de memória está livre.

int main(){
    int *p;
    p = (int *)calloc(1,4);  // supondo inteiro de 4 bytes
    p = (int *)calloc(1,sizeof(int)); //portabilidade
    
    printf("%d\n", calloc(1,4));

//----------- exemplo: alocação de vetor ---------------------------
        //calloc
    int n=5,*q;
    q = (int *)calloc(n,sizeof(int)); //aloca um vetor de 5 posições

    for(int i=0; i<n; i++) printf("%d ", q[i]);

        //malloc
    int *t;
    t = (int *)malloc(n*sizeof(int));

    printf("\n");
    for(int i=0; i<n; i++) printf("%d ", t[i]);

//------------ modo correto de usar calloc ou malloc ----------------------

    if((t = (int *)malloc(100000000000000)) == NULL){ //faz a atribuição e verifica se foi mal sucedida
        printf("\nSem memoria");
        exit(1); //ou outro método de tratar o erro
    }

    free(t); //sinaliza que o espaço está livre
    t = NULL; //limpa o espaço

//------------- realloc -----------------
/*
void *realloc(void *ptr, site_t size)
Tenta redimensionar o bloco de memória apontado por ptr previamente alocado com calloc ou malloc, 
size é o tamanho em bytes do novo bloco de memória.
Se for bem sucedido, retorna um ponteiro void para o endereço base alocado.
Senão, retorna NULL.
*/

    int *b = (int *)malloc(12*sizeof(int));

    b = (int*)realloc(b,14*sizeof(int));

    //forma correta:
    int *c; //fazer com outro ponteiro, pois caso não dê certo, o ponteiro vai receber NULL e perder o endereço anterior

    if((c = (int *)(realloc(b,14*sizeof(int)))) == NULL){
        printf("Sem memoria");
        exit(1);
    }
    else{
        b = c;
    }

    return 0;
}