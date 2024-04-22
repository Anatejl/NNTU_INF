//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include "vector.h"
#include <iostream>
#include <vector>

static bool appInitializeData(Application& app);
static bool appGetConstantD(Application& app);
static bool appProcessDataIntoFinalResult(Application& app);
static bool appGetOutputToUser(Application& app);


Vector vectorCreateTempVector(int i);

int appRun(Application& app){

    if(!appInitializeData(app)){

        std::cout << "Data input failure." << std::endl;
        return 1;

    }

    if(!appGetConstantD(app)){

        std::cout << "Data input failure." << std::endl;
        return 1;

    }

    appProcessDataIntoFinalResult(app);

    appGetOutputToUser(app);

    return 0;

}

static bool appInitializeData(Application& app){

    app.valueArray = vectorValueArrayInitialize(app.valueArray);
    app.indexArray = vectorIndexArrayInitialize(app.valueArray);

    return true;

}

static bool appGetConstantD(Application& app){

    std::cout << "Input array has been successfully processed." << std::endl << "Input a D constant to compare:" << std:: endl;
    //std::cin.get();
    //std::cin >> app.constD;

    app.constD = 5;
    std::cout << app.constD << std::endl;

    return true;
}

static bool appProcessDataIntoFinalResult(Application& app){

    // At this point you have:
    // app.valueArray.value[i] - vector of values, 14 total.
    // app.valueArray.counter - Counter of items in an array.
    // app.indexArray.value[i] - vector of idexes, 14 total.
    // app.constD - A D constant from task.
    // app.finalMinByValue
    // app.finalMaxByValue
    // app.finalMinByIndex
    // app.finalMaxByIndex

    std::cout << "ZDES' SOME PROCESSING OCCURS" << std::endl;

    unsigned tempMinByValue = 0;
    unsigned tempMaxByValue = -1;
    unsigned tempMinByIndex = 0;
    unsigned tempMaxByIndex = -1;


    for(int i = 0; i < app.valueArray.counter; i++){

        //check for index
        if(app.indexArray.value[i] == 0){

            tempMinByIndex = i;
            tempMinByValue = app.valueArray.value[i];

        }
        else if(app.indexArray.value[i] != 0){

            //check for greater of subsequent then previous
            if(app.valueArray.value[i] > app.valueArray.value[i-1] && app.valueArray.value[i+1] < app.valueArray.value[i]){

                //WE'RE IN ASCENDING LIST

                tempMaxByIndex = app.indexArray.value[i];
                tempMaxByValue = app.valueArray.value[i];

            }
            if(app.valueArray.value[i] > app.valueArray.value[i+1]){

                //ASCENDING LIST BROKE

                tempMinByIndex = app.indexArray.value[i];
                tempMinByValue = app.valueArray.value[i];

                //seqTracker is the array of sequence brokerers, value which broke ascending list.
                app.valueArray.seqTracker.push_back(i+1);

            }

        }
    }

    return true;
}

static bool appGetOutputToUser(Application& app){

   //std::cout << "Main vector has " << vectorGetSize(app.valueArray) << " entries." << std::endl;
   //std::cout << "Values as follows:" << std::endl;

   //for (int i = 0; i < vectorGetSize(app.valueArray); i++) {

   //    std::cout << app.valueArray.value[i] << " ";

   //}

   std::cout << "Consequence broke " << (app.valueArray.seqTracker.size()/2) << " times.";

    return true;

}