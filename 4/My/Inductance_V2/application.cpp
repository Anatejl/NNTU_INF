//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include "vector.h"
#include <iostream>

static bool appInitializeData(Application &app);

static bool appGetConstantD(Application &app);

static bool appProcessDataIntoFinalResult(Application &app);

static bool appGetOutputToUser(Application &app);

int appRun(Application &app) {

    if (!appInitializeData(app)) {

        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;

    }

    if (!appGetConstantD(app)) {

        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;

    }

    appProcessDataIntoFinalResult(app);

    if (!appGetOutputToUser(app)) {

        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;

    }
    return 0;

}

static bool appInitializeData(Application &app) {

    app.valueArray = vectorValueArrayInitialize(app.valueArray);
    app.indexArray = vectorIndexArrayInitialize(app.valueArray);
    std::cout << "Input array has been successfully processed." << std::endl;

    return true;

}

static bool appGetConstantD(Application &app) {

    std::cout << "Input a D constant to compare:" << std::endl;
    app.constD = 5;
    std::cout << app.constD << std::endl;

    return true;
}

static bool appProcessDataIntoFinalResult(Application &app) {

    unsigned tempConsequenceStreak = 0;

    for (int i = 0; i < app.valueArray.counter; ++i) {

        if (app.valueArray.value[i] > app.valueArray.value[i + 1]) {

            if ((app.valueArray.value[i] - app.valueArray.value[i - (tempConsequenceStreak - 1)]) > app.constD
                && tempConsequenceStreak > app.finalConsequenceStreak) {

                if (app.finalLeft == -1) {

                    app.finalLeft = app.indexArray.value[(i - tempConsequenceStreak)];

                }
                else{

                    app.finalLeft = app.indexArray.value[(i - tempConsequenceStreak) + 1];

                }
                app.finalRight = app.indexArray.value[i];
                app.finalConsequenceStreak = tempConsequenceStreak;
            }

            tempConsequenceStreak = 0;

        }

        if (app.valueArray.counter - 1 == i
            && (app.valueArray.value[i] - app.valueArray.value[i - (tempConsequenceStreak)]) > app.constD
            && tempConsequenceStreak > app.finalConsequenceStreak) {

            if (app.finalLeft == -1) {

                app.finalLeft = app.indexArray.value[(i - tempConsequenceStreak)];

            }
            else{

                app.finalLeft = app.indexArray.value[(i - tempConsequenceStreak) + 1];

            }
            app.finalRight = app.indexArray.value[i];

        }

        ++tempConsequenceStreak;
    }

    return true;
}

static bool appGetOutputToUser(Application &app) {

    //Demonstrate input data
    std::cout << "Provided vector consists of " << vectorGetSize(app.valueArray) << " entries." << std::endl;
    std::cout << "Values as follows:" << std::endl;

    for (int i = 0; i < vectorGetSize(app.valueArray); i++) {

        std::cout << app.valueArray.value[i] << " ";

    }

    //Output results
    if (!(app.finalLeft == (0|-1) && app.finalRight == (0|-1))) {

        std::cout << std::endl << app.finalLeft << " - Left Index" << std::endl;
        std::cout << app.finalRight << " - Right Index" << std::endl;

    } else {

        std::cout << std::endl << "No matches applicable." << std::endl;

        return false;
    }

    return true;
}