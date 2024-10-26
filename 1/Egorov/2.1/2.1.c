#include <stdio.h>

int main(){

    double a, b, c;
    double min = 99999;
    double max = -99999;
    double summ;

    printf("Input a:\n");
    scanf("%lf", &a);

    printf("Input b:\n");
    scanf("%lf", &b);

    printf("Input c:\n");
    scanf("%lf", &c);

    if(c < min){
        min = c;        
    }
    if(b < min){
        min = b;        
    }
    if(a < min){
        min = a;        
    }

    if(c > max){
        max = c;        
    }
    if(b > max){
        max = b;        
    }
    if(a > max){
        max = a;        
    }

    summ = min + max;

    printf("SUMM IS: %.f\n", summ);

    return 0;
}