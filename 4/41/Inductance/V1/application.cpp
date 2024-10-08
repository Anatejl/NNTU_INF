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
        std::vector<double> finalColumn;

        app.finalArray.row.push_back(finalColumn);
        for (int j = 0; j < app.initialArray.row[i].size(); ++j) {
            tempIterativeCircleR = sqrt(
                pow(app.initialArray.row[i][j].first - app.circleCenter.first, 2) +
                pow(app.initialArray.row[i][j].second - app.circleCenter.second, 2));
            app.finalArray.row[i].push_back(tempIterativeCircleR);
        }
    }
    return true;
}

bool appProcessFinalResult(Application &app) {
    int tempStreakCheck;
    for (int i = 0; i < app.finalArray.row.size(); ++i) {
        tempStreakCheck = 0;
        for (int j = 0; j < app.finalArray.row[i].size(); ++j) {
            if (app.finalArray.row[i][j] <= app.circleR) {
                ++tempStreakCheck;
            }
        }
        if (tempStreakCheck == app.constK) {
            app.finalArray.insideTheCircle.push_back(true);
        } else {
            app.finalArray.insideTheCircle.push_back(false);
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
            std::cout << "Group " << i+1 << " - ";
            for (int j = 0; j < app.constK; ++j) {
                std::cout << "(" <<app.initialArray.row[i][j].first << "/"<< app.initialArray.row[i][j].second
                << ") ";
            }
            std::cout << "is inside the circle." << std::endl;
        }

    }

    return true;
}
