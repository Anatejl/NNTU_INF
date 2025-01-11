#include "application.h"

int app_run(Application_mainline& app_main, Application_source& app_source){
    app_start(app_main, app_source);
    if (app_process(app_main, app_source)){
        app_end(app_main, app_source);
        return 0;
    }
    else{
        std::cout << "An error has occured." << std::endl;
        return 1;
    }
}

bool app_start(Application_mainline& app_main, Application_source& app_source){
    double temp_x = 0, temp_y = 0;
    int temp_n = 0;
    std::cout << "START START" << std::endl;
    std::cout << "Input a n number:" << std::endl;
    std::cin >> temp_n;
    for (int i = 0; i < temp_n; ++i){
        std::cout << "[" << i+1 << "/" << temp_n << "]" << " set is being assigned:" << std::endl;
        std::cout << "Input a x:" << std::endl;
        std::cin >> temp_x;
        std::cout << "Input an y:" << std::endl;
        std::cin >> temp_y;
        cartesian_add(temp_x, temp_y, app_source.array);
    }
    return true;
}

bool app_process(Application_mainline& app_main, Application_source& app_source){
    std::cout << "PROCESSING" << std::endl;
    if (app_source.array.size() > 1){
        cartesian_find(app_source.array, app_main.distanced);
        return true;
    }
    std::cout << "Insufficient data. ABORTING..." << std::endl;   
    return false;
}

bool app_end(Application_mainline& app_main, Application_source& app_source){

    std::cout << "ENDING" << std::endl;
    std::cout << "The farthest pair of points are:\n";

    for (int i = 0; i < app_source.array.size(); ++i) {
        if (app_source.array[i] == app_main.distanced.first) {
            std::cout << "First point: is " << i+1 << " - ["<< app_main.distanced.first.first << ", " << app_main.distanced.first.second << "]" <<  std::endl;
        } 
        if (app_source.array[i] == app_main.distanced.second) {
            std::cout << "Second point is: " << i+1 << " - ["<< app_main.distanced.second.first << ", " << app_main.distanced.second.second << "]" <<  std::endl;;
        }
    }
    return true;
}