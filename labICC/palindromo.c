#include <stdio.h>
#include <string.h>

int main(){
    int n;
    char p[100];
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%s", p);
        int palin = 1;
        int tam = strlen(p);
        for(int j=0; j<tam; j++){
            if(p[j] != p[tam-(j+1)]){
                palin = 0;
                break;
            }
        }
        if(palin) printf("%s eh um palindromo\n", p);
        else printf("%s nao eh um palindromo\n", p);
    }
}