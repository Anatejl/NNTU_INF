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
    app.array = vector_fill(app.n);
    return true;
}

bool app_process(Application& app){
    vector_show(app.array);
    app.counter_positive = vector_count_positive(app.array);
    app.counter_negative = vector_count_negative(app.array);
    app.zero = vector_count_zeroes(app.array);
    return true;
}

bool app_output(Application& app){
    std::cout << "Positive: " << app.counter_positive << std::endl;
    std::cout << "Negative: " << app.counter_negative << std::endl;
    std::cout << "Zero: " << app.zero << std::endl;
    return true;
}