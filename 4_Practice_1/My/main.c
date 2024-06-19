//
// Created by Anatejl on 19.06.2024.
//

#include <stdio.h>
#include "application.h"

/*Вывести на экран информацию о маршруте, номер которого
введен с клавиатуры. Если таких маршрутов нет, вывести на
экран соответствующее сообщение. Элементы структуры:
название начального пункта маршрута, название конечного
пункта маршрута, номер маршрута.*/

int main(int argc, char *argv[]){

    Application app;
    Application *p_app = &app;

    int ret = app_run(p_app);

    return ret;
}