//
// Created by Anatejl on 30.10.2022.
//
// Task 1 - Var 13

#include <stdio.h>

int main() {

    double a, b, c, r;
    double S;

    char userAnswer = 'y';

    while (userAnswer == 'y') {
        printf("Input triangle dimensions (a, b, c, r): ");
        scanf_s("%lf", &a);
        scanf_s("%lf", &b);
        scanf_s("%lf", &c);
        scanf_s("%lf", &r);

        if (a < 0) {
            printf(" a - can't be null");
            return 0;
        }
        if (b < 0) {
            printf(" b - can't be null");
            return 0;
        }
        if (c < 0) {
            printf(" c - can't be null");
            return 0;
        }
        if (r < 0) {
            printf(" r - can't be null");
            return 0;
        }

        S = ((a + b + c) * r) / 2;

        printf("%lf", S);
        printf("\n");
        printf("Again? (y/n) :\n");
        scanf_s("%s", &userAnswer);
        printf("\n");
    }
    return 0;
}