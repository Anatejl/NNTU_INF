//
// Created by anatejl on 8/21/24.
//

#include "application.h"

int app_run(Application& app) {

    app_get_n(app);
    app_get_array(app);
    app_process_array(app);
    app_output(app);

    return 0;
}

bool app_get_n(Application &app) {

    std::cout << "Input N number to generage upon: " << std::endl;
    std::cin >> app.n;
    std::cout << app.n << std::endl;

    return true;
}


bool app_get_array(Application &app) {

    for(int i = 0; i < app.n; ++i) {
        app.initial_array.push_back(i*2);
    }

    std::cout << "Generated array is: " << std::endl;
    for(int i = 0; i < app.initial_array.size(); ++i) {
        std::cout << app.initial_array[i] << " ";
    }
    std::cout << std::endl;
    return true;
}

bool app_process_array(Application &app) {
    // copy an array
    app.processed_array = app.initial_array;

    for (int i = 0; i < app.processed_array.size(); ++i) {

        if (i % 2 == 0 && i != 0) {

            //odd - 1, even - 2

            int buffer_odd = app.processed_array[i-1];
            int buffer_even = app.processed_array[i];

            app.processed_array[i] = buffer_odd;
            app.processed_array[i-1] = buffer_even;
        }
    }

    return true;
}

bool app_output(Application &app) {
    std::cout << std::endl << "Processed array is: " << std::endl;
    //display it
    for (int i = 0; i < app.processed_array.size(); ++i) {
        std::cout << app.processed_array[i] << " ";
    }
    std::cout << std::endl;
    return true;
}
