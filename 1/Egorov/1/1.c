#include <stdio.h>
#include <stdbool.h>
#include "1.h"

void get_input(Variables *p_var){

    printf("Input n: ");
    scanf("%lf", &p_var->n);

    printf("Input a1: ");
    scanf("%lf", &p_var->a1);

    printf("Input d (sequence diviation): ");
    scanf("%lf", &p_var->d);

}

void do_process(Variables* p_var){

    p_var->summ = p_var->n/2*(2*p_var->a1+(p_var->n-1)*p_var->d);

}

void do_output(Variables *p_var){

    printf("Summ is: %.f\n", p_var->summ);

}

int main(){

    Variables var;

    get_input(&var);
    do_process(&var);
    do_output(&var);

    return 0;

}