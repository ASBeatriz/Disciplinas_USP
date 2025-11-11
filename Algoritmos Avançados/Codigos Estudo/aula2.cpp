/*
    Força bruta e Backtracking 
    
    - Problemas e subproblemas
        - Dividir um problema em pequenas partes
        - Ex.: Encontrar o maior elemento de uma lista
            [1 4 5 7 8 10 2 3 5] -> percorrer todos os elementos (pensando de forma recursiva)
            1 [4 5 7 8 10 2 3 5]
            4 [5 7 8 10 2 3 5]
            5 [7 8 10 2 3 5]
            7 [8 10 2 3 5]
            8 [10 2 3 5]
            10 [2 3 5]
            10 [3 5]
            10 [5]
            10 []

    - Dicas para soluções Força Bruta
        - Filtros vs. Geradores
        - Poda de Subproblemas (ex.: n considerar todos os numeros em espaço de sudoku pq sabemos que alguns ja n são possiveis)
        - Simetrias
*/

#include <iostream>

using namespace std;

int main(){
    // Problema 1: tem uma lista de numeros e tem um valor que queremos saber se é possível obtê-lo com a soma de elementos da lista (problema do troco)
    // ela fez em python :(
    // solução: a cada etapa, separar em duas possibilidades: "o número entra ou não na soma"; função recursiva.

    // Problema 2: Problema das Rainhas: recebemos a posição de 1 rainha no tabuleiro e devemos colocar outras N rainhar sem que nenhuma se ataque.
    // solução: podagem - desconsiderar linhas e colunas já usadas
    // função recursiva q recebe lista de rainhas colocadas ate o momento, ... o resto eu n entendi mt bem, mas vai preenchendo uma linha por vez e no fim retorna uma lista com as colunas das rainhas

}