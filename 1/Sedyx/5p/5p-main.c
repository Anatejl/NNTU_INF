#include "5p-header.h"

int main() {
    
    int totalStudents;
    int debtCount = 0;

    printf("Enter the total number of students: ");
    scanf("%d", &totalStudents);
    getchar();

    Student *students = (Student *)malloc(totalStudents * sizeof(Student));
    int *students_with_debts = (int *)malloc(totalStudents * sizeof(int));

    if (students == NULL || students_with_debts == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    do_input(students, totalStudents);
    do_process(students, totalStudents, students_with_debts, &debtCount);
    do_output(students, students_with_debts, debtCount);

    free(students);
    free(students_with_debts);

    return 0;
}
