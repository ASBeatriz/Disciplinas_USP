#include <stdio.h>

int main()
{
    int n;
    float sum = 0.0;
    scanf("%d",&n);
    
    for(int i=1; i<=n; i++){
        if(i%2 == 0) sum -= 1.0/i;
        else sum += 1.0/i;
    }
    printf("%.4f", sum);

    return 0;
}
