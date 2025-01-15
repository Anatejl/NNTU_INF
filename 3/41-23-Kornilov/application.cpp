#include "application.h"

int app_launch(Application &app, Source_data& source){
    app_input(app, source);
    app_process(app, source);
    app_output(app);
    return 0;
}

bool app_input(Application& app, Source_data& source){

    int temp_n = 0;

    std::cout << "Input n: " << std::endl;
    std::cin >> temp_n;
    source.array = vector_fill(temp_n);
    return true;
}

bool app_process(Application& app, Source_data& source){
    vector_show(source.array);
    app.counter_positive = vector_count_positive(source.array);
    app.counter_negative = vector_count_negative(source.array);
    app.counter_zero = vector_count_zeroes(source.array);
    return true;
}

bool app_output(Application& app){
    std::cout << "Positive: " << app.counter_positive << std::endl;
    std::cout << "Negative: " << app.counter_negative << std::endl;
    std::cout << "Zero: " << app.counter_zero << std::endl;
    return true;
}