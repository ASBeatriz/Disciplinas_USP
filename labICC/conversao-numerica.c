#include <stdio.h>

int main(){
    char charTest;
    int intTest;

    scanf("%c %d", &charTest, &intTest);

    printf("numero correspondente: %d\n", charTest);
    printf("caracter correspondente: %c\n", intTest);
    printf("octal: %o\n", intTest);
    printf("hexadecimal: %x\n", intTest);

    return 0;
}
