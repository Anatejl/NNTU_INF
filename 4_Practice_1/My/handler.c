//
// Created by Anatejl on 19.06.2024.
//

#include "handler.h"
#include <stdlib.h>
#include <stdio.h>

void* application_init_array(int to_create){

    char buffer[256];
    //read start file
    int lines_start = 0;
    FILE *f_start, *f_end;
    f_start = fopen("array_start_locations.txt", "r");
    //char *p_start = malloc(sizeof(f_start)/sizeof (char));
    //free(p_start);

    fread_s()

    fclose(f_start);




    //init array
    array_template* p_array = (array_template*) malloc(to_create * sizeof(array_template));

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

