#include <stdio.h>

void imprimeMediaAlunos(float matriz[101][26], int l, int c){
    for(int i=0; i<l; i++){
        float S=0;
        for (int j = 0; j<c; j++) S += matriz[i][j];
        
        float media = S/(float)c;
        printf("Media do aluno %d = %.2f : %s\n", i+1, media, (media >= 5)?"Aprovado":"Reprovado");
    }
    printf("\n");
}

void mediaAtiv(float matriz[101][26], int l, int c, float *medias){
    for(int i=0; i<c; i++){
        float S=0;
        for (int j = 0; j<l; j++) S += matriz[j][i];
        
        float media = S/(float)l;
        medias[i] = media;
    }
}

void ordenar(float *vetor, int n){
    while(1){
        int cont=0;
        for(int i=0; i<n; i++){
            if(vetor[i] < vetor[i+1]){
                float k = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = k;
                cont++;
            }
        }
        if(!cont) break;
    }
}


int main(){
    int alunos, ativ;
    float medias[26], notas[101][26];
    scanf("%d %d", &alunos, &ativ);

    for(int i=0; i<alunos; i++){
        for(int j=0; j < ativ; j++){
            scanf("%f",&notas[i][j]);
        }
    }
    
    imprimeMediaAlunos(notas, alunos, ativ);
    mediaAtiv(notas, alunos, ativ, medias);  
    ordenar(medias, ativ);

    for(int i=0; i<ativ; i++) printf("%.2f ", medias[i]);  

}