//
// Created by Anatejl on 01.07.2024.
//
#include <stdio.h>
#include "library.h"

int main(int argc, char* argv[]){

    //ASSUME WE HAVE 25 BOOKS
    int count = 25;
    Library_template library[count];
    fill_library(library, count);

    printf("Enter desired author's name:\n");
    fgets(search_string, MAX_NAME_SIZE, stdin);


    return 0;
}