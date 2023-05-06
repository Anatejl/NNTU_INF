//data.h
//
// Created by Anatejl on 03.05.2023.
//

#ifndef NNTU_DATA_H
#define NNTU_DATA_H
#define NAME_MAX_SIZE 25

#include <string.h>

//Declaring necessary structures.
struct data {

    char title[NAME_MAX_SIZE];
    char continent[NAME_MAX_SIZE];
    int continentCode;
    char population[NAME_MAX_SIZE];
    long area;

};

//Providing variable which will allow us to access structure,
// assigning number, which prescribes size of structure.
struct data AccessCode[21];

//Declaring processing array, is which we will store calculated data.
struct arrFinal {

    int ID;

};

//Since main data array is 21 line long, we will use same number for processing array.
struct arrFinal arrayFinal[21];

#endif //NNTU_DATA_H
