//application.h
//
// Created by Anatejl on 15.01.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include "vector.h"

struct Application {

    Vector initial;
    Vector final;
    unsigned R;
    unsigned n;

};

//исполнение
int appRun(Application& app);

#endif //NNTU_APPLICATION_H
