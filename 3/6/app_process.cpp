#include "application.h"

bool app_process(Application& app) {
    for (int i = 1; i < vector_size(app.array); ++i) { 
        app.array.erase(app.array.begin() + i); 
    }
    return true; 
}