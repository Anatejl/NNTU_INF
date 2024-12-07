#include "5p-header.h"

void do_output(Student *students, int *students_with_debts, int debtCount) {
    if (debtCount > 0) {
        printf("\nStudents with debts:\n");
        for (int i = 0; i < debtCount; i++) {
            printf("%s\n", students[students_with_debts[i]].name);
        }
        printf("\nTotal number of students with debts: %d\n", debtCount);
    } else {
        printf("\nNo students have debts.\n");
    }
}
