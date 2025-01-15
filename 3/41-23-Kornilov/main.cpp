#include "application.h"

int main(){

    std::cout << "Welcome to Positive/Negative/Zero evaluation program." << std::endl;
    Application app;
    Source_data source;
    int ret = app_launch(app, source);
    return ret;

}