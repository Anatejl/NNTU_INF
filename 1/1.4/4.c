//
// Created by Anatejl on 08.10.2022.
//
// Calculator

#include <stdio.h>
#include <stdbool.h>

int main(){

    while( 0 < 1 ) {
        double leftOperand, rightOperand;
        char operation;
        printf("Input expression: ");
        scanf_s("%lf", &leftOperand);
        scanf_s("%c", &operation);
        scanf_s("%lf", &rightOperand);

        bool error = false;
        double result = 0;
        switch (operation) {
            case '+' :
                result = leftOperand + rightOperand;
                break;
            case '-':
                result = leftOperand - rightOperand;
                break;
            case '*':
                result = leftOperand * rightOperand;
                break;
            case '/':
                result = leftOperand / rightOperand;
                break;
            default:
                error = true;
        }
        if (!error) {
            printf("Result: %f\n", result);
        } else {
            printf("sasi\n");
        }
    }
}