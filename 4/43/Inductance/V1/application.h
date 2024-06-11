//
// Created by l3t on 11.06.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <utility>

struct Application{
    int cin_read;
    int cin_read_last;
    std::pair <int, int> max;
    std::pair <int, int> prev_max;

    int threshold;
    int iteration;

};

int app_run(Application &app);
bool app_get_threshold(Application &app);
bool app_get_another(Application &app);
bool app_evaluate(Application &app);
bool app_give_output(Application &app);


#endif //NNTU_APPLICATION_H
