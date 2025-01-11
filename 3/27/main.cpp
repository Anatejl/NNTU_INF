#include "application.h"
#include <iostream>

int main (){
    std::cout << "Cartesian dot finder!" << std::endl;
    Application_mainline app_main;
    Application_source app_source;
    int ret = app_run(app_main, app_source);
    return 0;
}