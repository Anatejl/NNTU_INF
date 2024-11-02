#include "5-array-header.h"

void do_output(int known_departments[], int department_counts[]){

    // Print the results
    printf("\nNumber of employees per department:\n");

    for (int i = 0; i < DEPT_COUNT; ++i) {
        
        printf("Department %d has %d employee(s)\n", known_departments[i], department_counts[i]);
    
    }
}