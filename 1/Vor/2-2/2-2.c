// VAR 20
#include <stdio.h>
#include <math.h>

int main(){

    double a = 1000, b = 1;
    double a_new, b_new;

    for(int i = 0; i < 6; ++i){

        if (i == 0){

            printf("a = %.2lf, b = %.2lf\n", a, b);

        }
        else{

            a_new = (a+b)/2;
            b_new = (sqrt(a*b));
            a = a_new, b = b_new;

            printf("a = %.2lf, b = %.2lf\n", a_new, b_new);

        }

    }

    return 0;
}