#include "5-pointer-header.h"

void do_output(Personnel* employees, Aux* aux){

    printf("\nNumber of employees per department:\n");

    for (int i = 0; i < DEPT_COUNT; ++i) {
        
        printf("Department %d has %d employee(s)\n", aux->known_departments[i], aux->department_counts[i]);
    
    }

}