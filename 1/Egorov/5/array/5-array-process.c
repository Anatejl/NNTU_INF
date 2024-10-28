#include "5-array-header.h"

void count_employees_by_department(Personnel employees[], int employee_count) {

    // Define known departments
    int known_departments[DEPT_COUNT] = {101, 102, 103, 104};
    int department_counts[DEPT_COUNT] = {0}; 
    
    // Count employees in each department
    for (int i = 0; i < employee_count; i++) {
        int dept = employees[i].department;
        for (int j = 0; j < DEPT_COUNT; j++) {
            if (dept == known_departments[j]) {
                department_counts[j]++;
                break;
            }
        }
    }

    // Print the results
    printf("\nNumber of employees in each department:\n");
    for (int i = 0; i < DEPT_COUNT; i++) {
        printf("Department %d has %d employee(s)\n", known_departments[i], department_counts[i]);
    }
}