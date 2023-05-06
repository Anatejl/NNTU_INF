//data.h
//
// Created by Anatejl on 03.05.2023.
//

#ifndef NNTU_DATA_H
#define NNTU_DATA_H

//Following values are based on properties of connected database or array.
#define NAME_MAX_SIZE 25
#define ARRAY_MAX_SIZE 21
#define INPUT_MAX_SIZE 16

#include <string.h>

//Declaring necessary structures.
typedef struct  {

    char title[NAME_MAX_SIZE];
    char continent[NAME_MAX_SIZE];
    int continentCode;
    char population[NAME_MAX_SIZE];
    long area;

} data;

//Providing variable which will allow us to access structure,
// assigning number, which prescribes size of structure.
data AccessCode[ARRAY_MAX_SIZE];

//Declaring processing array, is which we will store calculated data.
typedef struct  {

    int ID;

} arrFinal;

//Since main data array length corresponds to ARRAY_MAX_SIZE,
// we're passing same value to processing array, to iterate through main array.
arrFinal arrayFinal[ARRAY_MAX_SIZE];

#endif //NNTU_DATA_H
