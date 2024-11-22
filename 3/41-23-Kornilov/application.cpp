#include "application.h"

int app_launch(Application &app){
    app_input(app);
    app_process(app);
    app_output(app);
    return 0;
}

bool app_input(Application& app){
    std::cout << "Input n: " << std::endl;
    std::cin >> app.n;
    // std::cout << "Input a0: " << std::endl;
    // std::cin >> app.a0;
    return true;
}

bool app_process(Application& app){
    app.array = vector_fill(app.n);
    vector_show(app.array);
    app.odd = vector_count_odd(app.array);
    app.even = vector_count_even(app.array);
    app.zero = vector_count_zeroes(app.array);
    return true;
}

bool app_output(Application& app){
    std::cout << "ODD: " << app.odd << std::endl;
    std::cout << "EVEN: " << app.even << std::endl;
    std::cout << "ZERO: " << app.zero << std::endl;
    return true;
}