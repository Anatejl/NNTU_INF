//
// Created by Anatejl on 15.01.2024.
//
#include "application.h"
#include "vector.h"
#include <iostream>

static bool appGetN(Application& app);
static bool appGetR(Application& app);
static bool appGetXY(Application& app, unsigned n);
static bool appProcessVector(Application& app);
static void appOutputResult(Application& app);

int appRun(Application& app){

    if ( !appGetN(app) ){
        std::cout << "Data input failure." << std::endl;
        return 1;
    }
    if ( !appGetR(app) ){
        std::cout << "Data input failure." << std::endl;
        return 1;
    }
    if ( !appGetXY(app, app.n) ){
        std::cout << "Data input failure." << std::endl;
        return 1;
    }
    appProcessVector(app);
    appOutputResult(app);

    return 0;
}

static bool appGetN(Application& app){

    std::cout << "Input n:";
    std::cin >> app.n;
    vectorResize(app.initial, app.n);
    vectorResize(app.final, app.n);

    return true;

}

static bool appGetR(Application& app){

    std::cout << "Input R:";
    std::cin >> app.R;

    return true;

}

static bool appGetXY(Application& app, unsigned n ){

    for (int i = 0; i < app.n; ++i){

        std::cout << "Input set " << i << " of " << n <<" (X Y) - " << i << ":" << std::endl;
        std::cin >> app.initial.coordX[i] >> app.initial.coordY[i];

    }

    return true;
}

static bool appProcessVector(Application& app){

    app.final = vectorProcess(app.initial, app.final, app.R, app.n);

    return true;
}

static void appOutputResult(Application& app){

    unsigned SOF = vectorGetSizeOfFinal(app.final);

    for (int i = 0; i < SOF ; ++i) {

        std::cout << "{" << app.final.coordX[i] << ", " << app.final.coordY[i] << "}; " << std::endl;

    }
}