//
// Created by Anatejl on 30.10.2022.
//
// Task 2.2 - Var 7

#include <stdio.h>
#include <math.h>

int main() {

    double x, a, b;
    char userAnswer = 'y';

    while (userAnswer == 'y') {

        printf("Input three numbers (x, a, b): ");
        scanf_s("%lf", &x);
        scanf_s("%lf", &a);
        scanf_s("%lf", &b);

        if (x < -1.2) {
            double S;
            S = a*x* sin(x) + b * log10(x + 10);
            printf("%ln", S);
        }
        else if ( -1.2 <= x <= 0.3) {

        }


        printf("\n");
        printf("Again? (y/n) :\n");
        scanf_s("%s", &userAnswer);
        printf("\n");
    }

    return 0;
}