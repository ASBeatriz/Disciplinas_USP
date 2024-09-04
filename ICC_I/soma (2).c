#include <stdio.h>
#include <math.h>

int main()
{
    unsigned short int n1,n2;
    unsigned int v=0;
    scanf("%hd %hd", &n1, &n2);
    
    for(int i=n1-1; i>=0; i--){
        short int bin;
        scanf("%hd", &bin);
        v += bin*pow(2, i);
    }
    
    for(int i=n2-1; i>=0; i--){
        short int bin;
        scanf("%hd", &bin);
        v += bin*pow(2, i);
    }
    printf("%d", v);
    
    return 0;
}
