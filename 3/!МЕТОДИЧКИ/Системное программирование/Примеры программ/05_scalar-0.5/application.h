//Интерфейс АТД "Приложение"
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "vector.h"

struct Application {
    Vector first;
    Vector second;
};

//исполнение
int appRun(Application& app);

#endif
