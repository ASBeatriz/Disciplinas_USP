#include <stdio.h>

int main()
{
    char palavra[26];
    scanf("%[^\n]s",palavra);
    
    char *ps = palavra;
    for(*ps; *ps != '\0'; ps++){
        printf("%c\n", *ps);
    }
    
    return 0;
}