#include "application.h"

bool app_run(Application& app){

    app_start(app);
    app_process(app);
    app_end(app);

    return true;
}

bool app_start(Application& app){

    int temp_x = 0, temp_y = 0;

    std::cout << "START START" << std::endl;

    std::cout << "Input a n number:" << std::endl;

    std::cin >> app.n;

        for (int i = 0; i < app.n; ++i){

        std::cout << "[" << i+1 << "/" << app.n << "]" << " set is being assigned:" << std::endl;
        
        std::cout << "Input a x:" << std::endl;
        std::cin >> temp_x;

        std::cout << "Input an y:" << std::endl;
        std::cin >> temp_y;

        cartesian_add(app.n, temp_x, temp_y, app.array);

    }

    return true;
}

bool app_process(Application& app){

    std::cout << "PROCESSING" << std::endl;

    cartesian_find(app.array, app.distanced);

    return true;
}

bool app_end(Application& app){

    std::cout << "ENDING" << std::endl;
    
    return true;
}