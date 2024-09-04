#include <stdio.h>

int main()
{
    int *p; //* indica que é um endereço
    //ponteiros tem 8 bytes, mas a quantidade de bytes da região para a qual ele aponta depende do tipo em que ele foi inicializado (int, nesse caso, = 4 bytes)
    {
        int a = 10;
        printf("a: %d\n", a);
        p=&a; //SEMPRE INICIALIZAR O POPNTEIRO
        // & retorna o endereço de a;
    }
    printf("p: %p \n",p);

    int q = *p; // q recebe o conteúdo da variável "no endereço" p.
    printf("q: %d \n", q);

    int b = 10;
    int *p2 = &b;

    printf("p2 e p estao apontando para a mesma posicao de memoria? %d \n", p2==p); //comparação do lugar para onde estão apontando
    printf("p2 e p estao apontando para o mesmo valor? %d \n", *p2==*p); //comparação do valor para o qual estão apotando (10, nesse caso)

    *p2 = 20;
    printf("%d \n",b); //20

    /*

    ponteiro p:
    p = endereço para o qual p está apontando.
    *p = valor armazenado no endereço para o qual p está apontando.
    &p = endereço de p.

    */

    return 0;
}
