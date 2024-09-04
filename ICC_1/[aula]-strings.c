#include<stdio.h>
#include<stdlib.h>

char *p;

int main(){
    p = malloc(5*sizeof(char));
    for(int i=0; i<4; i++){
        scanf("%c",p);
        p++;
    }
    printf("%s",p); //??

    // char str[5],str2[5];
    // str[0] = 'a';
    // str[1] = 'b';
    // str[2] = 'c';
    // str2[0] = str[0];
    // str2[1] = str[1];
    // printf("%s ",str);
    // printf("%s ",str2);

}