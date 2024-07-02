//
// Created by Anatejl on 01.07.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include "library.h"
#include <stdio.h>

#define BOOKS_COUNT 25

typedef struct App{
    Library_template library[BOOKS_COUNT];
    char search_string[MAX_NAME_SIZE];
    int count;
    int found_index;
}App;

bool app_get_input(void* p_app);
bool app_process(void* p_app);
bool app_get_output(void* p_app);
bool app_rerun(void* p_app);

#endif //NNTU_APPLICATION_H
