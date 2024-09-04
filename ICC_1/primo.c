#include <stdio.h>

int main(){
    int q,n, ehprimo;
    scanf("%d",&q);

    for(int j=0; j<q; j++){
        scanf("%d",&n);
        ehprimo=1;
        for(int a=2, b=(n/2)+1; a<b; a++, b--){
            if(a == n) break;
            if((n%a == 0)||(n%b == 0)){
                ehprimo = 0;
                break;
            }
        }
        if(ehprimo) printf("Sim\n");
        else printf("Nao\n");
    }
}