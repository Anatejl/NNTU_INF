//
// Created by Anatejl on 27.09.2024.
//

#include "application.h"
#include "vector.h"

int app_run(Application& app){
    app_begin(app);
    app_process(app);
    app_end(app);
    return 0;
}

bool app_begin(Application& app){
    std::cout << "What's n?" << std::endl;
    std::cin >> app.n;
    std::cout << "DEBUG:" << app.n << std::endl;
    for (int i = 0; i < app.n; ++i){
        app.array.push_back(i+1);
    }
    std::cout << "Initial vector is: ";
    vector_display(app.array);
    return true;
}

bool app_process(Application& app){
    for (int i = 1; i < app.array.size(); ++i){
        app.array.erase(app.array.begin()+i);
    }
    return true;
}

bool app_end(Application& app){
    std::cout << "Processed vector is: ";
    vector_display(app.array);
    //vector_check(app.array);
    return true;
}