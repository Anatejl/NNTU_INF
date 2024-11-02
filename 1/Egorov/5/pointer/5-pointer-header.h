#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>

#define NAME_MAX_SIZE 50
#define HR_COUNT 2
#define DEPT_COUNT 4

typedef struct Personnel{

    char name[NAME_MAX_SIZE];
    char position[NAME_MAX_SIZE];
    int id;
    int department;

}Personnel;

typedef struct Aux{

    int known_departments[DEPT_COUNT];
    int department_counts[DEPT_COUNT];

}Aux;

int do_run(Personnel* employees, Aux* aux);
void do_input(Personnel* employees, Aux* aux);
void do_process(Personnel* employees, Aux* aux);
void do_output(Personnel* employees, Aux* aux);


#endif //HEADER_H