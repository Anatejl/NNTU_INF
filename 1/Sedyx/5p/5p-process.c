#include "5p-header.h"

void do_process(Student *students, int totalStudents, int *students_with_debts, int *debtCount) {
    *debtCount = 0;
    for (int i = 0; i < totalStudents; i++) {
        int hasDebt = 0;
        for (int j = 0; j < LABS; j++) {
            if (students[i].marks[j] == 0) {
                hasDebt = 1;
                break;
            }
        }
        if (hasDebt) {
            students_with_debts[*debtCount] = i;
            (*debtCount)++;
        }
    }
}
