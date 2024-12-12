// VAR 3
#include <stdio.h>
#include <math.h>

int main(){

    int n, R;
    long double S; 

    printf("Input n: ");
    scanf("%d", &n);
    
    printf("Input R: ");
    scanf("%d", &R);
    
    S = (1/2*n*R^2)*(sin(2*M_PI/n));

    printf("Result is: %Lf\n", S);

    return 0;
}