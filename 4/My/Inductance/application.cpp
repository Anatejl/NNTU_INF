//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include "vector.h"
#include <iostream>
#include <vector>

static bool appInitializeData(Application &app);

static bool appGetConstantD(Application &app);

static bool appProcessDataIntoFinalResult(Application &app);

static bool appGetOutputToUser(Application &app);


Vector vectorCreateTempVector(int i);

int appRun(Application &app) {

    if (!appInitializeData(app)) {

        std::cout << "Data input failure." << std::endl;
        return 1;

    }

    if (!appGetConstantD(app)) {

        std::cout << "Data input failure." << std::endl;
        return 1;

    }

    appProcessDataIntoFinalResult(app);

    appGetOutputToUser(app);

    return 0;

}

static bool appInitializeData(Application &app) {

    app.valueArray = vectorValueArrayInitialize(app.valueArray);
    app.indexArray = vectorIndexArrayInitialize(app.valueArray);

    return true;

}

static bool appGetConstantD(Application &app) {

    std::cout << "Input array has been successfully processed." << std::endl << "Input a D constant to compare:"
              << std::endl;

    app.constD = 5;
    std::cout << app.constD << std::endl;

    return true;
}

static bool appProcessDataIntoFinalResult(Application &app) {

    for (int i = 0; i < app.valueArray.counter; i++) {


        if (app.indexArray.value[i] != 0) {

            if (app.valueArray.value[i] > app.valueArray.value[i + 1]) {

                //seqTracker is the array of sequence brokerers, value which broke ascending list.
                app.seqTracker.value.push_back(i + 1);

            }
        }

        if (i + 1 == app.valueArray.counter) {

            app.seqTracker.value.push_back(app.indexArray.value[i]);

        }
    }

    for (int i = 1; i < vectorGetSize(app.seqTracker); ++i) {

        if ((app.seqTracker.value[i] - app.seqTracker.value[i - 1]) > app.finalConsequenceStreak) {

            app.finalConsequenceStreak = app.seqTracker.value[i] - app.seqTracker.value[i - 1];
            app.finalLeftByIndex = app.seqTracker.value[i - 1];
            app.finalRightByIndex = app.seqTracker.value[i];

        }

    }

    for (int i = 1; i < vectorGetSize(app.seqTracker); ++i) {

        if ((app.seqTracker.value[i] - app.seqTracker.value[i - 1]) == app.finalConsequenceStreak) {

            app.finalLeftByValue = app.valueArray.value[app.finalLeftByIndex];

            if (app.finalRightByIndex == app.valueArray.counter - 1) {

                app.finalRightByValue = app.valueArray.value[app.finalRightByIndex];

            }
            else {

                app.finalRightByValue = app.valueArray.value[app.finalRightByIndex - 1];

            }
            break;
        }

    }

    return true;
}

static bool appGetOutputToUser(Application &app) {

    std::cout << "Provided vector consists of  " << vectorGetSize(app.valueArray) << " entries." << std::endl;
    std::cout << "Values as follows:" << std::endl;

    for (int i = 0; i < vectorGetSize(app.valueArray); i++) {

        std::cout << app.valueArray.value[i] << " ";

    }

    std::cout << std::endl << "Consequence broke " << (vectorGetSize(app.seqTracker)) << " times." << std::endl;

    std::cout << "Longest streak of ascending values is " << app.finalConsequenceStreak << std::endl;
    std::cout << "Left index of matched sequence: " << app.finalLeftByIndex << " Value is: " << app.finalLeftByValue << std::endl;
    std::cout << "Right index of matched sequence: " << app.finalRightByIndex << " Value is: " << app.finalRightByValue << std::endl;

    return true;

}