//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include <iostream>
#include <cmath>

bool operation(Callback callback, void *ADT){
    return (*callback)(ADT);
}

bool appGetConstantK(void *object) {

    Application &app = *(Application*) object;

    std::cout << "Input a K constant:" << std::endl;
    std::cin >> app.const_k;
    std::cout << app.const_k << std::endl;
    return true;
}

bool appGetCircleDimensions(void *object) {

    Application &app = *(Application*) object;

    std::cout << "Input CENTER 'X Y' coordinate of circle: " << std::endl;
    std::cin >> app.circle_center.first >> app.circle_center.second;
    std::cout << app.circle_center.first <<"/"<< app.circle_center.second << std::endl;

    std::cout << "Input EDGE 'X Y' coordinate of circle: " << std::endl;
    std::cin >> app.circle_edge.first >> app.circle_edge.second;
    std::cout << app.circle_edge.first <<"/"<< app.circle_edge.second << std::endl;

    app.circle_r = sqrt(
            pow(app.circle_edge.first - app.circle_center.first, 2) +
            pow(app.circle_edge.second - app.circle_center.second, 2));

    return true;
}

bool appInitializeData(void *object) {

    Application &app = *(Application*) object;

    std::cin >> app.init_xy.first >> app.init_xy.second;

    return true;
}

bool appProcessCurrentXYRadius(void *object) {

    Application &app = *(Application*) object;

    app.temp_group.push_back(std::make_pair(false,std::make_pair(sqrt(
                                                    pow(app.init_xy.first - app.circle_center.first, 2) +
                                                    pow(app.init_xy.second - app.circle_center.second, 2)),
                                            std::make_pair(app.init_xy.first, app.init_xy.second))));

    return true;
}

bool appProcessResult(void *object) {

    Application &app = *(Application*) object;

    int counter = 0;

    for (int j = 0; j < app.temp_group.size(); ++j) {
        if (app.temp_group[j].second.first < app.circle_r) {
            app.temp_group[j].first = true;
            ++counter;
        }
    }

    if (counter == app.const_k){
        return true;
    }

    return false;
}

bool appGetOutputToUser(void *object) {

    Application &app = *(Application*) object;

    std::cout << app.iteration << " Iteration - group is" << "inside the circle, their values are:" << std::endl;

    for (int i = 0; i < app.const_k; ++i) {

        std::cout << "(" << app.temp_group[i].second.second.first << "/" << app.temp_group[i].second.second.second << ") ";

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

    while (!std::cin.eof()) {
        int i;
        while (i <= app.const_k) {
            if (i <= app.const_k - 1) {
                if (!operation(&appInitializeData, &app)) {
                    std::cout << "DATA INPUT FAILURE." << std::endl;
                    return 1;
                }

                if (!operation(&appProcessCurrentXYRadius, &app)) {
                    std::cout << "DATA INPUT FAILURE." << std::endl;
                    return 1;
                }
            }
            else {
                if (operation(&appProcessResult, &app)) {
                    operation(&appGetOutputToUser, &app);
                }
                app.temp_group.clear();
            }
            ++i;
        }
        ++app.iteration;
        i = 0;
    }
    return 0;
}