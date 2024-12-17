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
    
    S = (0.5*n*R*R)*(sin(2*M_PI/n));

    printf("Result is: %Lf\n", S);

    return 0;
}