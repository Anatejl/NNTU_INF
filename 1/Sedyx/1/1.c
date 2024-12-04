#include <stdio.h>

int main(){

    int d = 0;
    long double m = 0.0;

    printf("Input an inch length to convert into meters:\n");
    scanf("%d", &d);

    m = 0.0254 * d;

    printf("Result is: %Lf\n", m);

    return 0;

}