//
// Created by Anatejl on 19.06.2024.
//

#include "handler.h"
#include <stdlib.h>

//void* application_init_array(void* data){
//
//    return *;
//
//}

void* application_malloc(int size){

    return malloc(sizeof(array_template)*size);

}

void application_destroy(void* to_free){

    free(to_free);

}

