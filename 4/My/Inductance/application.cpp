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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Assemble seqTracker vector, to get all sequence breaking indexes.
    for (int i = 0; i <= app.valueArray.counter - 1; i++) {

        if (i == 0) {

            app.seqTracker.value.push_back(app.indexArray.value[i]);

        }

        //If index, by value, breaks ascending sequence, it's index added to seqTracker vector.
        if (app.valueArray.value[i] > app.valueArray.value[i + 1]) {

            //app.seqTracker.value.push_back(app.valueArray.value[app.indexArray.value[i]-1]);
            app.seqTracker.value.push_back(app.indexArray.value[i]);

            //if (i == 0 && app.seqTracker.value[i] == app.seqTracker.value[i + 1]) {
//
            //    //app.seqTracker.value.pop_back();
//
            //}

            app.seqTracker.value.push_back(app.indexArray.value[i] + 1);

        }



        //Push last item's index.
        if (i == app.valueArray.counter - 1) {

            app.seqTracker.value.push_back(app.indexArray.value[i]);

        }

        //If only one ascending seq -> insert 0 to the beginning of seqTracker
        //if (i == app.valueArray.counter-1 && app.seqTracker.value.size() == 1){
//
        //    app.seqTracker.value.insert(app.seqTracker.value.begin(), 0);
//
        //}

    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Narrow indexes by checking them against D constant, provided above.
    for (int i = 0; i < app.seqTracker.value.size() - 1; i++) {

        if (app.valueArray.value[app.seqTracker.value[i] - 1] - app.valueArray.value[app.seqTracker.value[i]] <
            app.constD) {

            app.seqTracker.value[i] = 0;

        }


        //if (std::accumulate(app.seqTracker.value.begin(), app.seqTracker.value.end(), 0) == 0){ // NOLINT(*-fold-init-type)
//
        //    app.seqTracker.value.clear();
//
        //}
    }

    //Get indexi posledotel'nosti
    //for (int i = 0; i < vectorGetSize(app.seqTracker)-1; ++i) {
//
    //    if ((app.seqTracker.value[i+1] - app.seqTracker.value[i]) > app.finalConsequenceStreak) {
//
    //        app.finalConsequenceStreak = app.seqTracker.value[i+1] - app.seqTracker.value[i];
    //        app.finalLeftByIndex = app.seqTracker.value[i];
//
    //        if(vectorGetSize(app.seqTracker) == 1){
    //            app.finalRightByIndex = app.seqTracker.value[i];
    //        }
    //        else {
    //            app.finalRightByIndex = app.seqTracker.value[i + 1];
    //        }
    //    }
//
    //}

    //Get values podhodyashih indexov
    //for (int i = 1; i < vectorGetSize(app.seqTracker); ++i) {
//
    //    if ((app.seqTracker.value[i] - app.seqTracker.value[i - 1]) == app.finalConsequenceStreak) {
//
    //        app.finalLeftByValue = app.valueArray.value[app.finalLeftByIndex];
//
    //        if (app.finalRightByIndex == app.valueArray.counter - 1) {
//
    //            app.finalRightByValue = app.valueArray.value[app.finalRightByIndex];
//
    //        } else {
//
    //            app.finalRightByValue = app.valueArray.value[app.finalRightByIndex - 1];
//
    //        }
//
    //        break;
    //    }
//
    //}

    return true;
}

static bool appGetOutputToUser(Application &app) {

    std::cout << "Provided vector consists of " << vectorGetSize(app.valueArray) << " entries." << std::endl;
    std::cout << "Values as follows:" << std::endl;

    for (int i = 0; i < vectorGetSize(app.valueArray); i++) {

        std::cout << app.valueArray.value[i] << " ";

    }

    std::cout << std::endl << "Consequence broke " << (vectorGetSize(app.seqTracker)) << " times." << std::endl;
    std::cout << "Longest streak of ascending values is: " << app.finalConsequenceStreak << std::endl;
    std::cout << "Left index of matched sequence: " << app.finalLeftByIndex << " Value is: " //<< app.finalLeftByValue
              << std::endl;
    std::cout << "Right index of matched sequence: " << app.finalRightByIndex
              << " Value is: " //<< app.finalRightByValue
              << std::endl;

    return true;

}