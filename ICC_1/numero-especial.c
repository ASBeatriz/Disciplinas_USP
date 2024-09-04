#include <stdio.h>

int main()
{
    int n, n1, n2, u, d, c;
    for(int i=1000; i<=9999; i++){
        n = i;
        n -= u = n%10;
        n -= d = n%100;
        n -= c = n%1000;
        n1 = d+u;
        n2 = ((c+n)/100);
        if(((n1+n2)*(n1+n2)) == i) printf("%d\n", i);
    }
    
}