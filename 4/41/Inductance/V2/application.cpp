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
    int tempIterativeCircleR;

    for (int i = 0; i < app.initialArray.row.size(); ++i) {
        tempIterativeCircleR = sqrt(
            pow(app.initialArray.row[i].first - app.circleCenter.first, 2) +
            pow(app.initialArray.row[i].second - app.circleCenter.second, 2));
        app.finalArray.row.push_back(tempIterativeCircleR);
    }
    return true;
}

bool appProcessFinalResult(Application &app) {

    std::vector<int>column;
    int tempSeqStreak = 0;
    std::vector<int> tempVector;

    for (int i = 0; i < app.finalArray.row.size(); ++i) {

        if (app.finalArray.row[i] <= app.circleR) {

            ++tempSeqStreak;

            if(tempSeqStreak >= app.constK) {
                if(tempVector.empty()) {
                    for(int j = 0; j < app.constK; ++j) {

                        tempVector.push_back(j);

                    }
                }
                tempVector.push_back(i);
            }
            else {
                tempVector.push_back(i);
            }

        }
        else if(tempSeqStreak < app.constK && app.finalArray.row[i] > app.circleR) {
            tempVector.clear();
        }
    }

    if (std::accumulate(app.finalArray.insideTheCircle.begin(),
                        app.finalArray.insideTheCircle.end(), 0) == 0) {
        return false;
    }
    return true;
}


bool appGetOutputToUser(Application &app) {

    for(int i = 0; i < app.finalArray.insideTheCircle.size(); ++i) {

        if(app.finalArray.insideTheCircle[i]) {
            std::cout << "Dot " << i+1 << " - ";
            std::cout << "(" <<app.initialArray.row[i].first << "/"<< app.initialArray.row[i].second << "; R - " << app.finalArray.row[i]
            << ") ";
            std::cout << "is inside the circle." << std::endl;
        }

    }

    return true;
}
