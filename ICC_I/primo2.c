#include <stdio.h>

int q,v[1500005]; //aloquei como global pq tava dando problema de stack overflow
int main(void) {
    
    scanf("%d", &q);

    for(int i=0; i<=1500000; i++) v[i] = 0;
    for(int i=2; i<=1500000; i++){
        if(v[i] == 0){
            for(int j = i+i; j<=1500000; j+=i) v[j] = 1;
        }
    }
    for(int a=0; a<q; a++){
        int n;
        scanf("%d", &n);
        if(v[n] == 0) printf("Sim\n");
        else printf("Nao\n");
    }
}