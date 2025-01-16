#include "application.h"

bool app_process(Application& app) {

    vector_compress(app.array);

    return true; 
}