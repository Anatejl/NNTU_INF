//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include "vector.h"
#include <iostream>
#include <utility>

bool operation(Callback callback, void *data) {
    return (*callback)(data);
}

bool appGetConstantD(void *app) {

    Application &tempApp = *(Application *) app;

    std::cout << "Input a D constant to compare:" << std::endl;
    std::cin >> tempApp.constD;
    std::cout << tempApp.constD << std::endl;

    return true;
}

bool appInitializeData(void *app) {

    Application &tempApp = *(Application *) app;

    int tmp;
    if(std::cin.eof()) {
        return false;
    }
    std::cin >> tmp;
    tempApp.valueArray.value.push_back(tmp);

    std::cout << "Input array has been successfully processed." << std::endl;
    std::cout << "Provided vector consists of " << tempApp.valueArray.value.size() << " entries." << std::endl;
    std::cout << "Values as follows:" << std::endl;

    for (int i: tempApp.valueArray.value) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return true;
}

bool appProcessDataIntoFinalResult(void *app) {

    Application &tempApp = *(Application *) app;

    for (int i = 0; i < vectorGetSize(tempApp.valueArray); ++i) {
        if (
        (i != vectorGetSize(tempApp.valueArray)-1 && tempApp.valueArray.value[i] > tempApp.valueArray.value[i + 1])
            ||
        (i == vectorGetSize(tempApp.valueArray)-1 )
        ){

            if (tempApp.tempConsequenceStreak > tempApp.finalConsequenceStreak &&
            (tempApp.valueArray.value[i] -tempApp.valueArray.value[i - (tempApp.tempConsequenceStreak-1)] > tempApp.constD ||
            tempApp.valueArray.value[i] -tempApp.valueArray.value[i - tempApp.tempConsequenceStreak] > tempApp.constD))
            {
                if((tempApp.finalLeft == INT_MAX && tempApp.finalRight == INT_MAX) &&
                   (i == tempApp.tempConsequenceStreak || i == tempApp.tempConsequenceStreak+1)){
                    tempApp.finalLeft = i - tempApp.tempConsequenceStreak;
                }
                else{
                    tempApp.finalLeft = i - (tempApp.tempConsequenceStreak-1);
                }
                tempApp.finalRight = i;
                tempApp.finalConsequenceStreak = tempApp.tempConsequenceStreak;
            }

            tempApp.tempConsequenceStreak = 0;
        }

        ++tempApp.tempConsequenceStreak;
    }

    if (tempApp.finalLeft == INT_MAX && tempApp.finalRight == INT_MAX && vectorGetSize(tempApp.valueArray) == 1) {
        tempApp.finalLeft = 0;
        tempApp.finalRight = 0;
    }

    if (tempApp.finalLeft == INT_MAX && tempApp.finalRight == INT_MAX) {
        return false;
    }

    return true;
}

//bool appGetOutputToUser(Application &app) {
//
//        std::cout << std::endl << app.finalLeft << " - Left Index" << std::endl;
//        std::cout << app.finalRight << " - Right Index" << std::endl;
//
//    return true;
//}

int appRun(void *app) {

    Application &tempApp = *(Application *) app;

    if (!operation(&appGetConstantD, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    while(!std::cin.eof()) {

        bool initData = operation(&appInitializeData, &app);
        if (!initData) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

    }

    return 0;
}
