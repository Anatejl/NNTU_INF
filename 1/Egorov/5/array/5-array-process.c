#include "5-array-header.h"

void do_process(Personnel employees[], int known_departments[], int department_counts[]) {

    for (int i = 0; i < HR_COUNT; ++i) {

        for (int j = 0; j < DEPT_COUNT; ++j) {
            
            if (employees[i].department == known_departments[j]) {
                
                department_counts[j]++;
                break;
            
            }
        
        }
    
    }
}