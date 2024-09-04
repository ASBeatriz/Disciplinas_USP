#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979323846

int main(){
    int n;
    double l;

    scanf("%d %lf", &n, &l);

    double semiper = (n*l)/2;
    double angRad = ((360*PI)/(2*n*180));
    double a = (l/2)/(tan(angRad));

    printf("%lf", semiper*a);

    return 0;
}
