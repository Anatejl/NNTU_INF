#include "application.h"

int main(){
    std::cout << "Welcome to Even/Odd/Zero evaluation program." << std::endl;
    Application app;
    int ret = app_launch(app);
    return ret;
}