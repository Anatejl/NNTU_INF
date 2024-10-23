//
// Created by Anatejl on 15.10.2022.
//

#include <stdio.h>
#include <stdbool.h>
//#include <sys/wait.h>


int main() {

    double leftOperand, rightOperand;
    char operation;


    char userAnswer;
    userAnswer = 'y';

    while (userAnswer == 'y') {
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
            return 0;
        }
        printf("ESHE? :\n");
        scanf_s("%s", &userAnswer);
        printf("\n");
    }

}