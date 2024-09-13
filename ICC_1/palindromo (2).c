#include <stdio.h>

// 97 a 122
int main()
{
    int n,v[26];
    scanf(" %d",&n);

    for(int i=0; i<26; i++) v[i]=0;

    for(int i=0; i<n; i++){
        char c;
        scanf(" %c",&c);
        v[c-97]++;
    }

    int impar = 0, res=0;

    for(int i=0; i<n; i++){
        if(v[i]%2 == 1) impar++;
    }
    if((n%2 == impar%2) && (impar <=1)) res = 1;

    if(res) printf("Sim");
    else printf("Nao");

    //for(int i=0; i<26; i++) printf("%d",v[i]);

    return 0;
}
