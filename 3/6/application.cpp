//
// Created by Anatejl on 27.09.2024.
//

#include "application.h"

int app_run(const Application& app){

    app_begin((Application &) app);
    app_process((Application&) app);
    app_end((Application&) app);

    return 0;
}

bool app_begin(Application &app){

    std::cout << "What's n?" << std::endl;
    std::cin >> app.n;

    for (int i = 0; i < app.n; ++i){

        app.array.push_back(i+1);

    }

    return true;
}

bool app_process(Application &app){

    std::cout << "CUM";

    return true;
}