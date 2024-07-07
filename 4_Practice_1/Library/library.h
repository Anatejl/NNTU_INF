#pragma once
#ifndef NNTU_LIBRARY_H
#define NNTU_LIBRARY_H

#include <stdbool.h>
#include <string.h>

#define MAX_NAME_SIZE 32
#define MIN_VAL (-999999999)

typedef struct Library_template{
    int code;
    int UDK;
    char author[MAX_NAME_SIZE];
    char book_name[MAX_NAME_SIZE];
    int year;
    bool inplace;
}Library_template;

bool library_fill(Library_template* p_library);

#endif //NNTU_LIBRARY_H
