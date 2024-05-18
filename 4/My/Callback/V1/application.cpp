//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include <iostream>

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
    //std::cout << "tempapp - appinitKAL "<< &tempApp << std::endl;

    int tempDataReadFromCIN;
    if(!std::cin.eof()) {
        std::cin >> tempDataReadFromCIN;
    }
    else{
        return false;
    }
    tempApp.valueArray.push_back(tempDataReadFromCIN);

    if(std::cin.eof()) {

        std::cout << "Input array has been successfully processed." << std::endl;
        std::cout << "Provided vector consists of " << tempApp.valueArray.size() << " entries." << std::endl;
        std::cout << "Values as follows:" << std::endl;

        for (int i: tempApp.valueArray) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

    }

    return true;
}

bool appProcessDataIntoFinalResult(void *app) {

    Application &tempApp = *(Application *) app;

    if (
    (tempApp.processIndex != vectorGetSize(tempApp.valueArray)-1 && tempApp.valueArray[tempApp.processIndex] > tempApp.valueArray[tempApp.processIndex + 1])
        ||
    (tempApp.processIndex == vectorGetSize(tempApp.valueArray)-1 )
    ){
        if (tempApp.tempConsequenceStreak > tempApp.finalConsequenceStreak &&
        (tempApp.valueArray[tempApp.processIndex] -tempApp.valueArray[tempApp.processIndex - (tempApp.tempConsequenceStreak-1)] > tempApp.constD ||
        tempApp.valueArray[tempApp.processIndex] -tempApp.valueArray[tempApp.processIndex - tempApp.tempConsequenceStreak] > tempApp.constD))
        {
            if((tempApp.finalLeft == INT_MAX && tempApp.finalRight == INT_MAX) &&
               (tempApp.processIndex == tempApp.tempConsequenceStreak || tempApp.processIndex == tempApp.tempConsequenceStreak+1)){
                tempApp.finalLeft = tempApp.processIndex - tempApp.tempConsequenceStreak;
            }
            else{
                tempApp.finalLeft = tempApp.processIndex - (tempApp.tempConsequenceStreak-1);
            }
            tempApp.finalRight = tempApp.processIndex;
            tempApp.finalConsequenceStreak = tempApp.tempConsequenceStreak;
        }
        tempApp.tempConsequenceStreak = 0;
    }
    ++tempApp.tempConsequenceStreak;
    ++tempApp.processIndex;

    if (tempApp.finalLeft == INT_MAX && tempApp.finalRight == INT_MAX && vectorGetSize(tempApp.valueArray) == 1) {
        tempApp.finalLeft = 0;
        tempApp.finalRight = 0;
    }



    return true;
}

bool appGetOutputToUser(void* app) {

    Application &tempApp = *(Application *) app;

    std::cout << std::endl << tempApp.finalLeft << " - Left Index" << std::endl;
    std::cout << tempApp.finalRight << " - Right Index" << std::endl;

    return true;
}

int appRun() {

    //Application &tempApp = app;
    Application app;
    //std::cout << "tempapp - apprun "<< &tempApp << std::endl;

    // 1 - Get D  const
    if (!operation(&appGetConstantD, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    // 2 - Read through cin
    while(!std::cin.eof()) {

        if (!operation(&appInitializeData, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

    }

    // 3 - Process data
    for(int i = 0; i < app.valueArray.size(); ++i){

       operation(&appProcessDataIntoFinalResult, &app);

       if (i == app.valueArray.size()-1 && app.finalLeft == INT_MAX && app.finalRight == INT_MAX){
           std::cout << "DATA INPUT FAILURE." << std::endl;
           return 1;
       }
    }

    // 4 - Display result
    operation(&appGetOutputToUser, &app);

    return 0;
}
