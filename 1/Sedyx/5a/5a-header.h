#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define LABS 4

typedef struct {
    char name[50];
    int marks[LABS];
} Student;

void do_input(Student students[], int *totalStudents);
void do_process(Student students[], int totalStudents, int students_with_debts[], int *debtCount);
void do_output(Student students[], int students_with_debts[], int debtCount);

#endif
