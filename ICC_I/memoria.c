#include <stdio.h>

int main() {
    int a, b, c;
    long long int conc;
    scanf("%d %d %d", &a, &b, &c);

    long long int lb = b<<16, lc = c<<32;
    conc = lc|lb;
    printf("%lld", (conc|a));

    return 0;
}



