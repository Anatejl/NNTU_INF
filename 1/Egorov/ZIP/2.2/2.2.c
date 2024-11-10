#include <stdio.h>

int main(){

    double x[6];
    double sum = 0;

    for (int i = 0; i < 6; ++i){

        printf("Enter value of an x[%d]:\n", i);
        scanf("%lf", &x[i]);
        sum += x[i];

    }

    printf("Summ is: %.2lf\n", sum);

    return 0;
}