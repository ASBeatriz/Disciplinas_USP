#include "Pilha.h"

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        char s[1010];
        scanf("%s", s);
        printf("%s", (balanceada(s)? "BALANCEADO\n" : "NAO BALANCEADO\n"));
    }
}