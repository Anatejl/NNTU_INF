#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>

#define NAME_MAX_SIZE 50
#define HR_COUNT 5
#define DEPT_COUNT 4

typedef struct Personnel{

    char name[NAME_MAX_SIZE];
    char position[NAME_MAX_SIZE];
    int id;
    int department;

}Personnel;

typedef struct Company{

    Personnel personnel[HR_COUNT];
    int known_departments[DEPT_COUNT];
    int department_counts[DEPT_COUNT];

}Company;


int do_run(Company* company);
void do_input(Company* company);
void do_process(Company* company);
void do_output(Company* company);


#endif //HEADER_H