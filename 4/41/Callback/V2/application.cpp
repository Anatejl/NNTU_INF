//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include <iostream>
#include <cmath>

bool operation(Callback callback, void *data) {
    return (*callback)(data);
}

bool appGetConstantK(void *app) {

    Application &tempApp = *(Application *) app;

    std::cout << "Input a K constant:" << std::endl;
    std::cin >> tempApp.constK;
    std::cout << tempApp.constK << std::endl;
    return true;
}

bool appGetCircleDimensions(void *app) {

    Application &tempApp = *(Application *) app;

    std::cout << "Input CENTER 'X Y' coordinate of circle " << std::endl;
    std::cin >> tempApp.circleCenter.first >> tempApp.circleCenter.second;

    std::cout << "Input EDGE 'X Y' coordinate of circle " << std::endl;
    std::cin >> tempApp.circleEdge.first >> tempApp.circleEdge.second;

    tempApp.circleR = sqrt(
        pow(tempApp.circleEdge.first - tempApp.circleCenter.first, 2) +
        pow(tempApp.circleEdge.second - tempApp.circleCenter.second, 2));

    return true;
}

bool appInitializeData(void *app) {

    Application &tempApp = *(Application *) app;

    tempApp.initialArray = vectorInitialArrayInitialize(tempApp.initialArray);
    std::cout << "Input array has been processed." << std::endl;

    return true;
}

bool appProcessXYArrayIntoRArray(void *app) {

    Application &tempApp = *(Application *) app;

    int tempIterativeCircleR = sqrt(
        pow(tempApp.initialArray.row[tempApp.temp_var.first].first - tempApp.circleCenter.first, 2) +
        pow(tempApp.initialArray.row[tempApp.temp_var.first].second - tempApp.circleCenter.second, 2));
    tempApp.finalArray.row.push_back(tempIterativeCircleR);

    return true;
}

bool appProcessFinalResult(void *app) {

    Application &tempApp = *(Application *) app;

    if(tempApp.finalArray.row[tempApp.temp_var.second] >= tempApp.circleR || tempApp.temp_var.second == tempApp.finalArray.row.size()-1) {
        if(tempApp.temp_var.tempSeqStreak >= tempApp.constK) {
            tempApp.temp_var.tempFinal.push_back(tempApp.temp_var.column);
            for(int j = tempApp.temp_var.tempSeqStreak; j > 0; --j) {
                tempApp.temp_var.tempFinal[tempApp.temp_var.tempFinal.size()-1].push_back(tempApp.temp_var.second-j);
            }
        }
        tempApp.temp_var.tempSeqStreak = 0;
    }

    else {
        ++tempApp.temp_var.tempSeqStreak;
    }

    if(tempApp.temp_var.second == tempApp.finalArray.row.size()-1) {
        tempApp.finalArray.insideTheCircleGroup = tempApp.temp_var.tempFinal;
    }

    return true;
}

bool appGetOutputToUser(void *app) {

    Application &tempApp = *(Application *) app;

    if (tempApp.temp_var.third == 0) {
        std::cout << "Initial data unfolds into " << tempApp.finalArray.insideTheCircleGroup.size() << " groups." << std::endl
        << "Here they are: "<< std::endl;
    }

    std::cout << "Group " << tempApp.temp_var.third+1 << ": ";
    for(int &j : tempApp.finalArray.insideTheCircleGroup[tempApp.temp_var.third]) {
        std::cout << j << " ";
    }
    std::cout << std::endl;

    return true;
}

int appRun() {

    Application app;

    if (!operation(&appGetConstantK, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!operation(&appGetCircleDimensions, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!operation(&appInitializeData, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    for (;app.temp_var.first < app.initialArray.row.size(); ++app.temp_var.first) {
        if (!operation(&appProcessXYArrayIntoRArray, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
    }

    for (;app.temp_var.second  < app.finalArray.row.size(); ++app.temp_var.second) {
        if (!operation(&appProcessFinalResult, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
    }

    for(;app.temp_var.third < app.finalArray.insideTheCircleGroup.size(); ++app.temp_var.third) {
        if (!operation(&appGetOutputToUser, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
    }

    return 0;
}