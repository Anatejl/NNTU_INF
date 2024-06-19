//
// Created by Anatejl on 19.06.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include "handler.h"

typedef struct Application{

    int one[3];
    int two;

}Application;

int app_run(void* raw_app);


#endif //NNTU_APPLICATION_H