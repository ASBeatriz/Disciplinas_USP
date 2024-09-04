#include <stdio.h>
#include <string.h>

int main(){
    const char haystack[20] = "TutorialsPointOK";
    const char needle[10] = "Point";
    char *ret, *strfinal;


    ret = strstr(haystack, needle);
    int n = (int)strlen(needle);
    printf("The substring is: %.*s\n", n, ret); //%.*s para especificar a quantidade de caracteres a ser impresso
   
    return(0);
}