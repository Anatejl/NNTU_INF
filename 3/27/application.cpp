#include "application.h"

int app_run(Application& app){
    app_start(app);
    if (app_process(app)){
        app_end(app);
        return 0;
    }
    else{
        std::cout << "An error has occured." << std::endl;
        return 1;
    }
}

bool app_start(Application& app){
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
        cartesian_add(temp_x, temp_y, app.array);
    }
    return true;
}

bool app_process(Application& app){
    std::cout << "PROCESSING" << std::endl;
    if (app.array.size() > 1){
        cartesian_find(app.array, app.distanced);
        return true;
    }
    std::cout << "Insufficient data. ABORTING..." << std::endl;   
    return false;
}

bool app_end(Application& app){

    std::cout << "ENDING" << std::endl;

    std::cout << "Entire sequence is:\n" << std::endl;
    cartesian_show(app.array);

    std::cout << "The farthest pair of points are:\n";

    for (int i = 0; i < app.array.size(); ++i) {
        if (app.array[i] == app.distanced.first) {
            std::cout << "First point: is " << i+1 << " - ["<< app.distanced.first.first << ", " << app.distanced.first.second << "]" <<  std::endl;
        } 
        if (app.array[i] == app.distanced.second) {
            std::cout << "Second point is: " << i+1 << " - ["<< app.distanced.second.first << ", " << app.distanced.second.second << "]" <<  std::endl;;
        }
    }
    return true;
}