#include<stdio.h>

int inteiroParaRomano(int *v, int i){
    for(int j=0; j < v[i]/1000; v[i]-=1000) printf("M");
    if(v[i]/900){
        printf("CM");
        v[i]-=900;
    }
    for(int j=0; j < v[i]/500; v[i]-=500) printf("D");
    for(int j=0; j < v[i]/100;){
        if(v[i]/100 == 4){
            printf("CD");
            v[i] -= 400;
            break;
        } 
        printf("C");
        v[i]-=100;
    }
    if(v[i]/90){
        printf("XC");
        v[i]-=90;
    }
    for(int j=0; j < v[i]/50; v[i]-=50) printf("L");
    for(int j=0; j < v[i]/10;){
        if(v[i]/10 == 4){
            printf("XL");
            v[i] -= 40;
            break;
        } 
        printf("X");
        v[i]-=10;
    }
    if(v[i] == 9){
        printf("IX");
        v[i]-=9;
    }
    if(v[i]/5){
        printf("V");
        v[i]-=5;
    }
    if(v[i] == 4) printf("IV");
    else{
        for(int j=0; j<v[i]; j++) printf("I");
    }
    printf("\n");   
}

int main(){
    int n, v[10000];
    scanf("%d",&n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
        inteiroParaRomano(v,i);
    }
    
    return 0;
}