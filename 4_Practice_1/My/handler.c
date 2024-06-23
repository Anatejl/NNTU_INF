//
// Created by Anatejl on 19.06.2024.
//

#include "handler.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HOLDER_MAX 32
void application_clear_array(int limit, char* array){

    for(int i = 0; i < limit; ++i){
        array[i] = 0;
    }

}

void* application_init_array(int to_create){

    char *start_end_files[] = { NULL,
                                "array_start_locations.txt",
                                "array_end_locations.txt",};

    char buffer[HOLDER_MAX];

    int lines_start = 0, lines_end = 0;

    application_clear_array((int)HOLDER_MAX, buffer);

    //read start file
    FILE *f_start, *f_end;
    f_start = fopen(start_end_files[1], "r");
    //char *p_start = malloc(sizeof(f_start)/sizeof (char));
    //free(p_start);
    while(fgets(buffer, HOLDER_MAX, f_start)){
        //printf("%s", buffer);
        //application_clear_array((int)HOLDER_MAX, buffer);
        ++lines_start;
    }
    printf("%d", lines_start);
    fclose(f_start);

    char* p_store_start_lines = malloc(lines_start * sizeof(buffer));
    f_start = fopen("array_start_locations.txt", "r");

    //char store_start_lines[lines_start] = *(char*)p_store_start_lines;
    char (*store_start_lines)[lines_start] = NULL;

    char ** my_string_array = malloc(sizeof(char*)*10);





    //init array
    array_template* p_array = (array_template*) malloc(to_create * sizeof(array_template));
    p_array -> code = 2;

    //fill array
    for(int i = 0; i < to_create; ++i){

        p_array[i].code = i;

        //printf("%d\n", p_array[i].code);
    }


    return p_array;

}

void application_destroy(void* to_free){

    free(to_free);

}

