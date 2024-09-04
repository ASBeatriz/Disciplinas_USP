#include<stdio.h>

int main(){
	int a,b,c,d;

	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);

	if(a == c && a != 0){
        if(b == d && b != 0){
            if(a == b){
                //quadrado
                printf("quadrado!\n");
            }
            else printf("retangulo!\n"); //retangulo
        }
        else printf("nenhum!\n"); //nenhum
	}
	else{
        //nenhum
        printf("nenhum!\n");
	}

	return 0;
}
