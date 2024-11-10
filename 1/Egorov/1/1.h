#ifndef NNTU_1
#define NNTU_1

#include <stdio.h>

typedef struct Variables{

    double n, d, a1;
    double summ;

}Variables;

void get_input(Variables *var);
void do_process(Variables *var);
void do_output(Variables *var);

#endif //NNTU_1