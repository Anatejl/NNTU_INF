//
// Created by Anatejl on 04.11.2022.
//
// Task 3 - Var 3

#include <stdio.h>
#include <math.h>

double xi;

int one(){
    double i, x;

    printf("Input two numbers (x, i): ");
    scanf_s("%lf", &x);
    scanf_s("%lf", &i);

    xi = pow(i, 2) * sin(i);
    //printf("%lf", xi);

    return xi;
}

int main(){

    one();

    double n = 4, sum = 0;

    for (; xi <= n ; xi++) {
        sum += 1;
    }

    double xcp = (1/n) * sum;
    printf("%.3f", xcp);

    return 0;
}