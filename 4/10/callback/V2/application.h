//
// Created by Anatejl on 15.04.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

struct Application {

    int i = 1;
    int cin_read;
    int constS;
    int finalSum = 0;
};

typedef bool (*Callback)(void *data);
bool operation(Callback callback, void *data);

int appRun();
bool appGetRead(void *data);
bool appGetS(void *data);
bool appProcess(void *data);
bool appMakeAnOutput(void *data);

#endif //NNTU_APPLICATION_H
