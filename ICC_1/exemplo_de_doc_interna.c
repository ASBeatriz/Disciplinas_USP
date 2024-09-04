/* Autoria: Renata P. M Fortes -  Data: setembro de 2003.            */
/* objetivo: Este programa converte um valor decimal maior que zero, */
/* lido do teclado, em  seu correspondente valor binario,            */
/* imprimindo este valor na tela.*/

#include <stdio.h>
#define LIMITE 255  /* valor Maximo de decimal*/

typedef int vetor[8]; /* Tipo definido pelo usuário. Nome: vetor. 
                         Um vetor de inteiros de 8 posições */

int converte (int n, vetor vet){ 
/* funcao que faz a conversao de um numero decimal, positivo   */
/*    em  numero binario                                       */
/*    Parametro de Entrada:  n - Valor a ser convertido        */
/*    Parametros de Saida:  vet - Vetor que contem resultado   */
/*                          qtos_bits - Numero de bits do resultado */
    int aux, qtos_bits = 0;
    
    while (n > 0)   { 
      aux = n / 2;  
      vet[qtos_bits] = n - aux * 2;
      n = aux;
      qtos_bits += 1;
    }
    return qtos_bits-1; /* tira um do nro-bits totalizado, contava o zero  */
}/*fim da função converte */

/* Programa Principal */
int main (void) { 
  int contaBits,      /* número de bits do valor binario   */
      j,              /* indexador do vetor */
      nro;            /* valor decimal lido */
      vetor vet;      /* valor binario */
 
   for (j=0; j<9; j++) vet[j]=0;

/* Leitura do Numero */
   printf("Forneca o numero decimal (maximo 255)");    
   scanf("%d", &nro);

/* Verificacao do limite maximo */
  if (nro > LIMITE) printf("Numero muito grande!. \n");
  else         {
        contaBits = converte (nro, vet); /* Conversao */
        /* Impressao dos Resultados */
        printf(" Valor decimal: %d - - valor binario:\n ", nro);
        for (j=contaBits; j>=0; j--) printf("%d", vet[j]);
          printf("\n-----------\n");
      }
  return(0);
}  /* fim do programa principal */


