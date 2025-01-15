#include "application.h"

bool app_end(Application& app) {
    std::cout << "Processed vector is: ";
    vector_display(app.array); 
    return true; 
}