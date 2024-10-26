#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>

#define NAME_MAX_SIZE 500

typedef struct Personnel{

    char name[NAME_MAX_SIZE];
    char position[NAME_MAX_SIZE];
    int id;
    int department;

}Personnel;

#endif //HEADER_H