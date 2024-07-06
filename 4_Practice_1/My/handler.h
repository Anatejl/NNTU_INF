//
// Created by Anatejl on 19.06.2024.
//

#ifndef NNTU_HANDLER_H
#define NNTU_HANDLER_H

#define NAME_MAX 25

typedef struct array_template{

    char starting_point[NAME_MAX];
    char ending_point[NAME_MAX];
    int code;

}array_template;

int handler_get_size_of_an_array(void* file_name);
char** handler_init_file (void* file_name);
void* handler_init_array(int to_create);


#endif //NNTU_HANDLER_H
