#include "application.h"

int app_run(Application& app) {
    app_begin(app); 
    app_process(app); 
    app_end(app); 
    return 0; 
}