//
// Created by l3t on 11.06.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <utility>

typedef bool (*Callback)(void *object);
bool operation(Callback callback, void *data);

struct Application {
    int cin_read;
    std::pair<int, int> max;
    int threshold;
    int iteration = 1;
};

int app_run(Application &app);
bool app_get_threshold(void *raw_app);
bool app_get_another(void *raw_app);
bool app_evaluate(void *raw_app);
bool app_give_output(void *raw_app);

#endif //NNTU_APPLICATION_H
