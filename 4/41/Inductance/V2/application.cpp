//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include "vector.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <numeric>

int appRun(Application &app) {
    if (!appGetConstantK(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appGetCircleDimensions(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appInitializeData(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appProcessXYArrayIntoRArray(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appProcessFinalResult(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

   if (!appGetOutputToUser(app)) {
       std::cout << "DATA INPUT FAILURE." << std::endl;
       return 1;
   }

    return 0;
}

bool appGetConstantK(Application &app) {
    std::cout << "Input a K constant:" << std::endl;
    std::cin >> app.constK;
    std::cout << app.constK << std::endl;
    return true;
}

bool appGetCircleDimensions(Application &app) {
    std::cout << "Input CENTER 'X Y' coordinate of circle " << std::endl;
    std::cin >> app.circleCenter.first >> app.circleCenter.second;

    std::cout << "Input EDGE 'X Y' coordinate of circle " << std::endl;
    std::cin >> app.circleEdge.first >> app.circleEdge.second;

    app.circleR = sqrt(
        pow(app.circleEdge.first - app.circleCenter.first, 2) +
        pow(app.circleEdge.second - app.circleCenter.second, 2));

    return true;
}

bool appInitializeData(Application &app) {

    app.initialArray = vectorInitialArrayInitialize(app.initialArray, app.constK);
    std::cout << "Input array has been processed." << std::endl;

    return true;
}

bool appProcessXYArrayIntoRArray(Application &app) {
    for (int i = 0; i < app.initialArray.row.size(); ++i) {
        int tempIterativeCircleR = sqrt(
            pow(app.initialArray.row[i].first - app.circleCenter.first, 2) +
            pow(app.initialArray.row[i].second - app.circleCenter.second, 2));
        app.finalArray.row.push_back(tempIterativeCircleR);
    }
    return true;
}

bool appProcessFinalResult(Application &app) {

    int tempSeqStreak = 0;
    std::vector<int> column;
    std::vector<std::vector<int>> tempFinal;

    for (int i = 0; i < app.finalArray.row.size(); ++i) {
        if(app.finalArray.row[i] >= app.circleR || i == app.finalArray.row.size()-1) {
            if(tempSeqStreak >= app.constK) {
                tempFinal.push_back(column);
                for(int j = tempSeqStreak; j > 0; --j) {
                    tempFinal[tempFinal.size()-1].push_back(i-j);
                }
            }
            tempSeqStreak = 0;
        }
        else {
            ++tempSeqStreak;
        }
    }

    app.finalArray.insideTheCircleGroup = tempFinal;
    return true;
}

bool appGetOutputToUser(Application &app) {

    std::cout << "Initial data unfolds into " << app.finalArray.insideTheCircleGroup.size() << " groups." << std::endl
    << "Here they are: "<< std::endl;

    for(int i = 0; i < app.finalArray.insideTheCircleGroup.size(); ++i) {

        std::cout << "Group " << i+1 << ": ";
        for(int &j : app.finalArray.insideTheCircleGroup[i]) {
            std::cout << j << " ";
        }

        std::cout << std::endl;
    }

    return true;
}