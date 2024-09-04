#include <stdio.h>

int main()
{
    int n1, n2, n3, *p1, *p2, *p3;
    scanf("%d %d", &n1, &n2);
    p1 = &n1;
    p2 = &n2;
    p3 = &n3;
    *p3 = *p1;
    *p1 = *p2;
    *p2 = *p3;
    
    printf("%d %d", n1, n2);
    
    return 0;
}