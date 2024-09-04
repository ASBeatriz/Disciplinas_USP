#include <stdio.h>

int main()
{
    long long int n;
    int c=1, pot10=1;
    scanf("%lld", &n);

    for(int i=n-1; i>0; i--) {
        n*=i;
    }

    while(1){
        pot10 *= 10;
        if((n%pot10) != 0) break;
        c++;
    }

    printf("%d", c-1);

    return 0;
}
