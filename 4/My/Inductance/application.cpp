//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include "vector.h"
#include <iostream>
#include <numeric>

static bool appInitializeData(Application &app);

static bool appGetConstantD(Application &app);

static bool appProcessDataIntoFinalResult(Application &app);

static bool appGetOutputToUser(Application &app);

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

    if (!appGetOutputToUser(app)) {

        std::cout << "Data input failure." << std::endl;
        return 1;

    }
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Assemble seqTracker vector, to get all sequence breaking indexes.
    for (int i = 0; i <= app.valueArray.counter - 1; i++) {

        //if (i == 0) {
//
        //    app.seqTracker.value.push_back(app.indexArray.value[i]);
//
        //}

        //If index, by value, breaks ascending sequence, it's index added to seqTracker vector.
        if (app.valueArray.value[i] > app.valueArray.value[i + 1]) {

            app.seqTracker.value.push_back(app.indexArray.value[i]);
            app.seqTracker.value.push_back(app.indexArray.value[i] + 1);

        }

        //Push last item's index.
        if (i == app.valueArray.counter - 1) {

            app.seqTracker.value.push_back(app.indexArray.value[i]);

        }

        if (i == app.valueArray.counter-1) {
            if (std::accumulate(app.seqTracker.value.begin(), app.seqTracker.value.end(), 0) == 0) {

                app.seqTracker.value.insert(app.seqTracker.value.begin(), 0);
                app.seqTracker.value.push_back(app.indexArray.value[app.indexArray.counter - 1]);

            }

            if (app.seqTracker.value.size() == 1) {

                app.seqTracker.value.insert(app.seqTracker.value.begin(), 0);

            }
        }
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Narrow indexes by checking them against D constant, provided above.
    for (int i = 0; i <= app.seqTracker.value.size() - 1; i += 2) {

        if (app.valueArray.value[app.seqTracker.value[i + 1]] - app.valueArray.value[app.seqTracker.value[i]] <
            app.constD) {

            app.seqTracker.value[i] = 0;
            app.seqTracker.value[i + 1] = 0;

        }

    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Get final indexes
    for (int i = 0; i < app.seqTracker.value.size(); i += 2) {

        if (app.seqTracker.value[i + 1] != 0) {

            if (app.seqTracker.value[i + 1] - app.seqTracker.value[i] > app.finalConsequenceStreak) {

                app.finalLeftByIndex = app.seqTracker.value[i];
                app.finalRightByIndex = app.seqTracker.value[i + 1];
                app.finalConsequenceStreak = app.seqTracker.value[i + 1] - app.seqTracker.value[i];

            }

        }

    }

    return true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static bool appGetOutputToUser(Application &app) {

    std::cout << "Provided vector consists of " << vectorGetSize(app.valueArray) << " entries." << std::endl;
    std::cout << "Values as follows:" << std::endl;

    for (int i = 0; i < vectorGetSize(app.valueArray); i++) {

        std::cout << app.valueArray.value[i] << " ";

    }

    if (app.finalConsequenceStreak != 0) {
        std::cout << std::endl << "Consequence broke " << (vectorGetSize(app.seqTracker) / 2) << " times." << std::endl;
        std::cout << "Longest streak of ascending values is: " << app.finalConsequenceStreak << std::endl;
        std::cout << "Left index of matched sequence: " << app.finalLeftByIndex << ", which value is: "
                  << app.valueArray.value[app.finalLeftByIndex] << std::endl;
        std::cout << "Right index of matched sequence: " << app.finalRightByIndex << ", which value is: "
                  << app.valueArray.value[app.finalRightByIndex] << std::endl;
    }
    else if (std::accumulate(app.seqTracker.value.begin(), app.seqTracker.value.end(), 0) == 0) {

        std::cout << std::endl << "INVALID DATA WERE INPUT, ABORT." << std::endl;

        return false;

    }
    return true;

}