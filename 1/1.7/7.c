//
// Created by Anatejl on 30.10.2022.
//
// Task 2.1 - Var 12

#include <stdio.h>

int main() {

    double x1, x2, x3;

    char userAnswer = 'y';

    while (userAnswer == 'y') {
        printf("Input three numbers (x1, x2, x3): ");
        scanf_s("%lf", &x1);
        scanf_s("%lf", &x2);
        scanf_s("%lf", &x3);

        if (x1 < x2 && x1 < x3) {
            printf("%lf", x1);
        } else if (x1 > x2 && x2 < x3) {
            printf("%lf", x2);
        } else {
            printf("%lf", x3);
        }
        printf("\n");
        printf("Again? (y/n) :\n");
        scanf_s("%s", &userAnswer);
        printf("\n");
    }
    return 0;
}