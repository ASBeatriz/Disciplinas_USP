/*
O objetivo deste exercício é treinar modularização e passagem 
de parâmetros.

Exercício:
Faça um programa em C para realizar a soma dos elementos 
de uma matriz MxN do tipo double que sejam maiores que um 
valor dado como entrada. Os elementos da matriz são entradas 
do usuário.
Utilize funções para modulizar seu código: entrada de dados, 
cálculo da soma, impressão do(s) resultado(s). 

Autor: Rudinei Goularte (2024)
*/

#include <stdio.h>

/*Protótipos das funções*/
double soma(double num, int n_linhas, int n_colunas, double matriz[100][100]);
void entrada(double *num, double mat[100][100], int *lin, int *col);
void resultado(double res, double num);

/*
A função soma() soma recebe como parâmetros uma matriz (matriz)
de doubles de dimensão 100 x 100, a quantidade de linha (n_linhas) 
e de colunas (n_colunas) definidas pelo usuário na função de 
entrada de dados (entrada()) como as dimensões úteis de "matriz" e
o número (num) usado como critério de busca. 

A função soma()
então percorre "matriz", elemento a elemento, linha a linha, e 
adiciona (somatório) o valor do elemento se o mesmo for maior
que "num". A função retorna o somatório acumulado (s).
*/
double soma(double num, int n_linhas, int n_colunas, double matriz[100][100]) {
	double s = 0.0;
	for (int i = 0; i < n_linhas; i++) {
		for (int j = 0; j < n_colunas; j++) {
			if (matriz[i][j] > num)
				s = s + matriz[i][j];
		}
	}
	return(s);
}

/*
A função entrada() realiza a entrada de dados para:
- mat: a matriz definida em main() que contém os valores a serem
trabalhados. "mat", por ser matriz, é passada por referência.
- num: número a ser usado como critério de busca. Como foi definido
em outra função (main()), é passado para entrada() por referência.
- lin e col: variáveis definidas em main() para determinar os 
limites em linhas e colunas da matriz "mat". "mat" foi definida
como tendo 100 linha e 100 colunas, mas não necessariamente
precisa sempre ter 100x100 elementos. A quantidade de elementos
(dimensões) real é definida pelo usuário a partir de "lin" e "col".
*/
void entrada(double *num, double mat[100][100], int *lin, int *col){
	printf("\nDigite um valor para o número da busca: ");
	scanf("%lf", num);

	printf("\nDigite os valores para a quantidade de linhas e de colunas da matriz (limitado a 100: ");
	while((*lin > 100) || (*col > 100))
		scanf("%d %d", lin, col);

	printf("\nDigite os valores dos elementos (double) da Matriz:\n");
	for(int i=0; i<*lin; i++)
		for(int j=0; j<*col; j++){
			scanf("%lf", &mat[i][j]);
		}
}

/*
Esta função simplesmente exibe no terminal o valor da soma
calculada na função soma().
*/
void resultado(double res, double num){
	printf("\n A Soma dos elementos da Matriz maiores que %lf é: %lf\n", num, res);
}

/*
Função principal: apenas define (declara) as variáveis relacionadas
ao problema e coordena as chamadas a funções que irão resolver
o problema proposto.
*/
int main(void) {
	double mat[100][100];
	double rsoma = 0.0;
	double num;
	int lin=101, col=101;

	entrada(&num, mat, &lin, &col);
	rsoma = soma(num, lin, col, mat);
	resultado(rsoma, num);

	return 0;
}
