//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include <iostream>

bool operation(Callback callback, void *data) {
    return (*callback)(data);
}

bool appGetConstantD(void *app) {

    Application &tempApp = *(Application*)app;
    
    std::cout << "Input a R constant, to compare adjacent values:" << std::endl;
    std::cin >> tempApp.constR;
    std::cout << tempApp.constR << std::endl;

    return true;
}

bool appProcessResult(void *app) {

    Application &tempApp = *(Application*)app;

    auto temp_pair = vectorPairInitialize();

    if(temp_pair.first){

        if (tempApp.processIteratorCounter == 0){
            if (abs((temp_pair.second.first - temp_pair.second.second)) > tempApp.constR) {
                tempApp.finalValueArray.value.push_back(vectorMakePair(temp_pair.second.first, temp_pair.second.second));
            }
            tempApp.lastRight = temp_pair.second.second;
        }
        else{
            if (abs((tempApp.lastRight-temp_pair.second.first)) > tempApp.constR){
                tempApp.finalValueArray.value.push_back(vectorMakePair(tempApp.lastRight, temp_pair.second.first));
            }
            if (abs((temp_pair.second.first - temp_pair.second.second)) > tempApp.constR){
                tempApp.finalValueArray.value.push_back(vectorMakePair(temp_pair.second.first, temp_pair.second.second));
            }

            tempApp.lastRight = temp_pair.second.second;
        }

        ++tempApp.processIteratorCounter;
    }
    else{

        if (abs((tempApp.lastRight-temp_pair.second.first)) > tempApp.constR){
            tempApp.finalValueArray.value.push_back(vectorMakePair(tempApp.lastRight, temp_pair.second.first));
        }

    }

    return true;
}

bool appGetOutputToUser(void *app) {

    Application &tempApp = *(Application*)app;
    
    //Output results
    if (!vectorGetEmpty_pair(tempApp.finalValueArray)) {
        std::cout << std::endl << "Final values are (Index - Left element / Right element):" << std::endl;
        for (int i = 0; i < vectorGetSize_pair(tempApp.finalValueArray); ++i) {
            std::cout << "Index: " << i+1 << " - " << tempApp.finalValueArray.value[i].first <<
                    "/" << tempApp.finalValueArray.value[i].second << std::endl;
        }
    }

    else {
        std::cout << std::endl << "No matches are applicable." << std::endl;
        return false;
    }

    return true;
}

int appRun() {

    Application app;
    
    if (!operation(&appGetConstantD, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    while(!std::cin.eof()) {
        if (!operation(&appProcessResult, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
    }

    if (!operation(&appGetOutputToUser, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    return 0;
}