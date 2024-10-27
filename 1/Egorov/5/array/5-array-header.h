#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>

#define NAME_MAX_SIZE 50
#define HR_COUNT 1

typedef struct Personnel{

    char name[NAME_MAX_SIZE];
    char position[NAME_MAX_SIZE];
    int id;
    int department;

}Personnel;

Personnel get_input(Personnel personnel);
void do_process(Personnel personnel);
void do_output(Personnel personnel);

#endif //HEADER_H