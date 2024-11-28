#include "application.h"

int main(){
    std::cout << "Welcome to Positive/Negative/Zero evaluation program." << std::endl;
    Application app;
    int ret = app_launch(app);
    return ret;
}