//
// Created by Anatejl on 01.07.2024.
//

#ifndef NNTU_LIBRARY_H
#define NNTU_LIBRARY_H

#include <string.h>
#include <stdbool.h>

#define MAX_NAME_SIZE 32


typedef struct Library_template{

    int code;
    int UDK;
    char author[MAX_NAME_SIZE];
    char book_name[MAX_NAME_SIZE];
    int year;
    bool inplace;

}Library_template;

char search_string[MAX_NAME_SIZE];

bool fill_library(Library_template* p_library, int count);
#endif //NNTU_LIBRARY_H
