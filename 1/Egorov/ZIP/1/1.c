#include <stdio.h>

int main(){

    double n, d, a1, summ;

    printf("Input n: ");
    scanf("%lf", &n);

    printf("Input a1: ");
    scanf("%lf", &a1);

    printf("Input d (sequence diviation): ");
    scanf("%lf", &d);

    summ = n/2*(2*a1+(n-1)*d);

    printf("Summ is: %.f\n", summ);  

    return 0;
}