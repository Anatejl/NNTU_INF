//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include "vector.h"
#include <iostream>


int appRun(Application &app) {
    if (!appInitializeData(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appGetConstantD(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appProcessDataIntoFinalResult(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl << "No matches applicable." << std::endl;
        return 1;
    }

    if (!appGetOutputToUser(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }
    return 0;
}

bool appInitializeData(Application &app) {
    app.valueArray = vectorValueArrayInitialize(app.valueArray);
    std::cout << "Input array has been successfully processed." << std::endl;

    return true;
}

bool appGetConstantD(Application &app) {
    std::cout << "Input a D constant to compare:" << std::endl;
    app.constD = 0;
    std::cout << app.constD << std::endl;

    return true;
}

bool appProcessDataIntoFinalResult(Application &app) {
    int tempConsequenceStreak = 0;

    for (int i = 0; i < vectorGetSize(app.valueArray); ++i) {
        if ( (app.valueArray.value[i] > app.valueArray.value[i + 1]) ||
            (i==vectorGetSize(app.valueArray)-1 && app.valueArray.value[i] < 0)
            )  {

            if (tempConsequenceStreak > app.finalConsequenceStreak &&
            (((app.valueArray.value[i] -app.valueArray.value[i - ((tempConsequenceStreak-1))]) > app.constD) ||
            (app.valueArray.value[i] -app.valueArray.value[i - tempConsequenceStreak]) > app.constD))
            {
                if((app.finalLeft == INT_MAX && app.finalRight == INT_MAX) &&
                   (i == tempConsequenceStreak || i == tempConsequenceStreak+1)){
                    app.finalLeft = i - tempConsequenceStreak;
                }
                else{
                    app.finalLeft = i - (tempConsequenceStreak-1);
                }
                app.finalRight = i;
                app.finalConsequenceStreak = tempConsequenceStreak;
            }

            tempConsequenceStreak = 0;
        }

        ++tempConsequenceStreak;
    }

    if (app.finalLeft == INT_MAX && app.finalRight == INT_MAX && vectorGetSize(app.valueArray) == 1) {
        app.finalLeft = 0;
        app.finalRight = 0;
    }
    if (app.finalLeft == INT_MAX && app.finalRight == INT_MAX) {
        return false;
    }

    return true;
}

bool appGetOutputToUser(Application &app) {

        std::cout << std::endl << app.finalLeft << " - Left Index" << std::endl;
        std::cout << app.finalRight << " - Right Index" << std::endl;

    return true;
}
