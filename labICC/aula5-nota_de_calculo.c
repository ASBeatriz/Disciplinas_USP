#include <stdio.h>

int main(){
	float n1,n2,n3,n4,p1,p2,sum;
	scanf("%f", &p1);
	scanf("%f", &p2);
	scanf("%f", &n1);
	scanf("%f", &n2);
	scanf("%f", &n3);
	scanf("%f", &n4);
	sum = p1+p2+n1+n2+n3+n4;

	if(sum-(p1+p2) == 0){
        printf("Reprovado\n");
        return 0;
	}
	float res = sum/6;
	if(res >= 5) printf("Aprovado\n");
	else if (res >= 3) printf("Recuperacao\n");
	else printf("Reprovado");

	return 0;
}
