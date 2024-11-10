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

Personnel get_input();
void do_process(Personnel employees[], int known_departments[], int departments_count[]);
void do_output(int known_departments[], int departments_count[]);

#endif //HEADER_H