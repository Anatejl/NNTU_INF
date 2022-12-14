//
// Created by Anatejl on 04.11.2022.
//
// Task 3 - Var 3

#include <stdio.h>
#include <math.h>

double one() {

    double i, x;

    printf("Input two numbers (x, i): ");
    scanf_s("%lf", &x);
    scanf_s("%lf", &i);

    return pow(i, 2) * sin(i);
}

double two() {

    double xi = one();
    double n = 4, sum = 0;

    for (; xi <= n; xi++) {
        sum += 1;
    }
    double xcp = (1 / n) * sum;

    return xcp;
}

int main() {

    double sum;
    char userAnswer = 'y';

    while (userAnswer == 'y') {
        sum = two();
        printf("Final: %.3f", sum);

        printf("\n");
        printf("Again? (y/n) :\n");
        scanf_s("%s", &userAnswer);
        printf("\n");
    }

    return 0;
}