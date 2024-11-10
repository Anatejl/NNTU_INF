#include <stdio.h>

int main(){

    double a, b, c;
    double min, max, summ;

    printf("Input a:\n");
    scanf("%lf", &a);

    printf("Input b:\n");
    scanf("%lf", &b);

    printf("Input c:\n");
    scanf("%lf", &c);

    min = max = a;

    if(b < min){
        min = b;        
    }
    if(c < min){
        min = c;        
    }

    if(b > max){
        max = b;        
    }
    if(c > max){
        max = c;        
    }

    summ = min + max;

    printf("SUMM IS: %.f\n", summ);

    return 0;
}