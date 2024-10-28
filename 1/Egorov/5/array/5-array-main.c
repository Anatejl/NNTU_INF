#include "5-array-header.h"


int main(){

    Personnel employees[HR_COUNT]; // Array to hold multiple employees

    // Fill the array with user input by calling get_input() for each employee
    for (int i = 0; i < HR_COUNT; i++) {
        printf("\n--- Enter details for employee %d ---\n", i + 1);
        employees[i] = get_input();
    }

    // Count the number of employees in each predefined department
    count_employees_by_department(employees, HR_COUNT);
    return 0;
}