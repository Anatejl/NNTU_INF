//
// Created by Anatejl on 15.10.2022.
//

#include <stdio.h>
#include <stdbool.h>
//#include <sys/wait.h>


int main(){

    bool needContinue = true;
    double leftOperand, rightOperand;
    char operation;
    char y;
    char n;

    while (needContinue) {

        Calc:
        {
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
                goto ASK;
            } else {
                printf("sasi\n");
                goto ASK;
            }
        }
    }
    ASK:
    {
        char userAnswer;
        printf("ESHE? :\n");
        scanf_s("%c", &userAnswer);
        needContinue = userAnswer;
        switch (userAnswer){
            case 'true':
                goto Calc;
            default:
                return 0;
        }
    }
}