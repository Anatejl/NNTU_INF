#include "application.h"

bool app_begin(Application& app) {
    int n, temp_read_value; 
    std::cout << "What's n?" << std::endl; 
    std::cin >> n; 
    for (int i = 0; i < n; ++i) { 
        std::cout << "<" << i + 1 << " of " << n << "> item assigning:" << std::endl; 
        std::cout << "Input a value:" << std::endl; 
        std::cin >> temp_read_value; 
        vector_push(app.array, temp_read_value); 
    }
    std::cout << "Initial vector is: ";
    vector_display(app.array); 
    return true; 
}