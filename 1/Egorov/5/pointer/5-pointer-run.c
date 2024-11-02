#include "5-pointer-header.h"

int do_run(Personnel* employees, Aux* aux){

    do_input(employees, aux);
    do_process(employees, aux);
    do_output(employees, aux);

    return 0;

}