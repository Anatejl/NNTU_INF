//
// Created by Anatejl on 30.10.2022.
//
// Task 2.2 - Var 7

#include <stdio.h>
#include <math.h>

int main() {

    double a, b, l;
    char userAnswer = 'y';

    while (userAnswer == 'y') {

        printf("Input three numbers (a, b, l): ");
        scanf_s("%lf", &a);
        scanf_s("%lf", &b);
        scanf_s("%lf", &l);

        for (double x = -1.5; x <= 1.51; x += 0.1) {

            double S;

            printf("%s", "\n");

            if (x < -1.2) {
                S = a * x * sin(x) + b * log(x + 10);
            } else if (-1.2 <= x <= 0.3) {
                S = -2 * (a + pow(l, -2 * x));
            } else {
                S = pow(x, -2) * sin(1.0 / x);
            }
            printf("%.1f: %lf", x, S);
        }

        printf("\n");
        printf("Again? (y/n) :\n");
        scanf_s("%s", &userAnswer);
        printf("\n");
    }

    return 0;
}