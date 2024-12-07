#include <stdio.h>
#include "5a-header.h"

int main() {

    int totalStudents;
    Student students[MAX_STUDENTS];
    int students_with_debts[MAX_STUDENTS];
    int debtCount = 0;

    do_input(students, &totalStudents);
    do_process(students, totalStudents, students_with_debts, &debtCount);
    do_output(students, students_with_debts, debtCount);
    
    return 0;
}
