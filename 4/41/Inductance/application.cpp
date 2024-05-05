//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include "vector.h"
#include <vector>
#include <iostream>
#include  <stdlib.h>
#include <math.h>

int appRun(Application &app) {

    if (!appGetCircleDimensions(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

//    if (!appGetConstantD(app)) {
//        std::cout << "DATA INPUT FAILURE." << std::endl;
//        return 1;
//    }

    if (!appGetConstantK(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appInitializeData(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appProcessDataIntoFinalResult(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appGetOutputToUser(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    return 0;
}

bool appGetCircleDimensions(Application &app) {

    std::cout << "Input CENTER 'X Y' coordinate of circle " << std::endl;
    std::cin >> app.circleCenter.first >> app.circleCenter.second;

    std::cout << "Input EDGE 'X Y' coordinate of circle " << std::endl;
    std::cin >> app.circleXY.first >> app.circleXY.second;

    app.circleR = sqrt(
            pow(app.circleXY.first - app.circleCenter.first, 2) +
            pow(app.circleXY.second - app.circleCenter.second, 2));

    return true;
}

//bool appGetConstantD(Application &app) {
//    std::cout << "Input a R constant:" << std::endl;
//    app.constR = 2;
//    std::cout << app.constR << std::endl;
//
//    return true;
//}

bool appGetConstantK(Application &app) {
    std::cout << "Input a K constant:" << std::endl;
    app.constK = 3;
    std::cout << app.constK << std::endl;
    return true;
}

bool appInitializeData(Application &app) {
    app.initialArray = vectorInitialArrayInitialize(app.initialArray, app.constK);
    std::cout << "Input array has been successfully processed." << std::endl;

    return true;
}

bool appProcessDataIntoFinalResult(Application &app) {

    for(int i = 0; i < app.initialArray.row.size(); ++i){

        app.finalArray.row;

    }


    return true;
}

bool appGetOutputToUser(Application &app) {



    return true;
}
