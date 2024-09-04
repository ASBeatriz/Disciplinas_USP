#include<stdio.h>

int main(){
    int t1,t2,v1[10],v2[10];
    
    scanf("%d", &t1);
    for(int i=0; i<t1; i++) scanf("%d",&v1[i]);
    scanf("%d", &t2);
    for(int i=0; i<t2; i++) scanf("%d",&v2[i]);

    int vazio = 1;
    printf("intersecao: ");
    for(int i=0; i<t1; i++){
        for(int j=0; j<t2; j++){
            if(v1[i] == v2[j]){
                printf("%d ", v1[i]);
                vazio=0;
                break;
            }
        }
    }
    if(vazio) printf("vazio");

    vazio = 1;
    printf("\na - b: ");
    for(int i=0; i<t1; i++){
        int ver = 1;
        for(int j=0; j<t2; j++){
            if(v1[i] == v2[j]){
                ver = 0;
                break;
            }
        }
        if(ver){
            printf("%d ",v1[i]);
            vazio = 0;
        }
    }
    if(vazio) printf("vazio");
}