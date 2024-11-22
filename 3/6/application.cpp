#include "application.h"

int app_run(Application& app){
    app_begin(app);
    app_process(app);
    app_end(app);
    return 0;
}

bool app_begin(Application& app){
    std::cout << "What's n?" << std::endl;
    std::cin >> app.n;
    int temp_read_value;
    for (int i = 0; i < app.n; ++i){
        std::cout << "<" << i+1 << " of " << app.n << ">" << " item assigning:" << std::endl;
        std::cout << "Input a value:" << std::endl;
        std::cin >> temp_read_value;
        vector_push(app.array, temp_read_value);
    }
    std::cout << "Initial vector is: ";
    vector_display(app.array);
    return true;
}

bool app_process(Application& app){
    for (int i = 1; i < vector_size(app.array); ++i){
        vector_erase(app.array, i);
    }
    return true;
}

bool app_end(Application& app){
    std::cout << "Processed vector is: ";
    vector_display(app.array);
    return true;
}