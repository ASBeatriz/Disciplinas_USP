#include <stdio.h>

int main(){
    int n, v[100005],*pv=v;
    scanf("%d",&n);

    for (pv; pv < v+n; pv++) scanf("%d",pv);
    
    pv--;
    for(pv; pv >= v; pv--) printf("%d ",*pv);

    return 0;
}