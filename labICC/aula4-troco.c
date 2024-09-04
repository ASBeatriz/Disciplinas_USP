#include <stdio.h>

void qtd_notas(int *valor, int valor_nota, int *cont_nota){ //usando * e & para acessar o endereço da variável e modoficá-la
    if(*valor >= valor_nota){
        *cont_nota = *valor/valor_nota;
        *valor -= *cont_nota*valor_nota;
	}
}

int main(){
	int valor, duz=0, cem=0, cinq=0, vinte=0, dez=0, cinco=0, dois=0, um=0, div=0;
	scanf("%d", &valor);

	qtd_notas(&valor, 200, &duz);
	qtd_notas(&valor, 100, &cem);
	qtd_notas(&valor, 50, &cinq);
	qtd_notas(&valor, 20, &vinte);
    qtd_notas(&valor, 10, &dez);
	qtd_notas(&valor, 5, &cinco);
	qtd_notas(&valor, 2, &dois);
	qtd_notas(&valor, 1, &um); /*

	if(valor >= 200){
        duz = valor/200;
        valor -= duz*200;
	}
	if(valor >= 100){
        cem = valor/100;
        valor -= cem*100;
	}
	if(valor >= 50){
        cinq = valor/50;
        valor -= cinq*50;
	}
	if(valor >= 20){
        vinte = valor/20;
        valor -= vinte*20;
	}
	if(valor >= 10){
        dez = valor/10;
        valor -= dez*10;
	}
	if(valor >= 5){
        cinco = valor/5;
        valor -= cinco*5;
	}
	if(valor >= 2){
        dois = valor/2;
        valor -= dois*2;
	}
	if(valor >= 1){
        um = valor;
        valor = 0;
	}
*/
	printf("%d nota(s) de R$ 200\n", duz);
	printf("%d nota(s) de R$ 100\n", cem);
	printf("%d nota(s) de R$ 50\n", cinq);
	printf("%d nota(s) de R$ 20\n", vinte);
	printf("%d nota(s) de R$ 10\n", dez);
	printf("%d nota(s) de R$ 5\n", cinco);
	printf("%d nota(s) de R$ 2\n", dois);
	printf("%d moeda(s) de R$ 1\n", um);

	return 0;
}
