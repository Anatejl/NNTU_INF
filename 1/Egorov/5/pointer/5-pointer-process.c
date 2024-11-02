#include "5-pointer-header.h"

void do_process(Personnel* employees, Aux* aux){

    for (int i = 0; i < HR_COUNT; ++i) {

        for (int j = 0; j < DEPT_COUNT; ++j) {
            
            if (employees[i].department == aux->known_departments[j]) {
                
                aux->department_counts[j]++;
                break;
            
            }
        }
    }
} 