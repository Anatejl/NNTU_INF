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

void* application_init_array(int to_create);

void application_clear_array(int limit, char* array);

void application_destroy(void* to_free);


#endif //NNTU_HANDLER_H
