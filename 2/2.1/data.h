//
// Created by Anatejl on 03.05.2023.
//

#ifndef NNTU_DATA_H
#define NNTU_DATA_H
#define NAME_MAX_SIZE 25
#include <string.h>

struct data {

    char title[NAME_MAX_SIZE];
    char continent[NAME_MAX_SIZE];
    char population[NAME_MAX_SIZE];
    char area[NAME_MAX_SIZE];

};

struct data AccessCode[21];

#endif //NNTU_DATA_H
