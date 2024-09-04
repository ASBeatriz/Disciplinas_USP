#include<stdio.h>

int main(){
    int n, m, matrizN[100][100], matrizM[100][100], diagN=1, diagM=1, matrizMult[100][100];
    scanf("%d %d", &n, &m);

    //ler matriz 1
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&matrizN[i][j]);
            if(((i == j)&&(!matrizN[i][j])) || ((i != j)&&(matrizN[i][j]))){
                diagN = 0;
            }
        }
    }
    //ler matriz 2
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            scanf("%d",&matrizM[i][j]);
            if(((i == j)&&(!matrizM[i][j])) || ((i != j)&&(matrizM[i][j]))){
                diagM = 0;
            }
        }
    }

    //printar matrizes
    printf("Matrizes:\n");

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ",matrizN[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            printf("%d ",matrizM[i][j]);
        }
        printf("\n");
    }

    //printar se é diagonais ou não
    printf("A matriz 1 %s diagonal\n", diagN ? "eh":"nao eh");
    printf("A matriz 2 %s diagonal\n", diagM ? "eh":"nao eh");

    //matriz multiplicada
    if(n != m) printf("Matrizes de tamanho incompativel\n");
    else{
        printf("Matriz multiplicada:\n");
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int Soma=0;
                for(int k=0; k<n; k++){
                    Soma += matrizN[i][k]*matrizM[k][j];
                }
                matrizMult[i][j] = Soma;
                printf("%d ", Soma);
            }
            printf("\n");
        }
    }
    
    
}