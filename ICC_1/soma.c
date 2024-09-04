#include <stdio.h>

int main(void){
    int n,m,vn[31],vm[31], *pvn = vn, *pvm = vm;
    
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0; i<n; i++) scanf("%d",pvn++);
    for(int i=0; i<m; i++) scanf("%d",pvm++);
    
    int Sn=0, Sm=0, pot=1;
    for(int i=0; i<n-1; i++) pot *= 2;

    for(pvn = vn; pvn < vn+n; pvn++){
        Sn += *pvn*pot;
        pot /= 2;
    }

    pot = 1;
    for(int i=0; i<m-1; i++) pot *= 2;

    for(pvm = vm; pvm < vm+m; pvm++){
        Sm += *pvm*pot;
        pot /= 2;
    }
    printf("%d\n",Sn+Sm);

    return 0;
}