//
// Created by Anatejl on 19.06.2024.
//

#include "handler.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>

#define HOLDER_MAX 32
void handler_clear_array(int limit, char* array){

    for(int i = 0; i < limit; ++i){
        array[i] = 0;
    }

}

char** handler_init_start_list (void* file_name){
    //total lines in file counter
    int line_count = 0;
    //malloc buffer
    char *buffer = malloc(HOLDER_MAX*sizeof(char));

    //var for readded line
    char *retrieved_line;

    //malloc for complete array
    char** resulting_array = malloc(sizeof (char*)*line_count);

    //we open file
    FILE *f_start = fopen(file_name,"r");

    if(f_start != NULL){
        char* tempStr = malloc(HOLDER_MAX * sizeof (char));
        do{
            tempStr = fgets(buffer,HOLDER_MAX, f_start);
            if(tempStr != NULL){
                ++line_count;
            }
        } while (tempStr != NULL);
        free(tempStr);

        fseek(f_start, 0, SEEK_SET);

        for(int i = 0; i < line_count; ++i){
            resulting_array[i] = malloc(HOLDER_MAX*sizeof (char));
            retrieved_line = fgets(resulting_array[i], HOLDER_MAX, f_start);
            if(retrieved_line != NULL){
                printf("%s\n", resulting_array[i]);
            }
        }
        free(retrieved_line);
        fclose(f_start);
    }
    else{
        printf("ER:011 - Error while opening starting locations text file.\n");
    }
    free(buffer);
    return resulting_array;
}
void* handler_init_array(int to_create){

    char *start_end_files[] = { NULL,
                                "array_start_locations.txt",
                                "array_end_locations.txt"};



    char** starting_locations = handler_init_start_list(start_end_files[1]);
    //handler_clear_array((int) HOLDER_MAX, buffer);

//    //read start file
//    FILE *f_start, *f_end;
//    f_start = fopen(start_end_files[1], "r");
//    //char *p_start = malloc(sizeof(f_start)/sizeof (char));
//    //free(p_start);
//    while(fgets(buffer, HOLDER_MAX, f_start)){
//        //printf("%s", buffer);
//        //handler_clear_array((int)HOLDER_MAX, buffer);
//        ++lines_start;
//    }
//    printf("%d", lines_start);
//    fclose(f_start);
//
//    char* p_store_start_lines = malloc(lines_start * sizeof(buffer));
//    f_start = fopen("array_start_locations.txt", "r");
//
//    //char store_start_lines[lines_start] = *(char*)p_store_start_lines;
//    char (*store_start_lines)[lines_start] = NULL;
//
//    char ** my_string_array = malloc(sizeof(char*)*10);

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

void handler_destroy(void* to_free){

    free(to_free);

}

