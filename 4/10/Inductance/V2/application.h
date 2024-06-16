//
// Created by Anatejl on 15.04.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

//Data for program to handle.
struct Application {

    int i = 1;
    int cin_read;
    int constS;
    int finalSum = 0;
    int tempSum = 0;
};

// To execute application
int appRun(Application& app);

bool appGetRead(Application &app);
bool appGetS(Application &app);
bool appProcess(Application &app);
bool appMakeAnOutput(Application &app);

#endif //NNTU_APPLICATION_H
