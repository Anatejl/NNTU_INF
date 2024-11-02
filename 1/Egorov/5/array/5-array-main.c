#include "5-array-header.h"

int main(){

    Personnel employees[HR_COUNT]; 

    int known_departments[DEPT_COUNT] = {101, 102, 103, 104};
    int department_counts[DEPT_COUNT] = {0}; 

    // Fill the array with user input by calling get_input() for each employee
    for (int i = 0; i < HR_COUNT; ++i) {

        printf("\n--- Enter details for employee %d ---\n", i + 1);
        employees[i] = get_input();

    }

    do_process(employees, known_departments, department_counts);

    do_output(known_departments, department_counts);

    return 0;
}