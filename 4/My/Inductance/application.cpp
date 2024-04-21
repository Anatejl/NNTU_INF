//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include "vector.h"
#include <iostream>

static bool appInitializeData(Application& app);
static bool appGetConstantD(Application& app);
static bool appProcessDataIntoFinalResult(Application& app);
static bool appGetOutputToUser(Application& app);


int appRun(Application& app){

    if(!appInitializeData(app)){

        std::cout << "Data input failure." << std::endl;
        return 1;

    }

    std::cin.get();

    if(!appGetConstantD(app)){

        std::cout << "Data input failure." << std::endl;
        return 1;

    }

    appProcessDataIntoFinalResult(app);
    appGetOutputToUser(app);


    return 0;

}

static bool appInitializeData(Application& app){

    app.valueArray = vectorInitialize(app.valueArray);

    return true;

}

static bool appGetConstantD(Application& app){

    std::cout << "Input array has been successfully processed." << std::endl << "Input a D constant to compare:" << std:: endl;
    std::cin.get();
    std::cin >> app.constD;

    std::cout << app.constD << std::endl;

    return true;
}

static bool appProcessDataIntoFinalResult(Application& app){

    std::cout << "ZDES' SOME PROCESSING OCCURS" << std::endl;

    return true;
}

static bool appGetOutputToUser(Application& app){

    std::cout << "Main vector has " << vectorGetSize(app.valueArray) << " entries." << std::endl;
    std::cout << "Values as follows:" << std::endl;

    for (int i = 0; i < vectorGetSize(app.valueArray); i++) {

        std::cout << app.valueArray.value[i] << " ";

    }

    return true;

}